<?php

/**
 * @file
 * Definition of novo_applications_handler_app_node_status.
 */

/**
 * Render a novo_applications_handler_app_last_date_serving as a field.
 */
class novo_applications_handler_app_last_date_serving extends views_handler_field {

  var $field_alias = "last_date_serving";

  /**
   * Called to add the field to a query.
   */
  function query() {
    parent::query();
    $this->ensure_my_table();

    $formula = novo_applications_get_last_date_serving_formula();
    $this->field_alias = $this->query->add_field(NULL, $formula, $this->field_alias);
    $this->add_additional_fields();
  }

  /**
   * Renders the field handler.
   */
  public function render($values) {
    $value = $this->get_value($values);
    $time = $this->sanitize_value($value);
    return (!empty($time)) ? format_date($time, "short") : " - ";
  }


  function click_sort($order) {
    $formula = novo_applications_get_last_date_serving_formula();
    $this->query->add_orderby(NULL, $formula, $order, 'subquery');
  }
}
