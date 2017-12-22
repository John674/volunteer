<?php

/**
 * @file
 * Applications cron.
 */

define("NOVO_APPLICATION_EXP_EMAIL_CRON_PERIOD", 60 * 5);

/**
 * Implements hook_cron().
 */
function novo_applications_cron() {
  $cron_last = variable_get('novo_application_exp_email_cron_last');
  if (REQUEST_TIME - $cron_last > NOVO_APPLICATION_EXP_EMAIL_CRON_PERIOD) {
    $email_queue = DrupalQueue::get('novo_application_exp_email_queue');
    $data = novo_application_get_all_expired_nids();
    foreach ($data as $key => $item) {
      $email_queue->createItem((array) $item);
    }

    variable_set('novo_application_exp_email_cron_last', REQUEST_TIME);
  }
}

/**
 * Implements hook_cron_queue_info().
 */
function novo_applications_cron_queue_info() {
  $queue['novo_application_exp_email_queue'] = [
    'worker callback' => 'novo_application_exp_email_queue_worker',
    'time' => 60,
  ];
  return $queue;
}

/**
 * Expired email queue worker.
 */
function novo_application_exp_email_queue_worker($data) {
  // Send email.
  $link = url("node/" . $data['nid'], array("absolute" => TRUE));
  $admin_emails = novo_application_get_siteadmin_emails();

  $result = NULL;
  foreach ($admin_emails as $uid => $email) {
    $params = [
      'link' => $link,
      'app_first_name' => $data['app_first_name'],
      'app_last_name' => $data['app_last_name']
    ];

    $result = drupal_mail('novo_applications', 'exp_email_admin', $email, language_default(), $params);
  }

  // Set status email has been sent.
  if ($result && isset($result['result']) && $result['result']) {
    novo_application_update_expired_email_sent($data['nid'], 1);
  }
  else {
    watchdog("novo_application_exp_email", "Can't send email for node.nid: :nid", array(
      ":nid" => $data['nid']
    ), WATCHDOG_ERROR);
  }

}

/**
 * Get all not sent tasks.
 *
 * @return mixed
 *   Result.
 */
function novo_application_get_all_expired_nids() {
  novo_master_set_default_mysql_timezone();
  return db_query("SELECT
  ed.entity_id AS nid,
  fn.field_first_name_value AS app_first_name,
  ln.field_last_name_value AS app_last_name
FROM field_data_field_expired_date AS ed
  LEFT JOIN field_data_field_expired_email_sent AS es ON es.entity_id = ed.entity_id
  LEFT JOIN field_data_field_first_name AS fn ON fn.entity_id = ed.entity_id
  LEFT JOIN field_data_field_last_name AS ln ON ln.entity_id = ed.entity_id

WHERE ed.field_expired_date_value <= UNIX_TIMESTAMP()
      AND es.field_expired_email_sent_value < 2 LIMIT 100")->fetchAll();
}

/**
 * Get siteadmin emails.
 */
function novo_application_get_siteadmin_emails() {
  $role = user_role_load_by_name('Siteadmin');
  return db_query("SELECT u.uid, u.mail FROM users AS u
    LEFT JOIN users_roles AS ur ON ur.uid = u.uid
    WHERE ur.rid = :rid", array(":rid" => $role->rid))->fetchAllKeyed();
}

/**
 * Update status for application exp email send falue.
 */
function novo_application_update_expired_email_sent($nid, $value = 0) {
  $result = db_update('field_data_field_expired_email_sent')
    ->fields(array(
      'field_expired_email_sent_value' => $value
    ))
    ->condition('entity_id', $nid)
    ->execute();
  if (!$result) {
    watchdog("novo_application_exp_email", "UPDATE status: NODE not found nid: :nid", array(
      ":nid" => $nid
    ), WATCHDOG_ERROR);
  }

  return $result;
}
