<?php
/**
 * @file
 * novo_menu_feature.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function novo_menu_feature_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_kids:kids.
  $menu_links['main-menu_kids:kids'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'kids',
    'router_path' => 'kids',
    'link_title' => 'Kids',
    'options' => array(
      'identifier' => 'main-menu_kids:kids',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_partners:partners.
  $menu_links['main-menu_partners:partners'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'partners',
    'router_path' => 'partners',
    'link_title' => 'Partners',
    'options' => array(
      'identifier' => 'main-menu_partners:partners',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: main-menu_programs:programs.
  $menu_links['main-menu_programs:programs'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'programs',
    'router_path' => 'programs',
    'link_title' => 'Programs',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_programs:programs',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_ref-request-tasks:ref-request-tasks.
  $menu_links['main-menu_ref-request-tasks:ref-request-tasks'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'ref-request-tasks',
    'router_path' => 'ref-request-tasks',
    'link_title' => 'Ref. request tasks',
    'options' => array(
      'identifier' => 'main-menu_ref-request-tasks:ref-request-tasks',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: main-menu_staff:staff.
  $menu_links['main-menu_staff:staff'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'staff',
    'router_path' => 'staff',
    'link_title' => 'Staff',
    'options' => array(
      'identifier' => 'main-menu_staff:staff',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_users:users.
  $menu_links['main-menu_users:users'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'users',
    'router_path' => 'users',
    'link_title' => 'Users',
    'options' => array(
      'identifier' => 'main-menu_users:users',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: main-menu_volunteers:volunteers.
  $menu_links['main-menu_volunteers:volunteers'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'volunteers',
    'router_path' => 'volunteers',
    'link_title' => 'Volunteers',
    'options' => array(
      'identifier' => 'main-menu_volunteers:volunteers',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-program-menu_attendance:attendance.
  $menu_links['menu-program-menu_attendance:attendance'] = array(
    'menu_name' => 'menu-program-menu',
    'link_path' => 'attendance',
    'router_path' => 'attendance',
    'link_title' => 'Attendance',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-program-menu_attendance:attendance',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-program-menu_enrollment:programs.
  $menu_links['menu-program-menu_enrollment:programs'] = array(
    'menu_name' => 'menu-program-menu',
    'link_path' => 'programs',
    'router_path' => 'programs',
    'link_title' => 'Enrollment',
    'options' => array(
      'identifier' => 'menu-program-menu_enrollment:programs',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-program-menu_locations:locations.
  $menu_links['menu-program-menu_locations:locations'] = array(
    'menu_name' => 'menu-program-menu',
    'link_path' => 'locations',
    'router_path' => 'locations',
    'link_title' => 'Locations',
    'options' => array(
      'identifier' => 'menu-program-menu_locations:locations',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-program-menu_mentoring:mentors.
  $menu_links['menu-program-menu_mentoring:mentors'] = array(
    'menu_name' => 'menu-program-menu',
    'link_path' => 'mentors',
    'router_path' => 'mentors',
    'link_title' => 'Mentoring',
    'options' => array(
      'identifier' => 'menu-program-menu_mentoring:mentors',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: user-menu_log-out:user/logout.
  $menu_links['user-menu_log-out:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'identifier' => 'user-menu_log-out:user/logout',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 0,
  );
  // Exported menu link: user-menu_user-account:user.
  $menu_links['user-menu_user-account:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'user-menu_user-account:user',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Attendance');
  t('Enrollment');
  t('Kids');
  t('Locations');
  t('Log out');
  t('Mentoring');
  t('Partners');
  t('Programs');
  t('Ref. request tasks');
  t('Staff');
  t('User account');
  t('Users');
  t('Volunteers');

  return $menu_links;
}
