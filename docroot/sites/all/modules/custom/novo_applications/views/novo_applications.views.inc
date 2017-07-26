<?php

/**
 * @file
 * Novo applications views.
 */

/**
 * Implements hook_views_data().
 */
function novo_applications_views_data() {
  $data = array();

  $data['users']['novo_application_status'] = array(
    'real field' => 'uid',
    'field' => array(
      'title' => t('Novo application status'),
      'help' => t('Provide buttons for create novo application.'),
      'handler' => 'novo_applications_handler_app_status_btn',
    ),
  );

  return $data;
}
