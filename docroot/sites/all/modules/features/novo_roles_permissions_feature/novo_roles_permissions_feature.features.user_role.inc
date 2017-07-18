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
    'weight' => 4,
  );

  // Exported role: siteadmin.
  $roles['siteadmin'] = array(
    'name' => 'siteadmin',
    'weight' => 2,
  );

  return $roles;
}
