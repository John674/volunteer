<?php
/**
 * @file
 * novo_menu_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function novo_menu_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_position_active_link_display';
  $strongarm->value = 'parent';
  $export['menu_position_active_link_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_application_pattern';
  $strongarm->value = 'application/[node:nid]';
  $export['pathauto_node_application_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_attendance_pattern';
  $strongarm->value = 'attendance/[node:nid]';
  $export['pathauto_node_attendance_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_class_pattern';
  $strongarm->value = 'class/[node:nid]';
  $export['pathauto_node_class_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_kids_pattern';
  $strongarm->value = 'kid/[node:nid]';
  $export['pathauto_node_kids_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_locations_pattern';
  $strongarm->value = 'location/[node:nid]';
  $export['pathauto_node_locations_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_mentors_pattern';
  $strongarm->value = 'mentor/[node:nid]';
  $export['pathauto_node_mentors_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_partner_pattern';
  $strongarm->value = 'partner/[node:nid]';
  $export['pathauto_node_partner_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_pattern';
  $strongarm->value = 'content/[node:title]';
  $export['pathauto_node_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_program_pattern';
  $strongarm->value = 'enrollment/[node:nid]';
  $export['pathauto_node_program_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_reference_request_pattern';
  $strongarm->value = 'ref-request/[node:nid]';
  $export['pathauto_node_reference_request_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_staff_pattern';
  $strongarm->value = 'staff/[node:nid]';
  $export['pathauto_node_staff_pattern'] = $strongarm;

  return $export;
}
