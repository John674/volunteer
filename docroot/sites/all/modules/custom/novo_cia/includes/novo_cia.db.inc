<?php

/**
 * @file
 * Novo cia request to database.
 */

/**
 * Add search request to queue.
 */
function novo_cia_add_search_request_to_queue($nid, $uid) {
  db_update('novo_cia_checks')
    ->fields(array(
      'request_status' => 3,
      'updated' => REQUEST_TIME,
    ))
    ->condition('application_nid', $nid)
    ->condition('request_status', 0)
    ->condition('request_type', 0)
    ->execute();

  $id = db_insert('novo_cia_checks')->fields(array(
    'uid' => $uid,
    'application_nid' => $nid,
    'request_type' => 0,
    'request_status' => 0,
    'attempts_number' => 1,
    'created' => REQUEST_TIME,
  ))->execute();
  return $id;
}

/**
 * Add pull report request to queue.
 */
function novo_cia_add_pull_report_request_to_queue($nid, $uid, $search_request_id, $tracking_number) {
  db_update('novo_cia_checks')
    ->fields([
      'request_status' => 3,
      'updated' => REQUEST_TIME,
    ])
    ->condition('application_nid', $nid)
    ->condition('request_type', 1)
    ->condition('request_status', 0)
    ->execute();

  return db_insert('novo_cia_checks')
    ->fields(array(
      'uid' => $uid,
      'application_nid' => $nid,
      'request_type' => 1,
      'request_status' => 0,
      'tracking_number' => $tracking_number,
      'search_request_id' => $search_request_id,
      'request_date' => REQUEST_TIME,
      'attempts_number' => 1,
      'created' => REQUEST_TIME,
    ))->execute();
}

/**
 * Get all pending pull reports requests.
 */
function novo_cia_get_pending_pull_report_requests() {
  return db_select('novo_cia_checks', 'cc')->fields('cc', array('id'))
    ->condition('request_type', 1)
    ->condition('request_status', 0)
    ->execute()
    ->fetchAll();
}

/**
 * Get all completed pull reports requests.
 */
function novo_cia_get_completed_pull_report_requests() {
  return db_select('novo_cia_checks', 'cc')->fields('cc', array('id'))
    ->condition('request_type', 1)
    ->condition('request_status', 1)
    ->execute()
    ->fetchAll();
}

/**
 * Get all pending search requests.
 */
function novo_cia_get_pending_search_requests() {
  return db_select('novo_cia_checks', 'cc')
    ->fields('cc', array('id'))
    ->condition('request_type', 0)
    ->condition('request_status', 0)
    ->execute()
    ->fetchAll();
}

/**
 * Get last pending pull report request.
 */
function novo_cia_get_last_pending_pull_report_request($nid) {
  return db_select('novo_cia_checks', 'cc')
    ->fields('cc', array(
      'id',
      'application_nid',
      'uid',
      'tracking_number',
    ))
    ->condition('request_type', 1)
    ->condition('application_nid', $nid)
    ->condition('request_status', 0)
    ->orderBy('cc.created', 'DESC')
    ->range(0, 1)
    ->execute()
    ->fetchObject();
}

/**
 * Get request.
 */
function novo_cia_get_request($request_id) {
  return db_select('novo_cia_checks', 'cc')
    ->fields('cc')
    ->condition('id', $request_id)
    ->execute()
    ->fetchObject();
}

/**
 * Update request.
 */
function novo_cia_update_request($request_id, $data = array()) {
  $update_data = array(
    'updated' => REQUEST_TIME,
  );
  $update_data += $data;
  return db_update('novo_cia_checks')
    ->fields($update_data)
    ->condition('id', $request_id)
    ->execute();
}

/**
 * Get last success request.
 */
function novo_cia_get_last_success_request($nid) {
  return db_select('novo_cia_checks', 'cc')
    ->fields('cc')
    ->condition('request_status', array(0, 1, 4))
    ->condition('application_nid', $nid)
    ->orderBy('cc.id', 'DESC')
    ->range(0, 1)
    ->execute()
    ->fetchObject();
}

/**
 * Get completed pull request for one node.
 */
function novo_cia_get_completed_pull_request($nid) {
  return db_select('novo_cia_checks', 'cc')
    ->fields('cc', array(
      'id',
      'application_nid',
      'uid',
      'tracking_number',
    ))
    ->condition('request_type', 1)
    ->condition('application_nid', $nid)
    ->condition('request_status', 1)
    ->orderBy('cc.id', 'DESC')
    ->range(0, 1)
    ->execute()
    ->fetchObject();
}

/**
 * Get users by role.
 */
function novo_cia_get_user_by_role($role_name) {
  $role = user_role_load_by_name($role_name);
  $uids = db_select('users_roles', 'ur')
    ->fields('ur', array(
      'uid',
    ))
    ->condition('rid', $role->rid)
    ->execute()
    ->fetchCol();

  return user_load_multiple($uids);
}

/**
 * Get request attempts.
 */
function novo_cia_get_request_attempts($request_id) {
  $attempts = db_select('novo_cia_checks', 'cc')
    ->fields('cc', array('attempts_number'))
    ->condition('id', $request_id)
    ->execute()
    ->fetchField();
  if (empty($attempts)) {
    db_update('novo_cia_checks')
      ->fields([
        'attempts_number' => 1,
        'updated' => REQUEST_TIME,
      ])
      ->condition('id', $request_id)
      ->execute();
    return 1;
  }
  return $attempts;
}
