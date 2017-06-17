<?php
/**
 * @file
 * novo_content_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function novo_content_feature_taxonomy_default_vocabularies() {
  return array(
    'ethnicity' => array(
      'name' => 'Ethnicity',
      'machine_name' => 'ethnicity',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'phone_type' => array(
      'name' => 'Phone type',
      'machine_name' => 'phone_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'weekdays' => array(
      'name' => 'Weekdays',
      'machine_name' => 'weekdays',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
