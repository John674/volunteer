<?php

/**
 * @file
 * Novo ref request database.
 */

/**
 * Add Task.
 *
 * @param int $uid
 *   User uid.
 * @param int $nid
 *   Node nid.
 * @param string $name
 *   Task name.
 * @param string $email
 *   User email.
 *
 * @return DatabaseStatementInterface|int
 *   Result.
 */
function novo_ref_request_task_add($uid, $nid, $volunteer_nid, $volunteer_name, $ref_name, $name, $email, $phone, $status = 0) {
  $exist = novo_ref_request_task_get_all_active($nid);
  if ($exist) {
    foreach ($exist as $key => $value) {
      db_update('novo_ref_tasks')
        ->fields(array(
          'status' => 4,
          'updated' => REQUEST_TIME,
        ))
        ->condition('id', $value->id)
        ->execute();
    }
  }
  return db_insert('novo_ref_tasks')
    ->fields(array(
      'uid' => $uid,
      'nid' => $nid,
      'volunteer_nid' => $volunteer_nid,
      'volunteer_name' => $volunteer_name,
      'ref_name' => $ref_name,
      'name' => $name,
      'email' => $email,
      'phone' => $phone,
      'status' => $status,
      'created' => REQUEST_TIME,
    ))->execute();
}

/**
 * Get last task.
 *
 * @param int $nid
 *   Node nid.
 *
 * @return mixed
 *   Result.
 */
function novo_ref_request_task_get_last($nid, $recreate = FALSE) {
  $result = db_query("SELECT * FROM {novo_ref_tasks} WHERE nid = :nid ORDER BY id DESC LIMIT 1", array(
    ":nid" => $nid
  ))->fetchObject();

  if (!$result && $recreate && function_exists("novo_ref_request_add_tasks_callback")) {
    $array_nid_status = array(
      'nid' => $nid,
      'status' => 0,
    );
    novo_ref_request_add_tasks_callback(array($array_nid_status));
    $result = db_query("SELECT * FROM {novo_ref_tasks} WHERE nid = :nid ORDER BY id DESC LIMIT 1", array(
      ":nid" => $nid
    ))->fetchObject();
  }

  return $result;

}

/**
 * Get all not cancelled tasks by nid.
 *
 * @param int $nid
 *   Node nid.
 *
 * @return mixed
 *   Result.
 */
function novo_ref_request_task_get_all_active($nid) {
  return db_query("SELECT * FROM {novo_ref_tasks} WHERE nid = :nid AND status <> 4", array(
    ":nid" => $nid
  ))->fetchAll();
}

/**
 * Get all not sent tasks.
 *
 * @return mixed
 *   Result.
 */
function novo_ref_request_task_get_all_not_sent() {
  return db_query("SELECT * FROM {novo_ref_tasks} WHERE status = 0")->fetchAll();
}

/**
 * Get all not sent tasks.
 *
 * @return mixed
 *   Result.
 */
function novo_ref_request_task_get_all_not_responded_expired() {
  return db_query("SELECT * FROM {novo_ref_tasks} WHERE status = 1 AND created < :exp_time", array(":exp_time" => REQUEST_TIME - NOVO_REF_REQUEST_EXPIRED_TIME))->fetchAll();
}

/**
 * Remove task from database.
 *
 * @param int $nid
 *   Node nid.
 *
 * @return mixed
 *   Result.
 */
function novo_ref_request_task_delete($nid) {
  return db_delete('novo_ref_tasks')
    ->condition('nid', $nid)
    ->execute();

}

/**
 * Update status for task.
 *
 * @param int $nid
 *   Node nid.
 *
 * @return mixed
 *   Result.
 */
function novo_ref_request_task_update_status($nid, $status = 4) {
  $exist = novo_ref_request_task_get_last($nid);
  if ($exist) {
    return db_update('novo_ref_tasks')
      ->fields(array(
        'status' => $status,
        'updated' => REQUEST_TIME,
      ))
      ->condition('id', $exist->id)
      ->execute();
  }
  else {
    watchdog("novo_ref_request_task", "UPDATE status: Task not found nid: :nid", array(
      ":nid" => $nid
    ), WATCHDOG_ERROR);
  }
  return NULL;
}

/**
 * Update status for task.
 *
 * @param int $id
 *   Task id.
 *
 * @return mixed
 *   Result.
 */
function novo_ref_request_task_update_status_by_id($id, $status = 4) {
  $result = db_update('novo_ref_tasks')
    ->fields(array(
      'status' => $status,
      'updated' => REQUEST_TIME,
    ))
    ->condition('id', $id)
    ->execute();
  if (!$result) {
    watchdog("novo_ref_request_task", "UPDATE status: Task not found id: :id", array(
      ":id" => $id
    ), WATCHDOG_ERROR);
  }

  return $result;
}

/**
 * Check if all 3 ref request were finished. (submitted by user).
 */
function novo_ref_request_check_all_refs_finished($app_nid) {
  $sql = "SELECT count(nrt.id) AS number_res FROM novo_ref_tasks AS nrt
  WHERE
    nrt.volunteer_nid = :app_nid AND
    nrt.status = 2 AND
    (
      (SELECT req_1.field_reference_request_1_target_id FROM field_data_field_reference_request_1 AS req_1 WHERE req_1.field_reference_request_1_target_id = nrt.nid) IS NOT NULL OR
      (SELECT req_2.field_reference_request_2_target_id FROM field_data_field_reference_request_2 AS req_2 WHERE req_2.field_reference_request_2_target_id = nrt.nid) IS NOT NULL OR
      (SELECT req_3.field_reference_request_standby_target_id FROM field_data_field_reference_request_standby AS req_3 WHERE req_3.field_reference_request_standby_target_id = nrt.nid) IS NOT NULL
    )
    HAVING number_res = 3";
  return db_query($sql, [
    ":app_nid" => $app_nid,
  ])->fetchField();
}
