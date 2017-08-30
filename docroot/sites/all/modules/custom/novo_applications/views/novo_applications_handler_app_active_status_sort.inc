<?php

/**
 * @file
 * Definition of novo_applications_handler_app_active_status_sort.
 */

/**
 * Render a novo_applications_handler_app_active_status_sort as a field.
 */
class novo_applications_handler_app_active_status_sort extends views_handler_sort {

  function query() {
    $this->ensure_my_table();
    $formula = "(IF ((SELECT ((UNIX_TIMESTAMP() - max(n_rev.timestamp)) / 60 / 60 / 24)
    FROM {field_revision_field_attendance_volunteer_list} AS rev_av 
    INNER JOIN {node_revision} AS n_rev ON (n_rev.nid = rev_av.entity_id AND n_rev.vid = rev_av.revision_id)
    WHERE rev_av.field_attendance_volunteer_list_target_id = {" . $this->table_alias . "}.nid) <= 6, 'Current', IF ((SELECT ((UNIX_TIMESTAMP() - max(n_rev.timestamp)) / 60 / 60 / 24)
    FROM {field_revision_field_attendance_volunteer_list} AS rev_av 
    INNER JOIN {node_revision} AS n_rev ON (n_rev.nid = rev_av.entity_id AND n_rev.vid = rev_av.revision_id)
    WHERE rev_av.field_attendance_volunteer_list_target_id = {" . $this->table_alias . "}.nid) <= 18, 'Lapsed', 'Inactive')))";

    $this->query->add_orderby(NULL, $formula, $this->options['order'], 'subquery');

  }
}
