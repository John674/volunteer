<?php
/**
 * @file
 * novo_roles_permissions_feature.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function novo_roles_permissions_feature_user_default_roles() {
  $roles = array();

  // Exported role: Reviewer.
  $roles['Reviewer'] = array(
    'name' => 'Reviewer',
    'weight' => 3,
  );

  return $roles;
}
