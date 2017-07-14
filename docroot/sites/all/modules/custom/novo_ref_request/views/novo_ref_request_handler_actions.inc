<?php

/**
 * @file
 * Definition of hr_promo_code_handler_status.
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
    $value = $this->get_value($values);
    $nid = $this->get_value($values, "nid");
    $output = "";

    if (!empty($nid)) {
      $buttons = novo_ref_request_prepare_action_buttons($nid);

      switch ($value) {
        case "0":
          // Not send - show "Send to referer button".
          $output = $buttons['send_link'];
          break;

        case "1":
          // Not responded - show phone number.
          // Edit.
          $phone = $this->get_value($values, "phone");
          $output = $phone . " " . $buttons['edit_link'];
          break;

        case "4":
          // Cancelled.
          $output = "";
          break;

        default:
          $output = $buttons['resend_link'] . " " . $buttons['pdf_link'] . " " . $buttons['edit_link'];
          break;
      }
    }

    return $output;
  }

}
