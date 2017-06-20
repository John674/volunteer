<?php
/**
 * @file
 * novo_content_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function novo_content_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_notes'.
  $permissions['create field_notes'] = array(
    'name' => 'create field_notes',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_texting'.
  $permissions['create field_texting'] = array(
    'name' => 'create field_texting',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_notes'.
  $permissions['edit field_notes'] = array(
    'name' => 'edit field_notes',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_texting'.
  $permissions['edit field_texting'] = array(
    'name' => 'edit field_texting',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_notes'.
  $permissions['edit own field_notes'] = array(
    'name' => 'edit own field_notes',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_texting'.
  $permissions['edit own field_texting'] = array(
    'name' => 'edit own field_texting',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_notes'.
  $permissions['view field_notes'] = array(
    'name' => 'view field_notes',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_texting'.
  $permissions['view field_texting'] = array(
    'name' => 'view field_texting',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_notes'.
  $permissions['view own field_notes'] = array(
    'name' => 'view own field_notes',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_texting'.
  $permissions['view own field_texting'] = array(
    'name' => 'view own field_texting',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  return $permissions;
}
