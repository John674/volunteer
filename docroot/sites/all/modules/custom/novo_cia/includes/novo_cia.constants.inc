<?php

/**
 * @file
 * Novo cia constants.
 */

define("NOVO_CIA_CRON_PERIOD_SEARCH_REQUEST", 60 * 15);
define("NOVO_CIA_CRON_PERIOD_PULL_REPORT_REQUEST", 60 * 60);

define("NOVO_CIA_CRON_LAST_PULL_REPORT_REQUEST", 'novo_cia_last_pull_report_request');
define("NOVO_CIA_CRON_LAST_SEARCH_REQUEST", 'novo_cia_last_pull_report_request');

define('NOVO_CIA_REQUEST_STATUSES', serialize(
  array(
    0 => t('Pending'),
    1 => t('Completed'),
    2 => t('Error'),
    3 => t('Canceled'),
  )
));

define('NOVO_CIA_REQUEST_TYPES', serialize(
  array(
    0 => t('Search'),
    1 => t('Pull report'),
  )
));

define('NOVO_CIA_MAP_APPLICATION_DATA', serialize(
  array(
    'first_name' => 'field_first_name',
    'alias_first_name' => 'field_goes_by',
    'middle_initial' => 'field_middle_name',
    'last_name' => 'field_last_name',
    'alias_last_name' => NULL,
    'suffix' => NULL,
    'address' => 'field_address_1',
    'city' => 'field_city',
    'state' => 'field_state',
    'zip_code' => 'field_zip',
    'ref_number' => NULL,
    'dob' => 'field_dob',
    'ssn' => 'field_ssn',
  )
));

define('NOVO_CIA_REPORT_STATUSES', serialize(
  array(
    0 => t('Pending'),
    1 => t('Approved'),
    2 => t('Not Approved'),
    3 => t('Conditional'),
  )
));

define('NOVO_CIA_API_URLS', serialize(
  array(
    'search' => 'https://www.ciaresearch.com/system/center.nsf/(RequestBackgroundCheck)?OpenAgent',
    'pull_report' => 'https://www.ciaresearch.com/system/center.nsf/(QueryXMLResults)?OpenAgent',
    'get_report' => 'https://www.ciaresearch.com/system/center.nsf?Login&Username=@username&Password=@password&RedirectTo=/system/center.nsf/BackgroundFullReport?OpenForm%26TNUM=@tracking_number',
  )
));

define('NOVO_CIA_API_USERNAME', 'novo_cia_api_username');
define('NOVO_CIA_API_PASSWORD', 'novo_cia_api_password');
define('NOVO_CIA_API_CLIENT_NAME', 'novo_cia_api_client_name');
define('NOVO_CIA_API_BRANCH_NAME', 'novo_cia_api_branch_name');
define('NOVO_CIA_API_CLIENT_CONTACT', 'novo_cia_api_client_contact');
define('NOVO_CIA_API_CLIENT_CONTACT_EMAIL', 'novo_cia_api_client_contact_email');
define('NOVO_CIA_API_IS_TEST', 'novo_cia_api_is_test');

define('NOVO_CIA_RESPONSE_STATUS_ACCEPTED', 'ACCEPTED');
define('NOVO_CIA_RESPONSE_STATUS_REJECTED', 'REJECTED');
define('NOVO_CIA_RESPONSE_DATABASE_OFFLINE', 'Database Offline');
define('NOVO_CIA_ERROR_RESPONSE_MESSAGE_DUPLICATE', 'DUPLICATE REQUEST');
