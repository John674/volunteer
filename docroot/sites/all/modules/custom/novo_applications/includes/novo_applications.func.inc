<?php

/**
 * @file
 * Applications functions.
 */

/**
 * Get status tid by name.
 */
function novo_applications_get_status_tid($term_name) {
  $term = taxonomy_get_term_by_name($term_name, NOVO_APPLICATION_STATUS_VOC_NAME);
  $term = array_values($term);
  $term = isset($term[0]) ? $term[0] : -1;
  return (isset($term->tid)) ? $term->tid : NULL;
}

/**
 * Get user application nid.
 */
function novo_applications_get_user_app($uid) {
  $query = db_select('users', 'u');
  $query->fields('u', array('uid'));
  $query->condition('uid', $uid);
  $query->leftJoin("field_data_field_app_user", "app_user", "app_user.field_app_user_value = u.uid");
  $query->addField('app_user', 'entity_id', 'nid');

  return $query->range(0, 1)->execute()->fetchObject();
}

/**
 * Prepare approve/ not approve block.
 */
function novo_application_prepare_approve_block($nid, $app_status, $app_completed) {
  if (!user_access("approve application") || !$app_completed) {
    return NULL;
  }
  $approve_btn = l('<i class="fa fa-check"></i> ' . t("Approve"), "novo-applications/update-status/" . $nid . "/1", array(
    "html" => TRUE,
    "attributes" => array(
      "class" => array(
        "btn",
        "btn-success",
        "novo-application-approve-btn"
      ),
    )
  ));
  $not_approve_btn = l('<i class="fa fa-times"></i> ' . t("Not Approve"), "novo-applications/update-status/" . $nid . "/0", array(
    "html" => TRUE,
    "attributes" => array(
      "class" => array(
        "btn",
        "btn-danger",
        "novo-application-approve-btn"
      ),
    )
  ));
  switch ($app_status) {
    case -1:
      $approve_block = $approve_btn;
      break;

    case 1:
      $approve_block = $not_approve_btn;
      break;

    default:
      $approve_block = $approve_btn . " " . $not_approve_btn;
  }

  return $approve_block;
}

/**
 * Change application status callback.
 */
function novo_application_update_status($node, $status = 0) {
  $lang = isset($node->language) ? $node->language : LANGUAGE_NONE;
  $node_completed = isset($node->field_completed[$lang][0]['value']) ? $node->field_completed[$lang][0]['value'] : FALSE;
  if ($node_completed) {
    $status_tid = novo_applications_get_status_tid(($status) ? NOVO_APPLICATION_STATUS_APPROVED_NAME : NOVO_APPLICATION_STATUS_NOT_APPROVED_NAME);
    if ($status_tid) {
      $node->field_app_status[$lang][0]['tid'] = $status_tid;
      node_save($node);
      drupal_set_message(t("Status has been changed"));
    }
    else {
      drupal_set_message(t("Can't change status for application"), "error");
    }
  }
  else {
    drupal_set_message(t("Can't change status for not completed application"), "error");
  }

  drupal_goto("node/" . $node->nid);
}

/**
 * Get status of application.
 */
function novo_application_get_status($app_completed, $app_status_tid) {
  $app_status_output = ($app_completed) ? t("Completed") : t("Started");
  $app_status = NULL;

  if ($app_status_tid && $app_completed) {
    $approved_term_tid = novo_applications_get_status_tid(NOVO_APPLICATION_STATUS_APPROVED_NAME);
    $not_approved_term_tid = novo_applications_get_status_tid(NOVO_APPLICATION_STATUS_NOT_APPROVED_NAME);

    if ($approved_term_tid && $approved_term_tid == $app_status_tid) {
      $app_status_output = t("Approved");
      $app_status = 1;
    }
    elseif ($not_approved_term_tid && $not_approved_term_tid == $app_status_tid) {
      $app_status_output = t("Not approved");
      $app_status = -1;
    }
  }
  return array($app_status_output, $app_status);
}

/**
 * Select active app status for views and dyn fields.
 */
