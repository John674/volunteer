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
    'roles' => array(),
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

  // Exported permission: 'create application content'.
  $permissions['create application content'] = array(
    'name' => 'create application content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create kids content'.
  $permissions['create kids content'] = array(
    'name' => 'create kids content',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create locations content'.
  $permissions['create locations content'] = array(
    'name' => 'create locations content',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create program content'.
  $permissions['create program content'] = array(
    'name' => 'create program content',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create staff content'.
  $permissions['create staff content'] = array(
    'name' => 'create staff content',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any application content'.
  $permissions['delete any application content'] = array(
    'name' => 'delete any application content',
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

  // Exported permission: 'delete any locations content'.
  $permissions['delete any locations content'] = array(
    'name' => 'delete any locations content',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any program content'.
  $permissions['delete any program content'] = array(
    'name' => 'delete any program content',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any staff content'.
  $permissions['delete any staff content'] = array(
    'name' => 'delete any staff content',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own application content'.
  $permissions['delete own application content'] = array(
    'name' => 'delete own application content',
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

  // Exported permission: 'delete own locations content'.
  $permissions['delete own locations content'] = array(
    'name' => 'delete own locations content',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own program content'.
  $permissions['delete own program content'] = array(
    'name' => 'delete own program content',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own staff content'.
  $permissions['delete own staff content'] = array(
    'name' => 'delete own staff content',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any application content'.
  $permissions['edit any application content'] = array(
    'name' => 'edit any application content',
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

  // Exported permission: 'edit any locations content'.
  $permissions['edit any locations content'] = array(
    'name' => 'edit any locations content',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any program content'.
  $permissions['edit any program content'] = array(
    'name' => 'edit any program content',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any staff content'.
  $permissions['edit any staff content'] = array(
    'name' => 'edit any staff content',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own application content'.
  $permissions['edit own application content'] = array(
    'name' => 'edit own application content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
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

  // Exported permission: 'edit own locations content'.
  $permissions['edit own locations content'] = array(
    'name' => 'edit own locations content',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own program content'.
  $permissions['edit own program content'] = array(
    'name' => 'edit own program content',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own staff content'.
  $permissions['edit own staff content'] = array(
    'name' => 'edit own staff content',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'publish any content'.
  $permissions['publish any content'] = array(
    'name' => 'publish any content',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish any content'.
  $permissions['unpublish any content'] = array(
    'name' => 'unpublish any content',
    'roles' => array(
      'siteadmin' => 'siteadmin',
    ),
    'module' => 'publishcontent',
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
