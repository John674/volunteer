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
