<?php

/**
 * @file
 * Definition of novo_applications_handler_app_active_status.
 */

/**
 * Render a novo_applications_handler_app_active_status as a field.
 */
class novo_applications_handler_app_active_status extends views_handler_field {

  /**
   * Override init function to add uid and homepage fields.
   */
  public function init(&$view, &$data) {
    parent::init($view, $data);
    $this->additional_fields['nid'] = 'nid';
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
    $nid = $this->get_value($values, "nid");

    list($activity, $min_date, $max_date) = novo_applications_get_app_active_status($nid);

    return $activity;
  }


  function click_sort($order) {
    $formula = "(IF ((SELECT ((UNIX_TIMESTAMP() - max(n_rev.timestamp)) / 60 / 60 / 24)
    FROM {field_revision_field_attendance_volunteer_list} AS rev_av 
    INNER JOIN {node_revision} AS n_rev ON (n_rev.nid = rev_av.entity_id AND n_rev.vid = rev_av.revision_id)
    WHERE rev_av.field_attendance_volunteer_list_target_id = {" . $this->table_alias . "}.nid) <= 6, 'Current', IF ((SELECT ((UNIX_TIMESTAMP() - max(n_rev.timestamp)) / 60 / 60 / 24)
    FROM {field_revision_field_attendance_volunteer_list} AS rev_av 
    INNER JOIN {node_revision} AS n_rev ON (n_rev.nid = rev_av.entity_id AND n_rev.vid = rev_av.revision_id)
    WHERE rev_av.field_attendance_volunteer_list_target_id = {" . $this->table_alias . "}.nid) <= 18, 'Lapsed', 'Inactive')))";

    $this->query->add_orderby(NULL, $formula, $order, 'subquery');
  }
}
