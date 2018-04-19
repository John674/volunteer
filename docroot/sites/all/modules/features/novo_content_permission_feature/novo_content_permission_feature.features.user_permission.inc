<?php
/**
 * @file
 * novo_content_permission_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function novo_content_permission_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_expired_email_sent'.
  $permissions['create field_expired_email_sent'] = array(
    'name' => 'create field_expired_email_sent',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_what_site_you_want'.
  $permissions['create field_what_site_you_want'] = array(
    'name' => 'create field_what_site_you_want',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_edu_level_years'.
  $permissions['edit field_edu_level_years'] = array(
    'name' => 'edit field_edu_level_years',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_expired_email_sent'.
  $permissions['edit field_expired_email_sent'] = array(
    'name' => 'edit field_expired_email_sent',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_what_site_you_want'.
  $permissions['edit field_what_site_you_want'] = array(
    'name' => 'edit field_what_site_you_want',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_expired_email_sent'.
  $permissions['edit own field_expired_email_sent'] = array(
    'name' => 'edit own field_expired_email_sent',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_what_site_you_want'.
  $permissions['edit own field_what_site_you_want'] = array(
    'name' => 'edit own field_what_site_you_want',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_app_user'.
  $permissions['view field_app_user'] = array(
    'name' => 'view field_app_user',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_edu_level_years'.
  $permissions['view field_edu_level_years'] = array(
    'name' => 'view field_edu_level_years',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_expired_email_sent'.
  $permissions['view field_expired_email_sent'] = array(
    'name' => 'view field_expired_email_sent',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_faq_a'.
  $permissions['view field_faq_a'] = array(
    'name' => 'view field_faq_a',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_what_site_you_want'.
  $permissions['view field_what_site_you_want'] = array(
    'name' => 'view field_what_site_you_want',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_edu_level_years'.
  $permissions['view own field_edu_level_years'] = array(
    'name' => 'view own field_edu_level_years',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_expired_email_sent'.
  $permissions['view own field_expired_email_sent'] = array(
    'name' => 'view own field_expired_email_sent',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_faq_a'.
  $permissions['view own field_faq_a'] = array(
    'name' => 'view own field_faq_a',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_what_site_you_want'.
  $permissions['view own field_what_site_you_want'] = array(
    'name' => 'view own field_what_site_you_want',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
