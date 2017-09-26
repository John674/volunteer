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
    $this->additional_fields['id'] = 'id';
  }

  /**
   * Renders the field handler.
   */
  public function render($values) {
    $last_request = novo_cia_get_last_success_request($values->nid);

    $output = !empty($last_request) ? novo_cia_render_action_buttons($values->nid) : novo_cia_render_action_buttons($values->nid, TRUE);

    return $output;
  }

}
