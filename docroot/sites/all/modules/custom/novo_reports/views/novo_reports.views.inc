<?php

/**
 * @file
 * Novo reports views handlers.
 */

/**
 * Implements hook_views_data().
 */
function novo_reports_views_data() {
  $data = array();

  $data['node']['novo_reports_enrolled'] = array(
    'real field' => 'nid',
    'group' => t('Novo reports'),
    'field' => array(
      'title' => t('Novo reports attendance enrolled kids number'),
      'help' => t('Novo reports attendance enrolled kids number.'),
      'handler' => 'novo_reports_handler_attendance_enrolled',
    ),
  );

  $data['node']['novo_reports_attendance'] = array(
    'real field' => 'nid',
    'group' => t('Novo reports'),
    'field' => array(
      'title' => t('Novo reports attendance kids number'),
      'help' => t('Novo reports attendance kids number.'),
      'handler' => 'novo_reports_handler_attendance',
    ),
  );

  $data['node']['novo_reports_attendance_new'] = array(
    'real field' => 'nid',
    'group' => t('Novo reports'),
    'field' => array(
      'title' => t('Novo reports attendance new kids number'),
      'help' => t('Novo reports attendance new kids number.'),
      'handler' => 'novo_reports_handler_attendance_new',
    ),
  );

  return $data;
}
