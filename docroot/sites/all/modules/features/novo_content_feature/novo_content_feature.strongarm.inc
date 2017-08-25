<?php
/**
 * @file
 * novo_content_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function novo_content_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_node_application';
  $strongarm->value = '1';
  $export['auto_entitylabel_node_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_node_attendance';
  $strongarm->value = '1';
  $export['auto_entitylabel_node_attendance'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_node_kids';
  $strongarm->value = '1';
  $export['auto_entitylabel_node_kids'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_node_mentors';
  $strongarm->value = '1';
  $export['auto_entitylabel_node_mentors'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_node_program';
  $strongarm->value = '1';
  $export['auto_entitylabel_node_program'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_node_reference_request';
  $strongarm->value = '1';
  $export['auto_entitylabel_node_reference_request'] = $strongarm;

  return $export;
}
