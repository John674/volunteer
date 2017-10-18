<?php

/**
 * @file
 * Definition of virtual field.
 */

/**
 * Render a virtual field.
 */
class novo_reports_handler_attendance_enrolled extends views_handler_field {

  var $field_alias = "attendance_enrolled";

  /**
   * Called to add the field to a query.
   */
  function query() {
    parent::query();
    $this->ensure_my_table();
    $formula = novo_reports_get_attendance_enrolled_formula();
    $this->field_alias = $this->query->add_field(NULL, $formula, $this->field_alias);

    $this->add_additional_fields();
  }

  /**
   * Renders the field handler.
   */
  public function render($values) {
    $value = $this->get_value($values);
    return $this->sanitize_value($value);
  }
}
