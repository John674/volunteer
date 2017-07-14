<?php

/**
 * @file
 * Definition of hr_promo_code_handler_status.
 */

/**
 * Render a novo_ref_request_handler_status as a field.
 */
class novo_ref_request_handler_user_name extends views_handler_field {

  /**
   * Override init function to add uid and homepage fields.
   */
  public function init(&$view, &$data) {
    parent::init($view, $data);
    $this->additional_fields['id'] = 'id';
  }

  /**
   * Renders the field handler.
   */
  public function render($values) {
    $value = $this->get_value($values);
    $statuses = unserialize(NOVO_REF_REQUEST_TASK_STATUSES);

    if (isset($statuses[$value])) {
      $status = (isset($statuses[$value])) ? $statuses[$value] : $value;
    }

    return $status;
  }
}
