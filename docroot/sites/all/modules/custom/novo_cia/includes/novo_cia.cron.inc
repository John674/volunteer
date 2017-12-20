<?php

/**
 * @file
 * Novo cia cron tasks.
 */

/**
 * Send search request to CIA.
 */
function novo_cia_search_queue_worker($data) {
  $result = novo_cia_send_search_request($data['id']);
  if (empty($result)) {
    watchdog("novo_cia", "Search request :id have error", array(
      ":id" => $data['id'],
    ), WATCHDOG_ERROR);
  }
}

/**
 * Send pull report request to CIA.
 */
function novo_cia_pull_report_queue_worker($data) {
  $result = novo_cia_send_pull_report_request($data['id']);
  if (!empty($result) && isset($result->report_status) && !empty($result->report_status)) {
    novo_cia_add_send_mail_reviewer_to_queue($result->id);
  }
  if (empty($result)) {
    watchdog("novo_cia", "Pull report request :id have error", array(
      ":id" => $data['id'],
    ), WATCHDOG_ERROR);
  }
}

/**
 * Send email to reviewer with answer from CIA.
 */
function novo_cia_send_email_reviewer_queue_worker($data) {
  $result = novo_cia_send_email_to_reviewer($data['uid'], $data['request_id']);
  if (empty($result)) {
    watchdog("novo_cia", "Can't send email :uid", array(
      ":uid" => $data['uid'],
    ), WATCHDOG_ERROR);
  }
}

/**
 * Worker for check expired requests.
 */
function novo_cia_check_expired_date_queue_worker($data) {
  $result = novo_cia_is_expired_request($data['id']);
  if (empty($result)) {
    watchdog("novo_cia", "Can't check expiration date :id", array(
      ":id" => $data['id'],
    ), WATCHDOG_ERROR);
  }
}

/**
 * Add sending mails to reviewers to cron queue.
 */
function novo_cia_add_send_mail_reviewer_to_queue($request_id) {
  $reviewers = novo_cia_get_user_by_role('Reviewer');
  $send_email_reviewer_queue = DrupalQueue::get('novo_cia_send_email_reviewer_queue');
  foreach ($reviewers as $reviewer) {
    $send_email_reviewer_queue->createItem(array(
      'uid' => $reviewer->uid,
      'request_id' => $request_id,
    ));
  }
}
