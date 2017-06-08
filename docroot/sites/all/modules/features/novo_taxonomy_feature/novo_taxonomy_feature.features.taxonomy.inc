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
    'church' => array(
      'name' => 'Church',
      'machine_name' => 'church',
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
  );
}
