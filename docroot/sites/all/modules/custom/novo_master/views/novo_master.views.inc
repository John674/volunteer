<?php

/**
 * @file
 * Views integration for field collection fields.
 */

/**
 * Implements hook_field_views_data().
 *
 */
function novo_master_field_views_data($field) {
  $data = field_views_field_default_views_data($field);
  $data['field_data_' . $field['field_name']][$field['field_name'] . '_' . $field['type']]['filter']['handler'] = 'novo_master_filters_handler_filter_school_year';
  return $data;
}
