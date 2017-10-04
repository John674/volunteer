<?php

/**
 * @file
 * Novo cia.
 */

/**
 * Data for render node.
 */
function novo_cia_get_render_data($nid) {
  $last_request = novo_cia_get_last_success_request($nid);
  $request_statuses = unserialize(NOVO_CIA_REQUEST_STATUSES);
  $status_request = !empty($last_request) ? $request_statuses[$last_request->request_status] : t('Not Sent');
  $status_buttons = !empty($last_request) ? novo_cia_render_action_buttons($nid) : novo_cia_render_action_buttons($nid, TRUE);
  return array(
    'title' => t('CIA Background Check:'),
    'status_label' => $status_request,
    'status_buttons' => $status_buttons,
  );
}

/**
 * Prepare action buttons.
 */
function novo_cia_prepare_action_buttons($nid) {
  $buttons = array(
    'resend_link' => l('<i class="glyphicon glyphicon-cog"></i> ' . t('Resend'), "novo-cia-request/send/" . $nid, array(
      'query' => drupal_get_destination(),
      'html' => TRUE,
      'attributes' => array(
        'class' => array("btn", "btn-default", "btn-xs"),
      ),
    )),
    'send_link' => l('<i class="glyphicon glyphicon-cog"></i> ' . t('Send'), "novo-cia-request/send/" . $nid, array(
      'query' => drupal_get_destination(),
      'html' => TRUE,
      'attributes' => array(
        'class' => array("btn", "btn-default", "btn-xs"),
      ),
    )),
    'view_report_disabled' => l('<i class="glyphicon glyphicon-eye-open"></i> ' . t('View Report'), "/", array(
      'html' => TRUE,
      'attributes' => array(
        'class' => array("btn", "btn-default", "btn-xs"),
        'disabled' => 'true',
        'role' => 'button',
      ),
    )),
    'view_report_enabled' => l('<i class="glyphicon glyphicon-eye-open"></i> ' . t('View Report'), "novo-cia/view_report/" . $nid, array(
      'query' => drupal_get_destination(),
      'html' => TRUE,
      'attributes' => array(
        'class' => array("btn", "btn-default", "btn-xs"),
        'role' => 'button',
      ),
    )),
  );

  return $buttons;
}

/**
 * Render action buttons.
 */
function novo_cia_render_action_buttons($nid, $first_request = FALSE) {
  $buttons = novo_cia_prepare_action_buttons($nid);
  $completed_pull_request = novo_cia_get_completed_pull_request($nid);
  if (!$first_request) {
    $output = $buttons['resend_link'];
    if (!empty($completed_pull_request)) {
      $output = $output . ' ' . $buttons['view_report_enabled'];
    }
    else {
      $output = $output . ' ' . $buttons['view_report_disabled'];
    }
  }
  else {
    $output = $buttons['send_link'] . ' ' . $buttons['view_report_disabled'];
  }
  return $output;
}

/**
 * Get application data for request to CIA.
 */
function novo_cia_get_application_data($nid) {
  $application = node_load($nid);
  $application_data = array();
  $map_application_data = unserialize(NOVO_CIA_MAP_APPLICATION_DATA);
  $test_mode = variable_get(NOVO_CIA_API_IS_TEST);
  foreach ($map_application_data as $key => $field_name) {
    if (!empty($field_name)) {
      $field = field_get_items('node', $application, $field_name);
      $field = reset($field);
      switch ($field_name) {
        case 'field_state':
          if (isset($field['tid']) && !empty($field['tid'])) {
            $taxanomy_term = taxonomy_term_load($field['tid']);
            $application_data[$key] = isset($taxanomy_term->name) && !empty($taxanomy_term->name) ? trim($taxanomy_term->name) : '';
          }
          else {
            $application_data[$key] = '';
          }
          break;

        case 'field_ssn':
          if (empty($test_mode)) {
            $ssn = isset($field['value']) && !empty($field['value']) ? trim($field['value']) : '';
            $ssn_array = novo_cia_format_ssn_array($ssn);
            $application_data[$key] = !empty($ssn_array) ? $ssn_array : NULL;
          }
          else {
            $application_data[$key] = array(
              'ssn1' => '111',
              'ssn2' => '11',
              'ssn3' => '1111',
            );
          }
          break;

        case 'field_dob':
          $dob_array = array(
            'month' => '',
            'day' => '',
            'year' => '',
          );
          if (!empty($field['value'])) {
            $dob_array['month'] = format_date($field['value'], 'custom', 'm');
            $dob_array['day'] = format_date($field['value'], 'custom', 'd');
            $dob_array['year'] = format_date($field['value'], 'custom', 'Y');
          }
          $application_data[$key] = $dob_array;
          break;

        default:
          $application_data[$key] = isset($field['value']) && !empty($field['value']) ? trim($field['value']) : '';
          break;
      }

    }
    else {
      $application_data[$key] = '';
    }
  }
  if (!empty($test_mode)) {
    $application_data['first_name'] = $application_data['first_name'] . 'TEST';
    $application_data['last_name'] = $application_data['last_name'] . 'TEST';
  }
  return $application_data;
}

/**
 * Formatted ssn to array.
 */
function novo_cia_format_ssn_array($ssn) {
  if (empty($ssn)) {
    return NULL;
  }
  $regex = "/^\d{3}-\d{2}-\d{4}$/";
  $formatted_ssn_array = array();

  if (!empty(preg_match($regex, $ssn))) {
    $formatted_ssn_array = explode("-", $ssn);
    $formatted_ssn_array = array_combine(array(
      'ssn1',
      'ssn2',
      'ssn3',
    ), $formatted_ssn_array);
    return $formatted_ssn_array;
  }

  $ssn = trim(preg_replace("/\D*/", "", $ssn));

  if (strlen($ssn) != 9) {
    return NULL;
  }

  $formatted_ssn_array['ssn1'] = substr($ssn, 0, 3);
  $formatted_ssn_array['ssn2'] = substr($ssn, 3, 2);
  $formatted_ssn_array['ssn3'] = substr($ssn, 5, 4);

  return $formatted_ssn_array;
}

/**
 * Check response report status.
 */
function novo_cia_check_report_status($report) {
  $status = 0;
  if (empty($report['ReportStatus']) || ($report['NumberRequests'] != $report['NumberRequestsCompleted'])) {
    $status = 0;
  }
  elseif (isset($report['RequestDetails']) && !empty($report['RequestDetails'])) {
    $status = 1;
    $request_details = $report['RequestDetails'];
    foreach ($request_details as $record) {
      if (isset($record['NumberRecords']) && !empty(trim($record['NumberRecords']))) {
        if (isset($record['RequestType']) && !empty($record['RequestType'])) {
          if ($record['RequestType'] == 'Sexual Offender Registry') {
            $status = 2;
            break;
          }
          else {
            $status = 3;
          }
        }
      }
    }
  }
  return $status;
}
