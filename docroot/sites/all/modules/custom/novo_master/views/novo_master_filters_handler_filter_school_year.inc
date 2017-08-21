<?php

/**
 * @file
 * Definition of novo_master_filters_handler_filter_school_year.
 */

/**
 * Render a novo_master_filters_handler_filter_school_year as a field.
 */
class novo_master_filters_handler_filter_school_year extends views_handler_filter_in_operator {

  function get_value_options() {
    $field = field_info_field($this->definition['field_name']);
    $instances = field_read_instances(array('field_name' => array($this->definition['field_name'])));
    $instance = reset($instances);
    $value_list = novo_master_available_options_list($instance);
    $this->value_options = $value_list;

    return $value_list;
  }
}
