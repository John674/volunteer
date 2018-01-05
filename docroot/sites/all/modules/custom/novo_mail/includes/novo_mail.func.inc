<?php

/**
 * @file
 * Mail functions.
 */

/**
 * Watchdog mail err.
 */
function novo_mail_err($key, $vars = []) {
  watchdog("novo_mail_err", "Can't send email: :key. <br> :params", [
    ":key" => $key,
    ":params" => var_export($vars, TRUE),
  ], WATCHDOG_ERROR);
}

/**
 * Base send mail.
 */
function novo_mail_send($nid, $key, $additional_params = []) {
  // Check if already not send.
  $exist = novo_mail_get_status_from_storage($key, $nid);
  if ($exist) {
    return;
  }

  $params = novo_mail_app_get_volunteer_params($nid);
  $result = NULL;
  if ($params) {
    $params = array_merge($params, $additional_params);
    if (isset($params['callback'])) {
      unset($params['callback']);
    }
    if (isset($params['callback_params'])) {
      unset($params['callback_params']);
    }
    $is_manager = novo_mail_check_is_manager_email($key);

    if ($is_manager) {
      $admin_emails = novo_mail_get_siteadmin_emails();
      foreach ($admin_emails as $uid => $email) {
        $result = drupal_mail('novo_mail', $key, $email, language_default(), $params);
      }
    }
    else {
      $email = $additional_params['email_to'] ?? $params['app_email'];
      $result = drupal_mail('novo_mail', $key, $email, language_default(), $params);
    }

    // Run callback function if exist.
    if ($result && isset($result['result']) && $result['result']) {
      if (isset($additional_params['callback']) && function_exists($additional_params['callback'])) {
        $params = $additional_params['callback_params'] ?? [];
        call_user_func_array($additional_params['callback'], $params);
      }
    }
  }

  if (!$params || !$result || isset($result['result']) && !$result['result']) {
    $params['nid'] = $nid;
    novo_mail_err($key, $params);
    return $result;
  }
  return $result;
}

/**
 * Add to mail queue.
 */
function novo_mail_add_to_queue($nid, $key, $additional_params = []) {
  $email_queue = DrupalQueue::get('novo_mail_queue');
  $item = [
    'nid' => $nid,
    'key' => $key,
    'additional_params' => $additional_params,
  ];
  $email_queue->createItem($item);
}

/**
 * Check is manager email.
 */
function novo_mail_check_is_manager_email($key) {
  $emails_conf = unserialize(NOVO_MAIL_EMAILS);
  foreach ($emails_conf as $item) {
    if ($item['key'] === $key && isset($item['is_manager']) && $item['is_manager']) {
      return TRUE;
    }
  }
  return FALSE;
}

/**
 * Get all not sent tasks.
 *
 * @return mixed
 *   Result.
 */
function novo_mail_app_get_all_expired_nids() {
  novo_master_set_default_mysql_timezone();
  return db_query("SELECT
  ed.entity_id AS nid
FROM field_data_field_expired_date AS ed
  LEFT JOIN novo_mail AS nm ON nm.nid = ed.entity_id

WHERE ed.field_expired_date_value <= UNIX_TIMESTAMP()
      AND nm.id IS NULL LIMIT 100")->fetchAll();
}

/**
 * Get nodes which was not completed X hours.
 */
function novo_mail_app_get_all_not_completed_nids($hours = 72, $mail_key = "novo_mail_app_not_completed_form_admin_72") {
  novo_master_set_default_mysql_timezone();
  return db_query("SELECT 
    comp.entity_id AS nid
FROM field_data_field_completed AS comp
  LEFT JOIN novo_mail AS nm ON nm.nid = comp.entity_id AND nm.mail_key = :mail_key
  LEFT JOIN node AS n ON n.nid = comp.entity_id
WHERE
  (n.created + (60 * 60 * :hours)) < UNIX_TIMESTAMP() AND
  comp.field_completed_value < 1 AND
  (nm.id IS NULL OR nm.mail_key <> :mail_key)  
  
  LIMIT 100", [":hours" => $hours, ":mail_key" => $mail_key])->fetchAll();
}

/**
 * Get siteadmin emails.
 */
function novo_mail_get_siteadmin_emails() {
  $role_siteadmin = user_role_load_by_name('Siteadmin');
  $role_reviewer = user_role_load_by_name('Reviewer');
  return db_query("SELECT u.uid, u.mail FROM users AS u
    LEFT JOIN users_roles AS ur ON ur.uid = u.uid
    WHERE ur.rid = :rid OR ur.rid = :rid2 AND u.status = 1", [
      ":rid" => $role_siteadmin->rid,
      ":rid2" => $role_reviewer->rid,
    ])->fetchAllKeyed();
}

/**
 * Get volunteer data for email.
 */
function novo_mail_app_get_volunteer_params($nid) {
  $result = db_query("SELECT
  fn.field_first_name_value AS app_first_name,
  ln.field_last_name_value AS app_last_name,
  em.field_email_email AS app_email
FROM field_data_field_first_name AS fn
  LEFT JOIN field_data_field_last_name AS ln ON ln.entity_id = fn.entity_id
  LEFT JOIN field_data_field_email AS em ON em.entity_id = fn.entity_id
WHERE fn.entity_id = :nid LIMIT 1", [":nid" => $nid])->fetchAll(PDO::FETCH_ASSOC);

  return $result[0] ?? NULL;
}

/**
 * Get mail status from storage.
 */
function novo_mail_get_status_from_storage($key, $nid = NULL, $uid = NULL) {
  $query = db_select("novo_mail", "nm");
  $query->fields("nm");
  $query->condition("mail_key", $key);

  if ($nid) {
    $query->condition("nid", $nid);
  }

  if ($uid) {
    $query->condition("uid", $uid);
  };

  return $query->execute()->fetchAll();
}

/**
 * Add mail status to storage.
 */
function novo_mail_add_status_to_storage($key, $nid = NULL, $uid = NULL) {
  $exist = novo_mail_get_status_from_storage($key, $nid, $uid);
  if (!$exist) {
    return db_insert('novo_mail')
      ->fields([
        'uid' => $uid,
        'nid' => $nid,
        'mail_key' => $key,
        'mail_status' => 1,
        'created' => REQUEST_TIME,
        'updated' => REQUEST_TIME,
      ])->execute();
  }
}

/**
 * Remove mail status from storage.
 */
function novo_mail_remove_status_from_storage($key, $nid = NULL, $uid = NULL) {
  if ($nid || $uid) {
    $query = db_delete('novo_mail');

    if ($nid) {
      $query->condition('nid', $nid);
    }

    if ($uid) {
      $query->condition('nid', $uid);
    }

    $query->condition('mail_key', $key);
    return $query->execute();
  }
  return FALSE;
}
