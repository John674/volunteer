<?php
/**
 * @file
 * novo_taxonomy_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function novo_taxonomy_feature_taxonomy_default_vocabularies() {
  return array(
    'application_site' => array(
      'name' => 'Application site',
      'machine_name' => 'application_site',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'church' => array(
      'name' => 'Church',
      'machine_name' => 'church',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'color_preference' => array(
      'name' => 'Color Preference',
      'machine_name' => 'color_preference',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'gender' => array(
      'name' => 'Gender',
      'machine_name' => 'gender',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'grade' => array(
      'name' => 'Grade',
      'machine_name' => 'grade',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'school' => array(
      'name' => 'School',
      'machine_name' => 'school',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'states' => array(
      'name' => 'States',
      'machine_name' => 'states',
      'description' => 'USA states list',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    't_shirt_size' => array(
      'name' => 'T-shirt Size',
      'machine_name' => 't_shirt_size',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'volunteer_interests_roles' => array(
      'name' => 'Volunteer interests / roles',
      'machine_name' => 'volunteer_interests_roles',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
