<?php

/**
 * @file
 * Definition of novo_ref_request_handler_actions.
 */

/**
 * Render a novo_ref_request_handler_actions as a field.
 */
class novo_ref_request_handler_actions extends views_handler_field {

  /**
   * Override init function to add uid and homepage fields.
   */
  public function init(&$view, &$data) {
    parent::init($view, $data);
    $this->additional_fields['nid'] = 'nid';
    $this->additional_fields['phone'] = 'phone';
  }

  /**
   * Renders the field handler.
   */
  public function render($values) {
    $status = $this->get_value($values);
    $nid = $this->get_value($values, "nid");
    $phone = $this->get_value($values, "phone");
    $output = "";

    if (!empty($nid) && function_exists("novo_ref_request_render_action_buttons")) {
      $output = novo_ref_request_render_action_buttons($nid, $status, $phone);
    }

    return $output;
  }

}
