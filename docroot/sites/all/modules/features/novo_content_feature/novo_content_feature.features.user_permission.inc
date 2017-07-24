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

  // Exported permission: 'create field_app_status'.
  $permissions['create field_app_status'] = array(
    'name' => 'create field_app_status',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_app_user'.
  $permissions['create field_app_user'] = array(
    'name' => 'create field_app_user',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_completed'.
  $permissions['create field_completed'] = array(
    'name' => 'create field_completed',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_faq_a'.
  $permissions['create field_faq_a'] = array(
    'name' => 'create field_faq_a',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_gender'.
  $permissions['create field_gender'] = array(
    'name' => 'create field_gender',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_notes'.
  $permissions['create field_notes'] = array(
    'name' => 'create field_notes',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_reference_request_1'.
  $permissions['create field_reference_request_1'] = array(
    'name' => 'create field_reference_request_1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_reference_request_2'.
  $permissions['create field_reference_request_2'] = array(
    'name' => 'create field_reference_request_2',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_reference_request_church'.
  $permissions['create field_reference_request_church'] = array(
    'name' => 'create field_reference_request_church',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_reference_request_parents'.
  $permissions['create field_reference_request_parents'] = array(
    'name' => 'create field_reference_request_parents',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_reference_request_standby'.
  $permissions['create field_reference_request_standby'] = array(
    'name' => 'create field_reference_request_standby',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_texting'.
  $permissions['create field_texting'] = array(
    'name' => 'create field_texting',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_app_status'.
  $permissions['edit field_app_status'] = array(
    'name' => 'edit field_app_status',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_app_user'.
  $permissions['edit field_app_user'] = array(
    'name' => 'edit field_app_user',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_completed'.
  $permissions['edit field_completed'] = array(
    'name' => 'edit field_completed',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_faq_a'.
  $permissions['edit field_faq_a'] = array(
    'name' => 'edit field_faq_a',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_gender'.
  $permissions['edit field_gender'] = array(
    'name' => 'edit field_gender',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_notes'.
  $permissions['edit field_notes'] = array(
    'name' => 'edit field_notes',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_reference_request_1'.
  $permissions['edit field_reference_request_1'] = array(
    'name' => 'edit field_reference_request_1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_reference_request_2'.
  $permissions['edit field_reference_request_2'] = array(
    'name' => 'edit field_reference_request_2',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_reference_request_church'.
  $permissions['edit field_reference_request_church'] = array(
    'name' => 'edit field_reference_request_church',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_reference_request_parents'.
  $permissions['edit field_reference_request_parents'] = array(
    'name' => 'edit field_reference_request_parents',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_reference_request_standby'.
  $permissions['edit field_reference_request_standby'] = array(
    'name' => 'edit field_reference_request_standby',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_texting'.
  $permissions['edit field_texting'] = array(
    'name' => 'edit field_texting',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_app_status'.
  $permissions['edit own field_app_status'] = array(
    'name' => 'edit own field_app_status',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_app_user'.
  $permissions['edit own field_app_user'] = array(
    'name' => 'edit own field_app_user',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_completed'.
  $permissions['edit own field_completed'] = array(
    'name' => 'edit own field_completed',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_faq_a'.
  $permissions['edit own field_faq_a'] = array(
    'name' => 'edit own field_faq_a',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_gender'.
  $permissions['edit own field_gender'] = array(
    'name' => 'edit own field_gender',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_notes'.
  $permissions['edit own field_notes'] = array(
    'name' => 'edit own field_notes',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_reference_request_1'.
  $permissions['edit own field_reference_request_1'] = array(
    'name' => 'edit own field_reference_request_1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_reference_request_2'.
  $permissions['edit own field_reference_request_2'] = array(
    'name' => 'edit own field_reference_request_2',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_reference_request_church'.
  $permissions['edit own field_reference_request_church'] = array(
    'name' => 'edit own field_reference_request_church',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_reference_request_parents'.
  $permissions['edit own field_reference_request_parents'] = array(
    'name' => 'edit own field_reference_request_parents',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_reference_request_standby'.
  $permissions['edit own field_reference_request_standby'] = array(
    'name' => 'edit own field_reference_request_standby',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_texting'.
  $permissions['edit own field_texting'] = array(
    'name' => 'edit own field_texting',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_app_status'.
  $permissions['view field_app_status'] = array(
    'name' => 'view field_app_status',
    'roles' => array(
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

  // Exported permission: 'view field_completed'.
  $permissions['view field_completed'] = array(
    'name' => 'view field_completed',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
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

  // Exported permission: 'view field_gender'.
  $permissions['view field_gender'] = array(
    'name' => 'view field_gender',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_notes'.
  $permissions['view field_notes'] = array(
    'name' => 'view field_notes',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_reference_request_1'.
  $permissions['view field_reference_request_1'] = array(
    'name' => 'view field_reference_request_1',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_reference_request_2'.
  $permissions['view field_reference_request_2'] = array(
    'name' => 'view field_reference_request_2',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_reference_request_church'.
  $permissions['view field_reference_request_church'] = array(
    'name' => 'view field_reference_request_church',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_reference_request_parents'.
  $permissions['view field_reference_request_parents'] = array(
    'name' => 'view field_reference_request_parents',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_reference_request_standby'.
  $permissions['view field_reference_request_standby'] = array(
    'name' => 'view field_reference_request_standby',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_texting'.
  $permissions['view field_texting'] = array(
    'name' => 'view field_texting',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_app_status'.
  $permissions['view own field_app_status'] = array(
    'name' => 'view own field_app_status',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_app_user'.
  $permissions['view own field_app_user'] = array(
    'name' => 'view own field_app_user',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_completed'.
  $permissions['view own field_completed'] = array(
    'name' => 'view own field_completed',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_faq_a'.
  $permissions['view own field_faq_a'] = array(
    'name' => 'view own field_faq_a',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_gender'.
  $permissions['view own field_gender'] = array(
    'name' => 'view own field_gender',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_notes'.
  $permissions['view own field_notes'] = array(
    'name' => 'view own field_notes',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_reference_request_1'.
  $permissions['view own field_reference_request_1'] = array(
    'name' => 'view own field_reference_request_1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_reference_request_2'.
  $permissions['view own field_reference_request_2'] = array(
    'name' => 'view own field_reference_request_2',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_reference_request_church'.
  $permissions['view own field_reference_request_church'] = array(
    'name' => 'view own field_reference_request_church',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_reference_request_parents'.
  $permissions['view own field_reference_request_parents'] = array(
    'name' => 'view own field_reference_request_parents',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_reference_request_standby'.
  $permissions['view own field_reference_request_standby'] = array(
    'name' => 'view own field_reference_request_standby',
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
