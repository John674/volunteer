<?php

/**
 * @file
 * Definition of views_handler_filter_boolean_operator.
 */

/**
 * Simple filter to handle matching of boolean values
 *
 * Definition items:
 * - label: (REQUIRED) The label for the checkbox.
 * - type: For basic 'true false' types, an item can specify the following:
 *    - true-false: True/false (this is the default)
 *    - yes-no: Yes/No
 *    - on-off: On/Off
 *    - enabled-disabled: Enabled/Disabled
 * - accept null: Treat a NULL value as false.
 * - use equal: If you use this flag the query will use = 1 instead of <> 0.
 *   This might be helpful for performance reasons.
 *
 * @ingroup views_filter_handlers
 */
class novo_cia_handler_filter_by_last_active extends views_handler_filter_boolean_operator_string {

  function query() {
    $this->ensure_my_table();

    $table = $this->table;

    $formula = "((
       $table.request_type = 0 AND
       (
         SELECT count(*)
         FROM novo_cia_checks AS sub_ncc

         WHERE sub_ncc.application_nid = $table.application_nid AND sub_ncc.request_type = 1
       ) = $this->value  
      ) OR 
      ($table.request_type = 1))";

    $this->query->add_where_expression($this->options['group'], "$formula");
  }
}
