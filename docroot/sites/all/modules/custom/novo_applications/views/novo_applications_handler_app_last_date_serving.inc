<?php

/**
 * @file
 * Definition of novo_applications_handler_app_node_status.
 */

/**
 * Render a novo_applications_handler_app_last_date_serving as a field.
 */
class novo_applications_handler_app_last_date_serving extends views_handler_field {

  /**
   * Called to add the field to a query.
   */
  function query() {
    parent::query();
    $this->ensure_my_table();
    $this->add_additional_fields();

    $formula = novo_applications_get_last_date_serving_formula();
    $this->query->add_field(NULL, $formula, "last_date_serving");

  }

  /**
   * Renders the field handler.
   */
  public function render($values) {
    return (isset($values->last_date_serving)) ? format_date($values->last_date_serving, "short") : " - ";
  }


  function click_sort($order) {
    $formula = novo_applications_get_last_date_serving_formula();
    $this->query->add_orderby(NULL, $formula, $order, 'subquery');
  }
}
