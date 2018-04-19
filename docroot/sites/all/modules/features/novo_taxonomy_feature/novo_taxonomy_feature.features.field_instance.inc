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

  // Exported field_instance: 'taxonomy_term-canvassing_group-field_color'.
  $field_instances['taxonomy_term-canvassing_group-field_color'] = array(
    'bundle' => 'canvassing_group',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'color_field',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
          'field_multiple_limit_order' => 0,
          'height' => 16,
          'width' => 16,
        ),
        'type' => 'color_field_swatch',
        'weight' => 0,
      ),
      'pdf' => array(
        'label' => 'hidden',
        'module' => 'color_field',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
          'field_multiple_limit_order' => 0,
        ),
        'type' => 'color_field_default_formatter',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_color',
    'label' => 'Color',
    'required' => 0,
    'settings' => array(
      'allow_empty' => FALSE,
      'box_height' => 20,
      'box_width' => 115,
      'cell_height' => 10,
      'cell_margin' => 1,
      'cell_width' => 10,
      'columns' => 16,
      'default_colors' => '#FF0000,
#0044FE,
#009E00,
#FFF000,
#F38F36,
#96C551,
#64CED1,
#852723,
#84527E,
#AD7200',
      'palette' => '',
      'show_buttons' => FALSE,
      'show_input' => FALSE,
      'show_palette' => FALSE,
      'show_palette_only' => TRUE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'color_field',
      'settings' => array(),
      'type' => 'color_field_default_widget',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'taxonomy_term-small_group-field_color'.
  $field_instances['taxonomy_term-small_group-field_color'] = array(
    'bundle' => 'small_group',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'color_field',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
          'field_multiple_limit_order' => 0,
          'height' => 16,
          'width' => 16,
        ),
        'type' => 'color_field_swatch',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_color',
    'label' => 'Color',
    'required' => 0,
    'settings' => array(
      'allow_empty' => FALSE,
      'box_height' => 20,
      'box_width' => 115,
      'cell_height' => 10,
      'cell_margin' => 1,
      'cell_width' => 10,
      'columns' => 16,
      'default_colors' => '#FF0000,
#0044FE,
#009E00,
#FFF000',
      'palette' => '',
      'show_buttons' => FALSE,
      'show_input' => FALSE,
      'show_palette' => FALSE,
      'show_palette_only' => TRUE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'color_field',
      'settings' => array(),
      'type' => 'color_field_default_widget',
      'weight' => 2,
    ),
  );

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
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
          'field_multiple_limit_order' => 0,
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
  t('Color');
  t('Time');

  return $field_instances;
}
