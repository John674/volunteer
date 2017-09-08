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

  $data['node']['novo_application_active_status'] = array(
    'title' => t('Novo application active status'),
    'help' => t('Provide Novo application active status sort.'),
    'real field' => 'nid',
    'field' => array(
      'title' => t('Novo application active status'),
      'help' => t('Provide application active status Current/Lapsed/Inactive.'),
      'handler' => 'novo_reports_handler_attendanceenrolled',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'novo_applications_handler_app_active_status_sort',
    ),
    'filter' => array(
      'real field' => 'nid',
      'handler' => 'novo_applications_handler_app_active_status_filter',
    ),
  );

  $data['node']['novo_application_last_date_serving'] = array(
    'title' => t('Novo application Last date serving'),
    'help' => t('Provide Novo application Last date serving sort.'),
    'real field' => 'nid',
    'field' => array(
      'title' => t('Novo application Last date serving'),
      'help' => t('Provide application Last date serving.'),
      'handler' => 'novo_applications_handler_app_last_date_serving',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'novo_applications_handler_app_last_date_serving_sort',
    ),
  );


  return $data;
}
