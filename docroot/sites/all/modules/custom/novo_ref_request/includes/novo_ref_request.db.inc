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
function novo_ref_request_task_add($uid, $nid, $name, $email) {
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
      'name' => $name,
      'email' => $email,
      'status' => 0,
      'created' => REQUEST_TIME
    ))->execute();
}

/**
 * Get last task
 *
 * @param int $nid
 *   Node nid.
 *
 * @return mixed
 *   Result.
 */
function novo_ref_request_task_get_last($nid) {
  return db_query("SELECT * FROM {novo_ref_tasks} WHERE nid = :nid ORDER BY id DESC LIMIT 1", array(
    ":nid" => $nid
  ))->fetchObject();
}

/**
 * Get all not cancelled tasks by nid.
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
