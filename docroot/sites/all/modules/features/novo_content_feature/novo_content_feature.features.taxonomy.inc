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
    'dismissal' => array(
      'name' => 'Dismissal',
      'machine_name' => 'dismissal',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
