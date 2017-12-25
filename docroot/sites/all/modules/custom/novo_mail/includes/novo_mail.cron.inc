<?php

/**
 * @file
 * Mail cron.
 */

define("NOVO_MAIL_CRON_PERIOD", 60 * 5);

define("NOVO_MAIL_HOURLY_CRON_PERIOD", 60 * 60);

/**
 * Implements hook_cron_queue_info().
 */
function novo_mail_cron_queue_info() {
  $queue['novo_mail_app_exp_email_queue'] = [
    'worker callback' => 'novo_mail_app_exp_email_queue_worker',
    'time' => 60,
  ];

  $queue['novo_mail_app_not_completed_to_admin_24_queue'] = [
    'worker callback' => 'novo_mail_app_not_completed_to_admin_24_queue_worker',
    'time' => 60,
  ];

  $queue['novo_mail_app_not_completed_to_admin_72_queue'] = [
    'worker callback' => 'novo_mail_app_not_completed_to_admin_72_queue_worker',
    'time' => 60,
  ];

  $queue['novo_mail_app_not_completed_to_volunteer_24_queue'] = [
    'worker callback' => 'novo_mail_app_not_completed_to_volunteer_24_queue_worker',
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
  $cron_last = variable_get('novo_mail_cron_last');
  if (REQUEST_TIME - $cron_last > NOVO_MAIL_CRON_PERIOD) {
    $email_queue = DrupalQueue::get('novo_mail_app_exp_email_queue');
    $data = novo_mail_app_get_all_expired_nids();
    foreach ($data as $key => $item) {
      $email_queue->createItem((array) $item);
    }

    variable_set('novo_mail_cron_last', REQUEST_TIME);
  }

  $cron_last_hourly = variable_get('novo_mail_cron_last_hourly');
  if (REQUEST_TIME - $cron_last_hourly > NOVO_MAIL_HOURLY_CRON_PERIOD) {
    // Not completed nids.
    $email_queue = DrupalQueue::get('novo_mail_app_not_completed_to_admin_24_queue');
    $data = novo_mail_app_get_all_not_completed_nids(24, "novo_mail_app_not_completed_to_admin_24");
    foreach ($data as $key => $item) {
      $email_queue->createItem((array) $item);
    }

    $email_queue = DrupalQueue::get('novo_mail_app_not_completed_to_admin_72_queue');
    $data = novo_mail_app_get_all_not_completed_nids(72, "novo_mail_app_not_completed_to_admin_72");
    foreach ($data as $key => $item) {
      $email_queue->createItem((array) $item);
    }

    $email_queue = DrupalQueue::get('novo_mail_app_not_completed_to_volunteer_24_queue');
    $data = novo_mail_app_get_all_not_completed_nids(24, "novo_mail_app_not_completed_to_volunteer_24");
    foreach ($data as $key => $item) {
      $email_queue->createItem((array) $item);
    }

    variable_set('novo_mail_cron_last_hourly', REQUEST_TIME);
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

/**
 * Not completed app form email send.
 */
function novo_mail_app_not_completed_progress($key, $nid) {
  $result = novo_mail_send($nid, $key);

  if ($result && isset($result['result']) && $result['result']) {
    novo_mail_add_status_to_storage($key, $nid);
  }
}

/**
 * Not completed app 24 hour to admin worker.
 */
function novo_mail_app_not_completed_to_admin_24_queue_worker($data) {
  novo_mail_app_not_completed_progress('novo_mail_app_not_completed_to_admin_24', $data['nid']);
}

/**
 * Not completed app 72 hour to admin worker.
 */
function novo_mail_app_not_completed_to_admin_72_queue_worker($data) {
  novo_mail_app_not_completed_progress('novo_mail_app_not_completed_to_admin_72', $data['nid']);
}

/**
 * Not completed app 24 hour to volunteer worker.
 */
function novo_mail_app_not_completed_to_volunteer_24_queue_worker($data) {
  novo_mail_app_not_completed_progress('novo_mail_app_not_completed_to_volunteer_24', $data['nid']);
}