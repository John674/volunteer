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

  // Exported menu link: main-menu_users:admin/people.
  $menu_links['main-menu_users:admin/people'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin/people',
    'router_path' => 'admin/people',
    'link_title' => 'Users',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_users:admin/people',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
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

  // Translatables
  // Included for use with string extractors like potx.
  t('Attendance');
  t('Enrollment');
  t('Locations');
  t('Users');

  return $menu_links;
}
