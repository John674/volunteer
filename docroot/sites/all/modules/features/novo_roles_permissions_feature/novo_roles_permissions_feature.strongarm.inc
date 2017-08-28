<?php
/**
 * @file
 * novo_roles_permissions_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function novo_roles_permissions_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userprotect_role_protections';
  $strongarm->value = array(
    2 => array(
      'up_name' => 0,
      'up_mail' => 0,
      'up_pass' => 0,
      'up_status' => 0,
      'up_roles' => 0,
      'up_openid' => 0,
      'up_cancel' => 0,
      'up_edit' => 0,
    ),
    6 => array(
      'up_name' => 0,
      'up_mail' => 0,
      'up_pass' => 0,
      'up_status' => 0,
      'up_roles' => 0,
      'up_openid' => 0,
      'up_cancel' => 0,
      'up_edit' => 1,
    ),
    5 => array(
      'up_name' => 0,
      'up_mail' => 0,
      'up_pass' => 0,
      'up_status' => 0,
      'up_roles' => 0,
      'up_openid' => 0,
      'up_cancel' => 0,
      'up_edit' => 0,
    ),
    3 => array(
      'up_name' => 0,
      'up_mail' => 0,
      'up_pass' => 0,
      'up_status' => 0,
      'up_roles' => 0,
      'up_openid' => 0,
      'up_cancel' => 0,
      'up_edit' => 0,
    ),
  );
  $export['userprotect_role_protections'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_register';
  $strongarm->value = 1;
  $export['user_register'] = $strongarm;

  return $export;
}
