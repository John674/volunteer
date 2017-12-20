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
  return [
    'title' => t('CIA Background Check:'),
    'status_label' => $status_request,
    'status_buttons' => $status_buttons,
  ];
}

/**
 * Prepare action buttons.
 */
function novo_cia_prepare_action_buttons($nid) {
  $buttons = [];

  if (user_access("send CIA")) {
    $buttons['resend_link'] = l('<i class="glyphicon glyphicon-envelope"></i> ' . t('Resend'), "novo-cia-request/send/" . $nid, [
      'query' => drupal_get_destination(),
      'html' => TRUE,
      'attributes' => [
        'class' => ["btn", "btn-default", "btn-xs"],
      ],
    ]);
    $buttons['send_link'] = l('<i class="glyphicon glyphicon-envelope"></i> ' . t('Send'), "novo-cia-request/send/" . $nid, [
      'query' => drupal_get_destination(),
      'html' => TRUE,
      'attributes' => [
        'class' => ["btn", "btn-default", "btn-xs"],
      ],
    ]);
  }

  if (user_access("view CIA")) {
    $buttons['view_report_disabled'] = l('<i class="glyphicon glyphicon-eye-open"></i> ' . t('View Report'), "/", [
      'html' => TRUE,
      'attributes' => [
        'class' => ["btn", "btn-default", "btn-xs"],
        'disabled' => 'true',
        'role' => 'button',
      ],
    ]);
    $buttons['view_report_enabled'] = l('<i class="glyphicon glyphicon-eye-open"></i> ' . t('View Report'), "novo-cia/view_report/" . $nid, [
      'query' => drupal_get_destination(),
      'html' => TRUE,
      'attributes' => [
        'class' => ["btn", "btn-default", "btn-xs"],
        'role' => 'button',
        'target' => '_blank',
      ],
    ]);
  }

  return $buttons;
}

/**
 * Render action buttons.
 */
function novo_cia_render_action_buttons($nid, $first_request = FALSE) {
  $buttons = novo_cia_prepare_action_buttons($nid);
  $completed_pull_request = novo_cia_get_completed_pull_request($nid);
  $output = [];
  if (!$first_request) {
    if (isset($buttons['resend_link'])) {
      $output[] = $buttons['resend_link'];
    }
    if (!empty($completed_pull_request)) {
      if (isset($buttons['view_report_enabled'])) {
        $output[] = $buttons['view_report_enabled'];
      }
    }
    else {
      if (isset($buttons['view_report_disabled'])) {
        $output[] = $buttons['view_report_disabled'];
      }
    }
  }
  else {
    if (isset($buttons['send_link'])) {
      $output[] = $buttons['send_link'];
    }
    if (isset($buttons['view_report_disabled'])) {
      $output[] = $buttons['view_report_disabled'];
    }
  }
  return implode(" ", $output);
}

/**
 * Get application data for request to CIA.
 */
