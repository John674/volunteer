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
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'administer userprotect'.
  $permissions['administer userprotect'] = array(
    'name' => 'administer userprotect',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'userprotect',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'user',
  );

  // Exported permission: 'approve application'.
  $permissions['approve application'] = array(
    'name' => 'approve application',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'novo_applications',
  );

  // Exported permission: 'bypass entity print access'.
  $permissions['bypass entity print access'] = array(
    'name' => 'bypass entity print access',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'entity_print',
  );

  // Exported permission: 'change own e-mail'.
  $permissions['change own e-mail'] = array(
    'name' => 'change own e-mail',
    'roles' => array(
      'Reviewer' => 'Reviewer',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'userprotect',
  );

  // Exported permission: 'change own openid'.
  $permissions['change own openid'] = array(
    'name' => 'change own openid',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'userprotect',
  );

  // Exported permission: 'change own password'.
  $permissions['change own password'] = array(
    'name' => 'change own password',
    'roles' => array(
      'Reviewer' => 'Reviewer',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'userprotect',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create application content'.
  $permissions['create application content'] = array(
    'name' => 'create application content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create attendance content'.
  $permissions['create attendance content'] = array(
    'name' => 'create attendance content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create kids content'.
  $permissions['create kids content'] = array(
    'name' => 'create kids content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create locations content'.
  $permissions['create locations content'] = array(
    'name' => 'create locations content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create mentors content'.
  $permissions['create mentors content'] = array(
    'name' => 'create mentors content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create partner content'.
  $permissions['create partner content'] = array(
    'name' => 'create partner content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create program content'.
  $permissions['create program content'] = array(
    'name' => 'create program content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create reference_request content'.
  $permissions['create reference_request content'] = array(
    'name' => 'create reference_request content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create staff content'.
  $permissions['create staff content'] = array(
    'name' => 'create staff content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any application content'.
  $permissions['delete any application content'] = array(
    'name' => 'delete any application content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any attendance content'.
  $permissions['delete any attendance content'] = array(
    'name' => 'delete any attendance content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any kids content'.
  $permissions['delete any kids content'] = array(
    'name' => 'delete any kids content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any locations content'.
  $permissions['delete any locations content'] = array(
    'name' => 'delete any locations content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any mentors content'.
  $permissions['delete any mentors content'] = array(
    'name' => 'delete any mentors content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any partner content'.
  $permissions['delete any partner content'] = array(
    'name' => 'delete any partner content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any program content'.
  $permissions['delete any program content'] = array(
    'name' => 'delete any program content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any reference_request content'.
  $permissions['delete any reference_request content'] = array(
    'name' => 'delete any reference_request content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any staff content'.
  $permissions['delete any staff content'] = array(
    'name' => 'delete any staff content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own application content'.
  $permissions['delete own application content'] = array(
    'name' => 'delete own application content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own attendance content'.
  $permissions['delete own attendance content'] = array(
    'name' => 'delete own attendance content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own kids content'.
  $permissions['delete own kids content'] = array(
    'name' => 'delete own kids content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own locations content'.
  $permissions['delete own locations content'] = array(
    'name' => 'delete own locations content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own mentors content'.
  $permissions['delete own mentors content'] = array(
    'name' => 'delete own mentors content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own partner content'.
  $permissions['delete own partner content'] = array(
    'name' => 'delete own partner content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own program content'.
  $permissions['delete own program content'] = array(
    'name' => 'delete own program content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own reference_request content'.
  $permissions['delete own reference_request content'] = array(
    'name' => 'delete own reference_request content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own staff content'.
  $permissions['delete own staff content'] = array(
    'name' => 'delete own staff content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'disable auto complete'.
  $permissions['disable auto complete'] = array(
    'name' => 'disable auto complete',
    'roles' => array(),
    'module' => 'novo_applications',
  );

  // Exported permission: 'disable auto complete redirect'.
  $permissions['disable auto complete redirect'] = array(
    'name' => 'disable auto complete redirect',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'novo_applications',
  );

  // Exported permission: 'edit any application content'.
  $permissions['edit any application content'] = array(
    'name' => 'edit any application content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any attendance content'.
  $permissions['edit any attendance content'] = array(
    'name' => 'edit any attendance content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any kids content'.
  $permissions['edit any kids content'] = array(
    'name' => 'edit any kids content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any locations content'.
  $permissions['edit any locations content'] = array(
    'name' => 'edit any locations content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any mentors content'.
  $permissions['edit any mentors content'] = array(
    'name' => 'edit any mentors content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any partner content'.
  $permissions['edit any partner content'] = array(
    'name' => 'edit any partner content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any program content'.
  $permissions['edit any program content'] = array(
    'name' => 'edit any program content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any reference_request content'.
  $permissions['edit any reference_request content'] = array(
    'name' => 'edit any reference_request content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any staff content'.
  $permissions['edit any staff content'] = array(
    'name' => 'edit any staff content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit application with any status'.
  $permissions['edit application with any status'] = array(
    'name' => 'edit application with any status',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'novo_applications',
  );

  // Exported permission: 'edit own account'.
  $permissions['edit own account'] = array(
    'name' => 'edit own account',
    'roles' => array(
      'Reviewer' => 'Reviewer',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'userprotect',
  );

  // Exported permission: 'edit own application content'.
  $permissions['edit own application content'] = array(
    'name' => 'edit own application content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own attendance content'.
  $permissions['edit own attendance content'] = array(
    'name' => 'edit own attendance content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own kids content'.
  $permissions['edit own kids content'] = array(
    'name' => 'edit own kids content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own locations content'.
  $permissions['edit own locations content'] = array(
    'name' => 'edit own locations content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own mentors content'.
  $permissions['edit own mentors content'] = array(
    'name' => 'edit own mentors content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own partner content'.
  $permissions['edit own partner content'] = array(
    'name' => 'edit own partner content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own program content'.
  $permissions['edit own program content'] = array(
    'name' => 'edit own program content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own reference_request content'.
  $permissions['edit own reference_request content'] = array(
    'name' => 'edit own reference_request content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own staff content'.
  $permissions['edit own staff content'] = array(
    'name' => 'edit own staff content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit ref request with any status'.
  $permissions['edit ref request with any status'] = array(
    'name' => 'edit ref request with any status',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'novo_ref_request',
  );

  // Exported permission: 'novo account edit roles'.
  $permissions['novo account edit roles'] = array(
    'name' => 'novo account edit roles',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'novo_account',
  );

  // Exported permission: 'novo master userprotect check bypass'.
  $permissions['novo master userprotect check bypass'] = array(
    'name' => 'novo master userprotect check bypass',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'novo_master',
  );

  // Exported permission: 'publish any content'.
  $permissions['publish any content'] = array(
    'name' => 'publish any content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish any content'.
  $permissions['unpublish any content'] = array(
    'name' => 'unpublish any content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
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
