<?php

/**
 * @file
 * Definition of novo_ref_request_handler_actions.
 */

/**
 * Render a novo_cia_handler_actions as a field.
 */
class novo_cia_handler_actions extends views_handler_field {

  /**
   * Override init function to add uid and homepage fields.
   */
  public function init(&$view, &$data) {
    parent::init($view, $data);
  }

  /**
   * Renders the field handler.
   */
  public function render($request) {
    $last_success_request = novo_cia_get_last_success_request($request->nid);

    $output = !empty($last_success_request) ? novo_cia_render_action_buttons($request->nid) : '';

    return $output;
  }

}
