<?php
/**
 * @file
 * novo_menu_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function novo_menu_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_menu_position_default_menu_positions().
 */
function novo_menu_feature_menu_position_default_menu_positions() {
  $items = array(
    'attendance_menu_active' => array(
      'admin_title' => 'Attendance menu active',
      'enabled' => 1,
      'conditions' => 'a:1:{s:5:"pages";a:1:{s:5:"pages";s:31:"attendance
node/add/attendance";}}',
      'menu_name' => 'menu-program-menu',
      'plid' => 1703,
      'mlid' => 1793,
      'weight' => 0,
      'machine_name' => 'attendance_menu_active',
    ),
    'class_menu_active' => array(
      'admin_title' => 'Class menu active',
      'enabled' => 1,
      'conditions' => 'a:1:{s:5:"pages";a:1:{s:5:"pages";s:21:"class
node/add/class";}}',
      'menu_name' => 'menu-program-menu',
      'plid' => 1788,
      'mlid' => 1797,
      'weight' => 0,
      'machine_name' => 'class_menu_active',
    ),
    'locations_menu_active' => array(
      'admin_title' => 'Locations menu active',
      'enabled' => 1,
      'conditions' => 'a:1:{s:5:"pages";a:1:{s:5:"pages";s:29:"locations
node/add/locations";}}',
      'menu_name' => 'menu-program-menu',
      'plid' => 394,
      'mlid' => 1795,
      'weight' => 0,
      'machine_name' => 'locations_menu_active',
    ),
    'mentors_menu_active' => array(
      'admin_title' => 'Mentors menu active',
      'enabled' => 1,
      'conditions' => 'a:1:{s:5:"pages";a:1:{s:5:"pages";s:25:"mentors
node/add/mentors";}}',
      'menu_name' => 'menu-program-menu',
      'plid' => 1693,
      'mlid' => 1796,
      'weight' => 0,
      'machine_name' => 'mentors_menu_active',
    ),
    'program_menu_active' => array(
      'admin_title' => 'Program menu active',
      'enabled' => 1,
      'conditions' => 'a:1:{s:5:"pages";a:1:{s:5:"pages";s:26:"programs
node/add/program";}}',
      'menu_name' => 'menu-program-menu',
      'plid' => 870,
      'mlid' => 1794,
      'weight' => 0,
      'machine_name' => 'program_menu_active',
    ),
    'programms_menu_active' => array(
      'admin_title' => 'Programms menu active',
      'enabled' => 1,
      'conditions' => 'a:1:{s:5:"pages";a:1:{s:5:"pages";s:140:"locations
programs
attendance
mentors
class
node/add/attendance
node/add/program
node/add/class
node/add/mentors
node/add/locations";}}',
      'menu_name' => 'main-menu',
      'plid' => 1695,
      'mlid' => 1798,
      'weight' => 0,
      'machine_name' => 'programms_menu_active',
    ),
  );
  return $items;
}
