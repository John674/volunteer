<?php

/**
 * @file
 * Definition of novo_applications_handler_app_active_status_filter.
 */

/**
 * Render a novo_applications_handler_app_active_status_on_date_filter as a filter.
 */
class novo_applications_handler_app_active_status_on_date_filter extends views_handler_filter_date {

  function query() {

    $on_date = $this->view->exposed_input['novo_application_active_status_on_date'] ?? NULL;
    if ($on_date) {
      $on_date = strtotime($on_date);
//      $where_last_date = novo_applications_get_last_date_serving_formula();
//      $where_last_date_formula = "(" . $where_last_date . " < " . $on_date . ")";
//      $this->query->add_where_expression($this->options['group'], "$where_last_date_formula");

      $where_first_date = novo_applications_get_first_date_serving_formula();
      $where_first_date_formula = "(" . $where_first_date . " < " . $on_date . ")";
      $this->query->add_where_expression($this->options['group'], "$where_first_date_formula");
    }
  }

  function op_between($field) {

  }

  function op_simple($field) {

  }

  function init(&$view, &$options) {
    parent::init($view, $options);
    drupal_add_library('system', 'ui.datepicker');
    drupal_add_js(drupal_get_path("module", "novo_applications") . "/js/novo_applications_handler_app_active_status_on_date_filter.js");
  }
}
