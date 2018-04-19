<?php

/**
 * @file
 * Definition of novo_cia_handler_response_date.
 */

/**
 * Render a novo_cia_handler_response_date as a field.
 */
class novo_cia_handler_response_date extends views_handler_field_date {

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
      if(!empty(novo_cia_get_completed_pull_request($values->nid))){
          return parent::render($values);
      } else {
          return 'N/a';
      }

  }
}
