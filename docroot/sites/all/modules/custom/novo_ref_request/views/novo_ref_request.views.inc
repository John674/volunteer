<?php

/**
 * @file
 * HR not relevant report fields for views.
 */

/**
 * Implements hook_views_data().
 */
function novo_ref_request_views_data() {
  $data = array();
  $data['novo_ref_tasks']['table']['group'] = t('Novo referral request tasks');

  $data['novo_ref_tasks']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Novo referral request tasks'),
    'help' => t('Contains records of referral request tasks.'),
  );

  $data['novo_ref_tasks']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  $data['novo_ref_tasks']['id'] = array(
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

  $data['novo_ref_tasks']['uid'] = array(
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

  $data['novo_ref_tasks']['nid'] = array(
    'title' => t('Ref request node'),
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

  $data['novo_ref_tasks']['name'] = array(
    'title' => t('Task name'),
    'help' => t('The task name.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );

  $data['novo_ref_tasks']['email'] = array(
    'title' => t('Ref email'),
    'help' => t('The Referral email.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );

  $data['novo_ref_tasks']['phone'] = array(
    'title' => t('Ref phone'),
    'help' => t('The Referral email.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );

  $data['novo_ref_tasks']['status'] = array(
    'title' => t('Status'),
    'help' => t('Status.'),
    'field' => array(
      'handler' => 'novo_ref_request_handler_status',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  $data['novo_ref_tasks']['created'] = array(
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

  $data['novo_ref_tasks']['updated'] = array(
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

  $data['novo_ref_tasks']['volunteer_nid'] = array(
    'title' => t('Volunteer node'),
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

  $data['novo_ref_tasks']['volunteer_name'] = array(
    'title' => t('Volunteer name'),
    'help' => t('The volunteer name.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );

  $data['novo_ref_tasks']['actions'] = array(
    'real field' => 'status',
    'field' => array(
      'title' => t('Actions'),
      'help' => t('Provide buttons.'),
      'handler' => 'novo_ref_request_handler_actions',
    ),
  );

  return $data;
}
