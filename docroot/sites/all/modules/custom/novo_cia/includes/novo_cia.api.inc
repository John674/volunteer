<?php

/**
 * @file
 * Novo cia API.
 */

/**
 * Send search request to CIA.
 */
function novo_cia_send_search_request($request_id) {
  $search_request = novo_cia_get_request($request_id);
  $application_data = novo_cia_get_application_data($search_request->application_nid);
  $request_data = novo_cia_get_api_credentials();
  $request_data += $application_data;
  $api_urls = unserialize(NOVO_CIA_API_URLS);
  $search_url = $api_urls['search'];
  if (!empty($request_data['ssn'])) {
    $request_body = theme('cia_request_by_ssn', $request_data);
  }
  else {
    $request_body = theme('cia_request_by_address', $request_data);
  }
  $request_body = trim(preg_replace('/<!--(.*)-->/Uis', '', $request_body));

  if (!empty($search_url) && !empty($request_body)) {
    $response = drupal_http_request($search_url, array(
      'headers' => array(
        'Content-Type' => 'application/xml',
        'Content-Length' => strlen($request_body),
      ),
      'method' => 'POST',
      'data' => $request_body,
    ));

    if ($response->code == 200 || $response->code == 201 || $response->status_message == 'OK') {
      $feed_xml = simplexml_load_string($response->data);
      $feed_json = json_encode($feed_xml);
      $feed_array = json_decode($feed_json, TRUE);
      if ($feed_array['Status'] == NOVO_CIA_RESPONSE_STATUS_ACCEPTED) {
        $tracking_number = $feed_array['TrackingNumber'];
        if (!empty($tracking_number)) {
          novo_cia_update_request($search_request->id, array(
            'tracking_number' => $tracking_number,
            'request_status' => 1,
          ));
          novo_cia_add_to_queue_pull_report_request($search_request->application_nid, $search_request->uid, $search_request->id, $tracking_number);
          return TRUE;
        }
      }

      if ($feed_array['Status'] == NOVO_CIA_RESPONSE_STATUS_REJECTED) {
        $error = isset($feed_array['Error']) && !empty($feed_array['Error']) ? $feed_array['Error'] : NULL;
        $error_message = NULL;
        if ($feed_array['Error'] == NOVO_CIA_ERROR_RESPONSE_MESSAGE_DUPLICATE) {
          $error_message = $feed_array['DuplicateList']['DuplicateSearch'];
        }
        novo_cia_update_request($request_id, array(
          'request_status' => 2,
          'log' => $error,
          'response' => $error_message,
        ));
        $last_pending_pull_report_request = novo_cia_get_last_pending_pull_report_request($search_request->application_nid);
        if (empty($last_pending_pull_report_request) && empty($last_pending_pull_report_request->tracking_number)) {
          novo_cia_add_to_queue_search_request($search_request->application_nid, $search_request->uid);
        }
      }
    }
  }
  return NULL;
}

/**
 * Send pull report request to CIA.
 */
function novo_cia_send_pull_report_request($request_id) {
  $request = novo_cia_get_request($request_id);
  $tracking_number = $request->tracking_number;
  if (empty($tracking_number)) {
    return NULL;
  }
  $request_data = novo_cia_get_api_credentials();
  $api_urls = unserialize(NOVO_CIA_API_URLS);
  $pull_report_url = $api_urls['pull_report'];
  $request_data['tracking_number'] = $tracking_number;
  $request_body = theme('cia_query_report', $request_data);
  $request_body = trim(preg_replace('/<!--(.*)-->/Uis', '', $request_body));

  if (!empty($pull_report_url) && !empty($request_body)) {
    $response = drupal_http_request($pull_report_url, array(
      'headers' => array(
        'Content-Type' => 'application/xml',
        'Content-Length' => strlen($request_body),
      ),
      'method' => 'POST',
      'data' => $request_body,
    ));

    if ($response->code == 200 || $response->code == 201 || $response->status_message == 'OK') {
      if (isset($response->data) && !empty($response->data)) {
        if (empty($request->request_date)) {
          novo_cia_update_request($request_id, array('request_date' => time()));
        }
        $feed_xml = simplexml_load_string($response->data);
        $feed_json = json_encode($feed_xml);
        $feed_array = json_decode($feed_json, TRUE);
        if (isset($feed_array) && isset($feed_array['Report']) && !empty($feed_array['Report'])) {
          $report = $feed_array['Report'];
          $report_status = novo_cia_check_report_status($report);
          $report_data = array(
            'response_date' => time(),
            'report_status' => $report_status,
          );
          if (!empty($report_status)) {
            $report_data['request_status'] = 1;
          }
          novo_cia_update_request($request_id, $report_data);
          return TRUE;
        }
      }
    }
  }

  return NULL;
}

/**
 * Get credentials from CIA account.
 */
function novo_cia_get_api_credentials() {
  return array(
    'username' => variable_get(NOVO_CIA_API_USERNAME),
    'password' => variable_get(NOVO_CIA_API_PASSWORD),
    'client_name' => variable_get(NOVO_CIA_API_CLIENT_NAME),
    'branch_name' => variable_get(NOVO_CIA_API_BRANCH_NAME),
    'client_contact' => variable_get(NOVO_CIA_API_CLIENT_CONTACT),
    'client_contact_email' => variable_get(NOVO_CIA_API_CLIENT_CONTACT_EMAIL),
  );
}