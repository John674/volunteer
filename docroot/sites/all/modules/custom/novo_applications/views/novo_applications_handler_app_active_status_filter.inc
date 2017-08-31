<?php

/**
 * @file
 * Definition of novo_applications_handler_app_active_status_filter.
 */

/**
 * Render a novo_applications_handler_app_active_status_filter as a filter.
 */
class novo_applications_handler_app_active_status_filter extends views_handler_filter_in_operator {
  function get_value_options() {

    $options = array(
      "Current" => t("Only Current (0 - 6 month)"),
      "Lapsed" => t("Only Lapsed (6 - 18 month)"),
      "Current-Lapsed" => t("Current (0 - 6 month) & Lapsed (6 - 18 month)"),
      "Inactive" => t("Inactive (18+ month)")
    );

    $this->value_options = $options;

    return $options;
  }

  function query() {
    $this->ensure_my_table();

    $formula = novo_applications_get_app_active_status_formula();

    $values = $this->value;
    foreach ($values as $key => $value) {
      $arr = explode("-", $value);
      if (!empty($arr)) {
        unset($values[$key]);
        $values = array_merge($values, $arr);
      }
    }

    $values = array_map(function ($str) {
      return sprintf("'%s'", $str);
    }, $values);


    $values = implode(",", $values);
    $this->query->add_where_expression($this->options['group'], "$formula $this->operator ($values)");
  }
}
