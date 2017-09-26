<?php

/**
 * @file
 * Novo cia fields for views.
 */

/**
 * Implements hook_views_data().
 */
function novo_cia_views_data() {
  $data = array();
  $data['novo_cia_checks']['table']['group'] = t('Novo CIA requests');

  $data['novo_cia_checks']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Novo CIA requests'),
    'help' => t('Contains records of request to CIA.'),
  );

  $data['novo_cia_checks']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
    'node' => array(
      'left_field' => 'nid',
      'field' => 'application_nid',
    ),
  );

  $data['novo_cia_checks']['id'] = array(
    'title' => t('ID'),
    'help' => t('The record ID.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  $data['novo_cia_checks']['uid'] = array(
    'title' => t('User ID'),
    'help' => t('The record user ID.'),
    'field' => array(
      'handler' => 'views_handler_field_user',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'relationship' => array(
      'base' => 'users',
      'base field' => 'uid',
      'handler' => 'views_handler_relationship',
      'label' => t('User'),
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
      'numeric' => TRUE,
      'validate type' => 'uid',
    ),
  );

  $data['novo_cia_checks']['application_nid'] = array(
    'title' => t('Application'),
    'help' => t('The record node ID.'),
    'field' => array(
      'handler' => 'views_handler_field_node',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Node'),
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_node_nid',
      'numeric' => TRUE,
      'validate type' => 'nid',
    ),
  );

  $data['novo_cia_checks']['request_status'] = array(
    'title' => t('Status'),
    'help' => t('Status.'),
    'field' => array(
      'handler' => 'novo_cia_handler_status',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );
  $data['novo_cia_checks']['report_status'] = array(
    'title' => t('Report status'),
    'help' => t('Report status.'),
    'field' => array(
      'handler' => 'novo_cia_handler_report_status',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  $data['novo_cia_checks']['request_type'] = array(
    'title' => t('Type'),
    'help' => t('Types.'),
    'field' => array(
      'handler' => 'novo_cia_handler_type',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  $data['novo_cia_checks']['request_date'] = array(
    'title' => t('Request date'),
    'help' => t('The date the request to CIA was send.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['novo_cia_checks']['response_date'] = array(
    'title' => t('Response date'),
    'help' => t('The date the response from CIA was got.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  $data['novo_cia_checks']['tracking_number'] = array(
    'title' => t('Tracking number'),
    'help' => t('Tracking number'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['novo_cia_checks']['created'] = array(
    'title' => t('Created date'),
    'help' => t('The date the content was posted.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['novo_cia_checks']['updated'] = array(
    'title' => t('Updated date'),
    'help' => t('The date the content was updated.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['novo_cia_checks']['actions'] = array(
    'real field' => 'application_nid',
    'field' => array(
      'title' => t('Actions'),
      'help' => t('Provide buttons.'),
      'handler' => 'novo_cia_handler_actions',
    ),
  );

  return $data;
}
