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
      'title' => t('User\'s Novo application status'),
      'help' => t('Provide buttons for create novo application.'),
      'handler' => 'novo_applications_handler_app_status_btn',
    ),
  );

  $data['node']['novo_application_status'] = array(
    'real field' => 'nid',
    'field' => array(
      'title' => t('Novo application status'),
      'help' => t('Provide application status Active/InActive/Started/Completed.'),
      'handler' => 'novo_applications_handler_app_node_status',
    ),
  );

  return $data;
}
