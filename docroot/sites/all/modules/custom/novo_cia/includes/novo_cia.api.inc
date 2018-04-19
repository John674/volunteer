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
  $app_nid = $search_request->application_nid;
  $application_data = novo_cia_get_data_for_cia_request($app_nid);
  $api_credentials = novo_cia_get_api_credentials();
  $request_data = array_merge($api_credentials, $application_data);
  $api_urls = unserialize(NOVO_CIA_API_URLS);
  $search_url = $api_urls['search'];
  if (!empty($request_data['ssn'])) {
    $request_body = theme('novo_cia_request_by_ssn', $request_data);
  }
  else {
    $request_body = theme('novo_cia_request_by_address', $request_data);
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
      if (strtolower($feed_array['Status']) == NOVO_CIA_RESPONSE_STATUS_ACCEPTED) {

        if (isset($feed_array['TrackingNumber']) && !empty($feed_array['TrackingNumber'])) {
          $tracking_number = $feed_array['TrackingNumber'];
          novo_cia_update_request($search_request->id, array(
            'tracking_number' => $tracking_number,
            'request_status' => 3,
          ));
          novo_cia_add_pull_report_request_to_queue($search_request->application_nid, $search_request->uid, $search_request->id, $tracking_number);
          return TRUE;
        }
      }

      if (strtolower($feed_array['Status']) != NOVO_CIA_RESPONSE_DATABASE_OFFLINE) {
        $error = isset($feed_array['Error']) && !empty($feed_array['Error']) ? $feed_array['Error'] : NULL;

        // @codingStandardsIgnoreStart
      /*  if (strtolower($feed_array['Error']) == NOVO_CIA_ERROR_RESPONSE_MESSAGE_DUPLICATE) {
          $error_message = $feed_array['DuplicateList']['DuplicateSearch'];
          $last_pending_pull_report_request = novo_cia_get_last_pending_pull_report_request($app_nid);
          if (empty($last_pending_pull_report_request)) {
            novo_cia_add_search_request_to_queue($app_nid, $search_request->uid);
          }
        }
        else {
          novo_cia_add_search_request_to_queue($app_nid, $search_request->uid);
        }*/
        // @codingStandardsIgnoreEnd
        $attempts = novo_cia_get_request_attempts($request_id);
        if ($attempts > variable_get(NOVO_CIA_API_ATTEMPTS)) {
          novo_cia_update_request($request_id, array(
            'request_status' => 2,
            'log' => $feed_array['Status'],
            'response' => $error,
          ));
        }
        else {
          $new_attempts = ++$attempts;
          novo_cia_update_request($request_id, array(
            'attempts_number' => $new_attempts,
          ));
        }
      }
    }
  }
  return NULL;
}

/**
 * Send pull report request to CIA.
 */
function novo_cia_send_pull_report_request($request_id = NULL) {
  if (empty($request_id)) {
    return NULL;
  }
  $pull_report_request = novo_cia_get_request($request_id);
  $tracking_number = $pull_report_request->tracking_number;
  if (empty($tracking_number)) {
    return NULL;
  }
  $api_urls = unserialize(NOVO_CIA_API_URLS);
  $pull_report_url = $api_urls['pull_report'];

  $request_data = novo_cia_get_api_credentials();
  $request_data['tracking_number'] = $tracking_number;

  $request_body = theme('novo_cia_query_report', $request_data);
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
        $feed_xml = simplexml_load_string($response->data);
        $feed_json = json_encode($feed_xml);
        $feed_array = json_decode($feed_json, TRUE);
        if (isset($feed_array) && isset($feed_array['Report']) && !empty($feed_array['Report'])) {
          $report = $feed_array['Report'];
          $report_status = novo_cia_check_report_status($report);
          $report_data = array(
            'response_date' => REQUEST_TIME,
            'report_status' => $report_status,
          );
          if (!empty($report_status)) {
            $nid = $pull_report_request->application_nid;
            $result = novo_cia_set_expiration_date($nid);
            $report_data['request_status'] = 1;
          }
          novo_cia_update_request($request_id, $report_data);
          $request = novo_cia_get_request($request_id);
          return $request;
        }
        elseif (strtolower($feed_array['Status']) != NOVO_CIA_RESPONSE_DATABASE_OFFLINE) {
          $error = isset($feed_array['Error']) && !empty($feed_array['Error']) ? $feed_array['Error'] : NULL;
          $attempts = novo_cia_get_request_attempts($request_id);
          if ($attempts > variable_get(NOVO_CIA_API_ATTEMPTS)) {
            novo_cia_update_request($request_id, array(
              'request_status' => 2,
              'log' => $feed_array['Status'],
              'response' => $error,
            ));
          }
          else {
            $new_attempts = ++$attempts;
            novo_cia_update_request($request_id, array(
              'attempts_number' => $new_attempts,
            ));
          }
        }
      }
    }
  }
  return NULL;
}

/**
 * Pull to CIA for report doc.
 */
function novo_cia_pull_report_doc($tracking_number) {
  $api_urls = unserialize(NOVO_CIA_API_URLS);
  $api_credentials = novo_cia_get_api_credentials();

  $get_report_url = format_string($api_urls['get_report'], array(
    '@username' => $api_credentials['username'],
    '@password' => $api_credentials['password'],
    '@tracking_number' => $tracking_number,
  ));

  $result = novo_cia_drupal_http_request($get_report_url);
  $context = isset($result->data) && !empty($result->data) ? $result->data : '';
  return $context;
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
