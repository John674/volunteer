<?php
/**
 * @file
 * novo_taxonomy_feature.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function novo_taxonomy_feature_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'taxonomy_term-volunteer_interests_roles-field_vol_roles_time'.
  $field_instances['taxonomy_term-volunteer_interests_roles-field_vol_roles_time'] = array(
    'bundle' => 'volunteer_interests_roles',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_vol_roles_time',
    'label' => 'Time',
    'required' => 1,
    'settings' => array(
      'max' => 10,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Time');

  return $field_instances;
}
