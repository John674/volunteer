<?php

/**
 * @file
 * Kids dynamic fields.
 */

/**
 * Dyn fields for kids.
 */
function novo_dynamic_fields_attach_dynamic_fields_kids($nid) {
  $output = "";

  $node = node_load($nid);
  $exposed_value = array("title" => htmlspecialchars_decode($node->title));

  $output .= theme("novo_dynamic_fields_row", array(
    "title" => t("Activity Record"),
    "content" => novo_dynamic_fields_get_kids_active_status($nid)
  ));

  $output .= theme("novo_dynamic_fields_row", novo_dynamic_fields_build_view_dyn_field("Attendance Records", "History attendancy dates", "attendance_records_of_kids", array(), $exposed_value));
  $output .= theme("novo_dynamic_fields_row", novo_dynamic_fields_build_view_dyn_field("Mentoring Records", "List staff mentors", "list_staff_mentors", array(), $exposed_value));
  $output .= theme("novo_dynamic_fields_row", novo_dynamic_fields_build_view_dyn_field("Program history", "List Program Participated", "list_programm_participated_kids", array(), $exposed_value));

  return $output;

}

/**
 * Get application Active status.
 */
function novo_dynamic_fields_get_kids_active_status($nid) {
  $activity_subquery = novo_dynamic_fields_get_kids_active_status_formula();

  $query = db_select("node", "node");
  $query->addExpression($activity_subquery, "activity");
  $query->condition("node.nid", $nid);
  $result = $query->execute()->fetchObject();

  return $result->activity;
}

/**
 * Select kid active app status for dyn fields.
 */
function novo_dynamic_fields_get_kids_active_status_formula() {
  $formula = "IF((SELECT ((UNIX_TIMESTAMP() - max(n_rev.timestamp)) / 60 / 60 / 24)
      FROM {field_revision_field_attendance_kids_list} AS kids
        INNER JOIN {node_revision} AS n_rev ON (n_rev.nid = kids.entity_id)
      WHERE n_rev.timestamp < UNIX_TIMESTAMP() AND kids.field_attendance_kids_list_target_id = {node}.nid) <= 6, 'Current',
     IF((SELECT ((UNIX_TIMESTAMP() - max(n_rev.timestamp)) / 60 / 60 / 24)
         FROM {field_revision_field_attendance_kids_list} AS kids
           INNER JOIN {node_revision} AS n_rev ON (n_rev.nid = kids.entity_id)
         WHERE n_rev.timestamp < UNIX_TIMESTAMP() AND kids.field_attendance_kids_list_target_id = {node}.nid) <= 18, 'Lapsed',
        'Inactive'))";
  return "(" . $formula . ")";
}
