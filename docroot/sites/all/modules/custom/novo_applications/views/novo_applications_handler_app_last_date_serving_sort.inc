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
    $formula = '(SELECT MAX(n_rev.timestamp)
    FROM {field_revision_field_attendance_volunteer_list} AS rev_av 
    INNER JOIN {node_revision} AS n_rev ON n_rev.nid = rev_av.entity_id AND n_rev.vid = rev_av.revision_id
    WHERE rev_av.field_attendance_volunteer_list_target_id = {' . $this->table_alias . '}.nid)';
    $this->query->add_orderby(NULL, $formula, $this->options['order'], 'subquery');


  }
}
