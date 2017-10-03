<?php

/**
 * @file
 * Definition of novo_cia_handler_status.
 */

/**
 * Render a novo_cia_handler_status as a field.
 */
class novo_cia_handler_status extends views_handler_field {

  /**
   * Override init function to add uid and homepage fields.
   */
  public function init(&$view, &$data) {
    parent::init($view, $data);
  }

  /**
   * Renders the field handler.
   */
  public function render($values) {
    $value = $this->get_value($values);
    $statuses = unserialize(NOVO_CIA_REQUEST_STATUSES);
    $status = (isset($statuses[$value])) ? $statuses[$value] : '';

    return $status;
  }

}
