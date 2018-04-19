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
    $error = '';
    if (isset($values->novo_cia_checks_id) && !empty($values->novo_cia_checks_id)) {
      $request = novo_cia_get_request($values->novo_cia_checks_id);
      $error = $value == 2 ? $request->response : '';
    }

    $statuses = unserialize(NOVO_CIA_REQUEST_STATUSES);
    $status = (isset($statuses[$value])) ? $statuses[$value] : '';
    $status = '<span data-toggle="tooltip" data-placement="left" title="' . $error . '">' . $status . '</span>';
    return $status;
  }

}
