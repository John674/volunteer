<?php

/**
 * @file
 * Definition of novo_applications_handler_app_node_status.
 */

/**
 * Render a novo_applications_handler_app_node_status as a field.
 */
class novo_applications_handler_app_node_status extends views_handler_field {

  /**
   * Override init function to add uid and homepage fields.
   */
  public function init(&$view, &$data) {
    parent::init($view, $data);
    $this->additional_fields['nid'] = 'nid';
    $this->additional_fields['completed'] = array(
      'table' => 'field_data_field_completed',
      'field' => 'field_completed_value'
    );
    $this->additional_fields['app_status'] = array(
      'table' => 'field_data_field_app_status',
      'field' => 'field_app_status_tid'
    );
    $this->additional_fields['app_expired_date'] = array(
      'table' => 'field_data_field_expired_date',
      'field' => 'field_expired_date_value'
    );
  }

  /**
   * Called to add the field to a query.
   */
  function query() {
    parent::query();
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * Renders the field handler.
   */
  public function render($values) {
    $app_status_tid = $this->get_value($values, "app_status");
    $app_completed = $this->get_value($values, "completed");
    $app_expired_date = $this->get_value($values, "app_expired_date");
    list($app_status_output, $app_status) = novo_application_get_status($app_completed, $app_status_tid);

    if ($app_expired_date && $app_expired_date < REQUEST_TIME){
      $app_status_output = t("Expired :date", [":date" => format_date($app_expired_date, "custom", "m/d/Y")]);
    }

    return $app_status_output;
  }
}
