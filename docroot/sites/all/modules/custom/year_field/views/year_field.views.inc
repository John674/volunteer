<?php

/**
 * @file
 * Views integration for year_field.
 */

/**
 * Implements hook_field_views_data().
 */
function year_field_field_views_data($field) {
  $data = field_views_field_default_views_data($field);
  $data['field_data_' . $field['field_name']][$field['field_name'] . '_' . $field['type']]['filter']['handler'] = 'year_field_filters_handler_filter_year';
  return $data;
}
