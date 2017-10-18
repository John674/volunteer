<?php

/**
 * @file
 * Definition of novo_applications_handler_app_active_status.
 */

/**
 * Render a novo_applications_handler_app_active_status as a field.
 */
class novo_applications_handler_app_active_status extends views_handler_field {

  var $field_alias = "active_status";

  /**
   * Called to add the field to a query.
   */
  function query() {
    parent::query();
    $this->ensure_my_table();
    $formula = novo_applications_get_app_active_status_formula();
    $this->field_alias = $this->query->add_field(NULL, $formula, $this->field_alias);
    $this->add_additional_fields();
  }

  function click_sort($order) {
    $formula = novo_applications_get_app_active_status_formula();
    $this->query->add_orderby(NULL, $formula, $order, 'subquery');
  }
}
