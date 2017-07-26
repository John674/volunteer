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
      'conditions' => 'YToxOntzOjU6InBhZ2VzIjthOjE6e3M6NToicGFnZXMiO3M6MTk6Im5vZGUvYWRkL2F0dGVuZGFuY2UiO319',
      'menu_name' => 'menu-program-menu',
      'plid' => 1703,
      'mlid' => 1793,
      'weight' => 0,
      'machine_name' => 'attendance_menu_active',
    ),
    'class_menu_active' => array(
      'admin_title' => 'Class menu active',
      'enabled' => 1,
      'conditions' => 'YToxOntzOjU6InBhZ2VzIjthOjE6e3M6NToicGFnZXMiO3M6MTQ6Im5vZGUvYWRkL2NsYXNzIjt9fQ==',
      'menu_name' => 'menu-program-menu',
      'plid' => 1788,
      'mlid' => 1797,
      'weight' => 0,
      'machine_name' => 'class_menu_active',
    ),
    'locations_menu_active' => array(
      'admin_title' => 'Locations menu active',
      'enabled' => 1,
      'conditions' => 'YToxOntzOjU6InBhZ2VzIjthOjE6e3M6NToicGFnZXMiO3M6MTg6Im5vZGUvYWRkL2xvY2F0aW9ucyI7fX0=',
      'menu_name' => 'menu-program-menu',
      'plid' => 394,
      'mlid' => 1795,
      'weight' => 0,
      'machine_name' => 'locations_menu_active',
    ),
    'mentors_menu_active' => array(
      'admin_title' => 'Mentors menu active',
      'enabled' => 1,
      'conditions' => 'YToxOntzOjU6InBhZ2VzIjthOjE6e3M6NToicGFnZXMiO3M6MTY6Im5vZGUvYWRkL21lbnRvcnMiO319',
      'menu_name' => 'menu-program-menu',
      'plid' => 1693,
      'mlid' => 1796,
      'weight' => 0,
      'machine_name' => 'mentors_menu_active',
    ),
    'program_menu_active' => array(
      'admin_title' => 'Program menu active',
      'enabled' => 1,
      'conditions' => 'YToxOntzOjU6InBhZ2VzIjthOjE6e3M6NToicGFnZXMiO3M6MTY6Im5vZGUvYWRkL3Byb2dyYW0iO319',
      'menu_name' => 'menu-program-menu',
      'plid' => 870,
      'mlid' => 1794,
      'weight' => 0,
      'machine_name' => 'program_menu_active',
    ),
    'programms_menu_active' => array(
      'admin_title' => 'Programms menu active',
      'enabled' => 1,
      'conditions' => 'YToxOntzOjU6InBhZ2VzIjthOjE6e3M6NToicGFnZXMiO3M6MTQwOiJsb2NhdGlvbnMNCnByb2dyYW1zDQphdHRlbmRhbmNlDQptZW50b3JzDQpjbGFzcw0Kbm9kZS9hZGQvYXR0ZW5kYW5jZQ0Kbm9kZS9hZGQvcHJvZ3JhbQ0Kbm9kZS9hZGQvY2xhc3MNCm5vZGUvYWRkL21lbnRvcnMNCm5vZGUvYWRkL2xvY2F0aW9ucyI7fX0=',
      'menu_name' => 'main-menu',
      'plid' => 1695,
      'mlid' => 1798,
      'weight' => 0,
      'machine_name' => 'programms_menu_active',
    ),
  );
  return $items;
}
