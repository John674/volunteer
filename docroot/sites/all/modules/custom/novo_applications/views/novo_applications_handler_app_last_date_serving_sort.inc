<?php

/**
 * @file
 * Definition of novo_applications_handler_app_last_date_serving_sort.
 */

/**
 * Render a novo_applications_handler_app_last_date_serving_sort as a field.
 */
class novo_applications_handler_app_last_date_serving_sort extends views_handler_sort {

  function query() {
    $this->ensure_my_table();
    $formula = novo_applications_get_last_date_serving_formula();
    $this->query->add_orderby(NULL, $formula, $this->options['order'], 'subquery');

  }
}
