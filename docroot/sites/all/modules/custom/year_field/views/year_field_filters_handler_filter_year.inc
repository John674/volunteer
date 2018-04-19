<?php

/**
 * @file
 * Definition of year_field_filters_handler_filter_year.
 */

/**
 * Render a year_field_filters_handler_filter_year as a field.
 */
class year_field_filters_handler_filter_year extends views_handler_filter_in_operator {

  function get_value_options() {
    $field = field_info_field($this->definition['field_name']);
    $instances = field_read_instances(array('field_name' => array($this->definition['field_name'])));
    $instance = reset($instances);
    $value_list = year_field_available_options_list($instance);
    $this->value_options = $value_list;

    return $value_list;
  }
}
