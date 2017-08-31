<?php

/**
 * @file
 * Definition of novo_applications_handler_app_active_status.
 */

/**
 * Render a novo_applications_handler_app_active_status as a field.
 */
class novo_applications_handler_app_active_status extends views_handler_field {
  /**
   * Called to add the field to a query.
   */
  function query() {
    parent::query();
    $this->ensure_my_table();
    $this->add_additional_fields();
    $formula = novo_applications_get_app_active_status_formula();
    $this->query->add_field(NULL, $formula, "active_status");
  }

  /**
   * Renders the field handler.
   */
  public function render($values) {
    $active_status = (isset($values->active_status)) ? $values->active_status : " - ";

    return $active_status;
  }


  function click_sort($order) {
    $formula = novo_applications_get_app_active_status_formula();
    $this->query->add_orderby(NULL, $formula, $order, 'subquery');
  }
}
