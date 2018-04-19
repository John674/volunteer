<?php
/**
 * @file
 * novo_account_feature.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function novo_account_feature_user_default_roles() {
  $roles = array();

  // Exported role: Applicant US citizen.
  $roles['Applicant US citizen'] = array(
    'name' => 'Applicant US citizen',
    'weight' => 5,
  );

  return $roles;
}
