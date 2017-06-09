<?php
/**
 * @file
 * novo_taxonomy_feature.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function novo_taxonomy_feature_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_vol_roles_time'.
  $field_bases['field_vol_roles_time'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_vol_roles_time',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  return $field_bases;
}