function novo_applications_get_app_active_status_formula($on_date = NULL) {
  // @codingStandardsIgnoreStart
  // FROM REVISION
//  $formula = "IF ((SELECT ((UNIX_TIMESTAMP() - max(n_rev.timestamp)) / 60 / 60 / 24 / 30)
//    FROM {field_data_field_attendance_volunteer_list} AS av
//    INNER JOIN {node_revision} AS n_rev ON (n_rev.nid = av.entity_id AND n_rev.vid = av.revision_id)
//    WHERE av.field_attendance_volunteer_list_target_id = {node}.nid) <= 6, 'Current', IF ((SELECT ((UNIX_TIMESTAMP() - max(n_rev.timestamp)) / 60 / 60 / 24 / 30)
//    FROM {field_data_field_attendance_volunteer_list} AS av
//    INNER JOIN {node_revision} AS n_rev ON (n_rev.nid = av.entity_id AND n_rev.vid = av.revision_id)
//    WHERE av.field_attendance_volunteer_list_target_id = {node}.nid) <= 18, 'Lapsed', 'Inactive'))";
  // @codingStandardsIgnoreEnd

  novo_master_set_default_mysql_timezone();

  if (!$on_date) {
    $on_date = "UNIX_TIMESTAMP()";
  }

  $formula = "IF ((SELECT (($on_date - UNIX_TIMESTAMP(max(ad.field_attendance_date_value))) / 60 / 60 / 24 / 30)
    FROM {field_data_field_attendance_volunteer_list} AS av 
    INNER JOIN field_data_field_attendance_date AS ad ON ad.entity_id = av.entity_id
    WHERE av.field_attendance_volunteer_list_target_id = {node}.nid) <= 6, 'Current', 
      IF ((SELECT (($on_date - UNIX_TIMESTAMP(max(ad.field_attendance_date_value))) / 60 / 60 / 24 / 30)
      FROM {field_data_field_attendance_volunteer_list} AS av 
      INNER JOIN field_data_field_attendance_date AS ad ON ad.entity_id = av.entity_id
      WHERE av.field_attendance_volunteer_list_target_id = {node}.nid) <= 18, 'Lapsed', 'Inactive'))";

  return "(" . $formula . ")";
}

/**
 * Select active app status for views and dyn fields.
 */
function novo_applications_get_app_active_status_formula_where($on_date = NULL) {
  novo_master_set_default_mysql_timezone();

  if (!$on_date) {
    $on_date = "UNIX_TIMESTAMP()";
  }

  $formula = "SELECT (($on_date - UNIX_TIMESTAMP(max(ad.field_attendance_date_value))) / 60 / 60 / 24 / 30)
    FROM {field_data_field_attendance_volunteer_list} AS av 
    INNER JOIN field_data_field_attendance_date AS ad ON ad.entity_id = av.entity_id
    WHERE av.field_attendance_volunteer_list_target_id = {node}.nid";

  return "((" . $formula . ") >= 0 OR (" . $formula . ") IS NULL)";
}

/**
 * Select last date serving (max date) for views and dyn fields.
 */
function novo_applications_get_last_date_serving_formula() {
  novo_master_set_default_mysql_timezone();
  $formula = "SELECT UNIX_TIMESTAMP(MAX(ad.field_attendance_date_value))
    FROM {field_data_field_attendance_volunteer_list} AS av 
    INNER JOIN {field_data_field_attendance_date} AS ad ON ad.entity_id = av.entity_id
    WHERE av.field_attendance_volunteer_list_target_id = {node}.nid";
  return "(" . $formula . ")";
}

/**
 * Select first date serving (min date) for views and dyn fields.
 */
function novo_applications_get_first_date_serving_formula() {
  novo_master_set_default_mysql_timezone();
  $formula = "SELECT UNIX_TIMESTAMP(MIN(ad.field_attendance_date_value))
    FROM {field_data_field_attendance_volunteer_list} AS av 
    INNER JOIN {field_data_field_attendance_date} AS ad ON ad.entity_id = av.entity_id
    WHERE av.field_attendance_volunteer_list_target_id = {node}.nid";
  return "(" . $formula . ")";
}


/**
 * Implements hook_action_info().
 */
function novo_applications_set_expiration_date($nid, $date = NULL) {
  if (empty($nid)) {
    return NULL;
  }

  $node = node_load($nid);
  if (!empty($node)) {
    cache_clear_all("field:node:$nid", 'cache_field');
    $exp_period = variable_get('novo_master_exp_period', '+36 months');
    $expired_date = strtotime($exp_period, REQUEST_TIME);

    $node->field_expired_date[$node->language][0]['value'] = $expired_date;
    $info1 = field_info_field('field_expired_date');

    $node->field_expired_email_sent[$node->language][0]['value'] = 0;
    $info2 = field_info_field('field_expired_email_sent');

    $fields = [$info1['id'], $info2['id']];
    field_sql_storage_field_storage_write('node', $node, 'update', $fields);

    cache_clear_all("field:node:$node->nid", 'cache_field');
    return TRUE;
  }
  return FALSE;
}