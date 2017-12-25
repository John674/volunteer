<?php

/**
 * @file
 * Mail cron.
 */

define("NOVO_MAIL_APP_EXP_EMAIL_CRON_PERIOD", 60 * 5);

/**
 * Implements hook_cron_queue_info().
 */
function novo_mail_cron_queue_info() {
  $queue['novo_mail_app_exp_email_queue'] = [
    'worker callback' => 'novo_mail_app_exp_email_queue_worker',
    'time' => 60,
  ];

  $queue['novo_mail_queue'] = [
    'worker callback' => 'novo_mail_queue_worker',
    'time' => 60,
  ];
  return $queue;
}

/**
 * Implements hook_cron().
 */
function novo_mail_cron() {
  $cron_last = variable_get('novo_mail_app_exp_email_cron_last');
  if (REQUEST_TIME - $cron_last > NOVO_MAIL_APP_EXP_EMAIL_CRON_PERIOD) {
    $email_queue = DrupalQueue::get('novo_mail_app_exp_email_queue');
    $data = novo_mail_app_get_all_expired_nids();
    foreach ($data as $key => $item) {
      $email_queue->createItem((array) $item);
    }

    variable_set('novo_mail_app_exp_email_cron_last', REQUEST_TIME);
  }
}

/**
 * Expired email queue worker.
 */
function novo_mail_app_exp_email_queue_worker($data) {
  // Send email.
  $nid = $data['nid'];
  $additional_params = ['link' => url("node/" . $nid, ["absolute" => TRUE])];
  $result = novo_mail_send($nid, 'novo_mail_app_expired_to_admin', $additional_params);

  if ($result && isset($result['result']) && $result['result']) {
    novo_mail_add_status_to_storage('novo_mail_app_expired_to_admin', $nid);
  }
}

/**
 * Mail queue worker.
 */
function novo_mail_queue_worker($item) {
  novo_mail_send($item['nid'], $item['key'], $item['additional_params']);
}