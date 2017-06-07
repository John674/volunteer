<?php
/**
 * @file
 * novo_roles_permissions_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function novo_roles_permissions_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create kids content'.
  $permissions['create kids content'] = array(
    'name' => 'create kids content',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any kids content'.
  $permissions['delete any kids content'] = array(
    'name' => 'delete any kids content',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own kids content'.
  $permissions['delete own kids content'] = array(
    'name' => 'delete own kids content',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any kids content'.
  $permissions['edit any kids content'] = array(
    'name' => 'edit any kids content',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own kids content'.
  $permissions['edit own kids content'] = array(
    'name' => 'edit own kids content',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(),
    'module' => 'system',
  );

  return $permissions;
}