function novo_cia_get_data_for_cia_request($nid) {
  $application = node_load($nid);
  $application_data = [];
  $map_application_data = unserialize(NOVO_CIA_MAP_APPLICATION_DATA);
  $test_mode = variable_get(NOVO_CIA_API_IS_TEST);
  foreach ($map_application_data as $key => $field_name) {
    if (!empty($field_name)) {
      $field = field_get_items('node', $application, $field_name);
      if (!empty($field)) {
        $field = reset($field);
        switch ($field_name) {
          case 'field_state':
            if (isset($field['tid']) && !empty($field['tid'])) {
              $taxonomy_term = taxonomy_term_load($field['tid']);
              $application_data[$key] = isset($taxonomy_term->name) && !empty($taxonomy_term->name) ? trim($taxonomy_term->name) : '';
            }
            else {
              $application_data[$key] = '';
            }
            break;

          case 'field_ssn':
            if (empty($test_mode)) {
              $ssn = isset($field['value']) && !empty($field['value']) ? trim($field['value']) : NULL;
              $application_data[$key] = !empty($ssn) ? novo_cia_format_ssn_to_array($ssn) : NULL;
            }
            else {
              $application_data[$key] = [
                'ssn1' => '111',
                'ssn2' => '11',
                'ssn3' => '1111',
              ];
            }
            break;

          case 'field_dob':
            $dob_array = [
              'month' => '',
              'day' => '',
              'year' => '',
            ];
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
function novo_cia_format_ssn_to_array($ssn) {
  if (empty($ssn)) {
    return NULL;
  }
  $regex = "/^\d{3}-\d{2}-\d{4}$/";
  $formatted_ssn_array = [];

  if (!empty(preg_match($regex, $ssn))) {
    $formatted_ssn_array = explode("-", $ssn);
    $formatted_ssn_array = array_combine([
      'ssn1',
      'ssn2',
      'ssn3',
    ], $formatted_ssn_array);
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

/**
 * Set expiration date for node.
 */
function novo_cia_set_expiration_date($nid = NULL) {
  if (empty($nid)) {
    return NULL;
  }

  $node = node_load($nid);
  if (!empty($node)) {
    cache_clear_all("field:node:$nid", 'cache_field');
    $expired_date = strtotime('+36 months', REQUEST_TIME);
    $node->field_expired_date[$node->language][0]['value'] = $expired_date;
    $info = field_info_field('field_expired_date');
    $fields = [$info['id']];
    field_sql_storage_field_storage_write('node', $node, 'update', $fields);
    cache_clear_all("field:node:$node->nid", 'cache_field');
    return TRUE;
  }
  return FALSE;
}

/**
 * Check expired requests.
 */
function novo_cia_is_expired_request($request_id = NULL) {
  if (empty($request_id)) {
    return NULL;
  }

  $request = novo_cia_get_request($request_id);
  if (empty($request) || ($request->request_type != 1) || $request->request_status != 1) {
    return NULL;
  }

  $response_date = $request->response_date;
  $expired_date = strtotime('+36 months', $response_date);
  if (REQUEST_TIME > $expired_date && ($request->request_status != 4)) {
    $update_data = [
      'request_status' => 4,
    ];
    $result = novo_cia_update_request($request_id, $update_data);
    if (!empty($result)) {
      novo_cia_add_send_mail_reviewer_to_queue($request_id);
    }
  }
  return TRUE;
}

/**
 * Add search request to CIA.
 */
function novo_cia_add_request_for_search($node) {
  if ($node->type == 'application') {
    $lang = isset($node->language) ? $node->language : LANGUAGE_NONE;
    $app_completed = (isset($node->field_completed[$lang][0]['value'])) ? $node->field_completed[$lang][0]['value'] : FALSE;

    if (empty($app_completed)) {
      drupal_set_message(t("Application must be completed for CIA request."), 'error');
      $url = $_GET['destination'] ? $_GET['destination'] : '<front>';
      drupal_goto($url);
    }

    $nid = $node->nid;
    $uid = $node->uid;
    if (isset($nid) && !empty($nid)) {
      $search_request_id = novo_cia_add_search_request_to_queue($nid, $uid);
      if (!empty($search_request_id)) {
        drupal_set_message(t("The request was added to the queue for sending to CIA."));
      }
      else {
        drupal_set_message(t("The request was`t be added to the queue for sending to CIA."), 'error');
      }
    }
  }
  else {
    drupal_set_message(t('Node type should be application'), 'error');
  }
  $url = $_GET['destination'] ? $_GET['destination'] : '<front>';
  drupal_goto($url);
}

/**
 * Get report document.
 */
function novo_cia_get_report_doc($nid) {
  $completed_pull_request = novo_cia_get_completed_pull_request($nid);
  $tracking_number = !empty($completed_pull_request) ? $completed_pull_request->tracking_number : NULL;
  if (!empty($tracking_number)) {
    $respond_html_report = novo_cia_pull_report_doc($tracking_number);
    print $respond_html_report;
  }
  else {
    drupal_set_message(t('Could`t get report.'), 'error');
    $url = $_GET['destination'] ? $_GET['destination'] : '<front>';
    drupal_goto($url);
  }

}

/**
 * Get request or response date for CIA.
 */
function novo_cia_date($nid = NULL, $date_type = NULL, $renewal = FALSE) {
  if (!empty($nid)) {
    $request = novo_cia_get_last_success_request($nid);
    if ($renewal) {
      if (!empty($request->{$date_type}) && !empty($request->tracking_number)) {
        $time = $request->{$date_type};
        return format_date(strtotime("+3 month", $time), 'custom', 'Y-m-d  H:i:s');
      }
      else {
        return 'N/A';
      }
    }
    else {
      return !empty($request->{$date_type}) && !empty($request->tracking_number) ? format_date($request->{$date_type}, 'custom', 'Y-m-d  H:i:s') : 'N/A';
    }
  }
  return NULL;
}

/**
 * Override drupal_http_request.
 */
if (function_exists("novo_cia_drupal_http_request")) {
  $url = '';
  $context = '';
  $response = novo_cia_drupal_http_request($url, [
    'method' => 'GET',
    'max_redirects' => 5,
    'context' => $context,
  ]);
}

/**
 * Performs an HTTP request with Coockies.
 */
function novo_cia_drupal_http_request($url, array $options = []) {
  // Allow an alternate HTTP client library to replace Drupal's default
  // implementation.
  $override_function = variable_get('drupal_http_request_function', FALSE);
  if (!empty($override_function) && function_exists($override_function)) {
    return $override_function($url, $options);
  }

  $result = new stdClass();

  // Parse the URL and make sure we can handle the schema.
  $uri = @parse_url($url);

  if ($uri == FALSE) {
    $result->error = 'unable to parse URL';
    $result->code = -1001;

    return $result;
  }

  if (!isset($uri['scheme'])) {
    $result->error = 'missing schema';
    $result->code = -1002;

    return $result;
  }

  timer_start(__FUNCTION__);

  // Set default context to enable/disable SSL verification.
  $default_context = stream_context_create([
    'ssl' => [
      'verify_peer' => FALSE,
      'verify_peer_name' => FALSE,
    ],
  ]);

  // Merge the default options.
  $options += [
    'headers' => [],
    'method' => 'GET',
    'data' => NULL,
    'max_redirects' => 3,
    'timeout' => 30.0,
    'context' => $default_context,
  ];

  // Merge the default headers.
  $options['headers'] += [
    'User-Agent' => 'Drupal (+http://drupal.org/)',
  ];

  // stream_socket_client() requires timeout to be a float.
  $options['timeout'] = (float) $options['timeout'];

  // Use a proxy if one is defined and the host is not on the excluded list.
  $proxy_server = variable_get('proxy_server', '');
  if ($proxy_server && _drupal_http_use_proxy($uri['host'])) {
    // Set the scheme so we open a socket to the proxy server.
    $uri['scheme'] = 'proxy';
    // Set the path to be the full URL.
    $uri['path'] = $url;
    // Since the URL is passed as the path, we won't use the parsed query.
    unset($uri['query']);

    // Add in username and password to Proxy-Authorization header if needed.
    if ($proxy_username = variable_get('proxy_username', '')) {
      $proxy_password = variable_get('proxy_password', '');
      $options['headers']['Proxy-Authorization'] = 'Basic ' . base64_encode($proxy_username . (!empty($proxy_password) ? ":" . $proxy_password : ''));
    }
    // Some proxies reject requests with any User-Agent headers, while others
    // require a specific one.
    $proxy_user_agent = variable_get('proxy_user_agent', '');
    // The default value matches neither condition.
    if ($proxy_user_agent === NULL) {
      unset($options['headers']['User-Agent']);
    }
    elseif ($proxy_user_agent) {
      $options['headers']['User-Agent'] = $proxy_user_agent;
    }
  }

  switch ($uri['scheme']) {
    case 'proxy':
      // Make the socket connection to a proxy server.
      $socket = 'tcp://' . $proxy_server . ':' . variable_get('proxy_port', 8080);
      // The Host header still needs to match the real request.
      $options['headers']['Host'] = $uri['host'];
      $options['headers']['Host'] .= isset($uri['port']) && $uri['port'] != 80 ? ':' . $uri['port'] : '';
      break;

    case 'http':
    case 'feed':
      $port = isset($uri['port']) ? $uri['port'] : 80;
      $socket = 'tcp://' . $uri['host'] . ':' . $port;
      // RFC 2616: "non-standard ports MUST, default ports MAY be included".
      // We don't add the standard port to prevent from breaking rewrite rules
      // checking the host that do not take into account the port number.
      $options['headers']['Host'] = $uri['host'] . ($port != 80 ? ':' . $port : '');
      break;

    case 'https':
      // Note: Only works when PHP is compiled with OpenSSL support.
      $port = isset($uri['port']) ? $uri['port'] : 443;
      $socket = 'ssl://' . $uri['host'] . ':' . $port;
      $options['headers']['Host'] = $uri['host'] . ($port != 443 ? ':' . $port : '');
      break;

    default:
      $result->error = 'invalid schema ' . $uri['scheme'];
      $result->code = -1003;

      return $result;
  }

  if (empty($options['context'])) {
    $fp = @stream_socket_client($socket, $errno, $errstr, $options['timeout']);
  }
  else {
    // Create a stream with context. Allows verification of a SSL certificate.
    $fp = @stream_socket_client($socket, $errno, $errstr, $options['timeout'], STREAM_CLIENT_CONNECT, $options['context']);
  }

  // Make sure the socket opened properly.
  if (!$fp) {
    // When a network error occurs, we use a negative number so it does not
    // clash with the HTTP status codes.
    $result->code = -$errno;
    $result->error = trim($errstr) ? trim($errstr) : t('Error opening socket @socket', ['@socket' => $socket]);

    // Mark that this request failed. This will trigger a check of the web
    // server's ability to make outgoing HTTP requests the next time that
    // requirements checking is performed.
    // See system_requirements().
    variable_set('drupal_http_request_fails', TRUE);

    return $result;
  }

  // Construct the path to act on.
  $path = isset($uri['path']) ? $uri['path'] : '/';
  if (isset($uri['query'])) {
    $path .= '?' . $uri['query'];
  }

  // Only add Content-Length if we actually have any content or if it is a POST
  // or PUT request. Some non-standard servers get confused by Content-Length in
  // at least HEAD/GET requests, and Squid always requires Content-Length in
  // POST/PUT requests.
  $content_length = strlen($options['data']);
  if ($content_length > 0 || $options['method'] == 'POST' || $options['method'] == 'PUT') {
    $options['headers']['Content-Length'] = $content_length;
  }

  // If the server URL has a user then attempt to use basic authentication.
  if (isset($uri['user'])) {
    $options['headers']['Authorization'] = 'Basic ' . base64_encode($uri['user'] . (isset($uri['pass']) ? ':' . $uri['pass'] : ':'));
  }

  // If the database prefix is being used by SimpleTest to run the tests in a copied
  // database then set the user-agent header to the database prefix so that any
  // calls to other Drupal pages will run the SimpleTest prefixed database. The
  // user-agent is used to ensure that multiple testing sessions running at the
  // same time won't interfere with each other as they would if the database
  // prefix were stored statically in a file or database variable.
  $test_info = &$GLOBALS['drupal_test_info'];
  if (!empty($test_info['test_run_id'])) {
    $options['headers']['User-Agent'] = drupal_generate_test_ua($test_info['test_run_id']);
  }

  $request = $options['method'] . ' ' . $path . " HTTP/1.0\r\n";
  foreach ($options['headers'] as $name => $value) {
    $request .= $name . ': ' . trim($value) . "\r\n";
  }
  $request .= "\r\n" . $options['data'];
  $result->request = $request;
  // Calculate how much time is left of the original timeout value.
  $timeout = $options['timeout'] - timer_read(__FUNCTION__) / 1000;
  if ($timeout > 0) {
    stream_set_timeout($fp, floor($timeout), floor(1000000 * fmod($timeout, 1)));
    fwrite($fp, $request);
  }

  // Fetch response. Due to PHP bugs like http://bugs.php.net/bug.php?id=43782
  // and http://bugs.php.net/bug.php?id=46049 we can't rely on feof(), but
  // instead must invoke stream_get_meta_data() each iteration.
  $info = stream_get_meta_data($fp);
  $alive = !$info['eof'] && !$info['timed_out'];
  $response = '';

  while ($alive) {
    // Calculate how much time is left of the original timeout value.
    $timeout = $options['timeout'] - timer_read(__FUNCTION__) / 1000;
    if ($timeout <= 0) {
      $info['timed_out'] = TRUE;
      break;
    }
    stream_set_timeout($fp, floor($timeout), floor(1000000 * fmod($timeout, 1)));
    $chunk = fread($fp, 1024);
    $response .= $chunk;
    $info = stream_get_meta_data($fp);
    $alive = !$info['eof'] && !$info['timed_out'] && $chunk;
  }
  fclose($fp);

  if ($info['timed_out']) {
    $result->code = HTTP_REQUEST_TIMEOUT;
    $result->error = 'request timed out';

    return $result;
  }
  // Parse response headers from the response body.
  // Be tolerant of malformed HTTP responses that separate header and body with
  // \n\n or \r\r instead of \r\n\r\n.
  list($response, $result->data) = preg_split("/\r\n\r\n|\n\n|\r\r/", $response, 2);
  $response = preg_split("/\r\n|\n|\r/", $response);

  // Parse the response status line.
  $response_status_array = _drupal_parse_response_status(trim(array_shift($response)));
  $result->protocol = $response_status_array['http_version'];
  $result->status_message = $response_status_array['reason_phrase'];
  $code = $response_status_array['response_code'];

  $result->headers = [];

  // Parse the response headers.
  while ($line = trim(array_shift($response))) {
    list($name, $value) = explode(':', $line, 2);
    $name = strtolower($name);
    if (isset($result->headers[$name]) && $name == 'set-cookie') {
      // RFC 2109: the Set-Cookie response header comprises the token Set-
      // Cookie:, followed by a comma-separated list of one or more cookies.
      $result->headers[$name] .= ',' . trim($value);
    }
    else {
      $result->headers[$name] = trim($value);
    }
  }

  $responses = [
    100 => 'Continue',
    101 => 'Switching Protocols',
    200 => 'OK',
    201 => 'Created',
    202 => 'Accepted',
    203 => 'Non-Authoritative Information',
    204 => 'No Content',
    205 => 'Reset Content',
    206 => 'Partial Content',
    300 => 'Multiple Choices',
    301 => 'Moved Permanently',
    302 => 'Found',
    303 => 'See Other',
    304 => 'Not Modified',
    305 => 'Use Proxy',
    307 => 'Temporary Redirect',
    400 => 'Bad Request',
    401 => 'Unauthorized',
    402 => 'Payment Required',
    403 => 'Forbidden',
    404 => 'Not Found',
    405 => 'Method Not Allowed',
    406 => 'Not Acceptable',
    407 => 'Proxy Authentication Required',
    408 => 'Request Time-out',
    409 => 'Conflict',
    410 => 'Gone',
    411 => 'Length Required',
    412 => 'Precondition Failed',
    413 => 'Request Entity Too Large',
    414 => 'Request-URI Too Large',
    415 => 'Unsupported Media Type',
    416 => 'Requested range not satisfiable',
    417 => 'Expectation Failed',
    500 => 'Internal Server Error',
    501 => 'Not Implemented',
    502 => 'Bad Gateway',
    503 => 'Service Unavailable',
    504 => 'Gateway Time-out',
    505 => 'HTTP Version not supported',
  ];
  // RFC 2616 states that all unknown HTTP codes must be treated the same as the
  // base code in their class.
  if (!isset($responses[$code])) {
    $code = floor($code / 100) * 100;
  }
  $result->code = $code;

  switch ($code) {
    case 200:
    case 304:

      break;

    case 301:
    case 302:
    case 307:
      $location = $result->headers['location'];
      $options['timeout'] -= timer_read(__FUNCTION__) / 1000;
      if ($options['timeout'] <= 0) {
        $result->code = HTTP_REQUEST_TIMEOUT;
        $result->error = 'request timed out';
      }
      elseif ($options['max_redirects']) {
        // Redirect to the new location.
        $options['max_redirects']--;

        if (isset($result->headers['set-cookie']) && !empty($result->headers['set-cookie'])) {
          $options['headers']['Cookie'] = $result->headers['set-cookie'];
        }
        $result = novo_cia_drupal_http_request($location, $options);
        $result->redirect_code = $code;
      }
      if (!isset($result->redirect_url)) {
        $result->redirect_url = $location;
      }

      break;

    default:
      $result->error = $result->status_message;
  }

  return $result;
}

/**
 * Send email to referral.
 */
function novo_cia_send_email_to_reviewer($uid = NULL, $request_id = NULL) {
  if (!empty($uid) && !empty($request_id)) {
    $request = novo_cia_get_request($request_id);
    if ($request->request_type != 1 && ($request->request_status != 1 || $request->request_status != 4) && empty($request->tracking_number)) {
      return NULL;
    }
    $mail_key = '';

    $nid = $request->application_nid;
    $reviewer = user_load($uid);

    $reviewer_name = (isset($reviewer->name) && !empty($reviewer->name)) ? $reviewer->name : 'Reviewer';

    $volunteer_link = url('application/' . $nid, ['absolute' => TRUE]);
    $report_status = $request->report_status;
    $volunteer = node_load($nid);

    $data = [
      'reviewer_name' => $reviewer_name,
      'vol_name' => $volunteer->title,
      'vol_link' => $volunteer_link,
    ];

    // Background task was completed.
    if ($request->request_status == 1) {
      $mail_key = 'answer_report';

      // Report from CIA approved or conditional.
      if ($report_status == 1 || $report_status == 3) {
        $data['cia_answer'] = 'positive';
      }

      // Report from CIA not approved.
      if ($report_status == 2) {
        $data['cia_answer'] = 'negative';
      }
    }

    // Background task was expired.
    if ($request->request_status == 4) {
      $mail_key = 'expired_date';
    }

    return drupal_mail('novo_cia', $mail_key, $reviewer->mail, language_default(), $data);
  }
  return NULL;
}
