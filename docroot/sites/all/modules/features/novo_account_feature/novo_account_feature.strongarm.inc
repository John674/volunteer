<?php
/**
 * @file
 * novo_account_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function novo_account_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_email_verification';
  $strongarm->value = FALSE;
  $export['user_email_verification'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_registrationpassword_registration';
  $strongarm->value = 'none';
  $export['user_registrationpassword_registration'] = $strongarm;

  return $export;
}
