<?php

/**
 * @file
 * Applications dynamic fields.
 */

/**
 * Attach dynamic fields to application node.
 */
function novo_dynamic_fields_attach_dynamic_fields_applications(&$variables) {
  $exposed_value = array("title" => htmlspecialchars_decode($variables['title']));
  $output = "";

  $output .= theme("novo_dynamic_fields_row", novo_dynamic_fields_build_view_dyn_field("Attendance Records", "History attendance dates", "attendance_records_of_volunteer", array(), $exposed_value));
  $output .= theme("novo_dynamic_fields_row", novo_dynamic_fields_build_view_dyn_field("Mentoring Records", "List Kids mentored", "list_kids_mentored", array(), $exposed_value));
  $output .= theme("novo_dynamic_fields_row", novo_dynamic_fields_build_view_dyn_field("Program history", "List Program Paticipated", "programm_participated", array(), $exposed_value));

  $output .= "<hr>";

  // Get min/max volunter attached to attendance dates.
  list($activity, $min_date, $max_date) = novo_dynamic_fields_get_app_active_status($variables['nid']);

  $output .= theme("novo_dynamic_fields_row", array(
    "title" => t("First date serving"),
    "content" => (!empty($min_date) ? format_date($min_date, "custom", "m/d/Y") : " - ")
  ));

  $output .= theme("novo_dynamic_fields_row", array(
    "title" => t("Last date serving"),
    "content" => (!empty($max_date) ? format_date($max_date, "custom", "m/d/Y") : " - ")
  ));

  $output .= theme("novo_dynamic_fields_row", array(
    "title" => t("Activity"),
    "content" => $activity
  ));

  return $output;
}

/**
 * Get application Active status.
 */
function novo_dynamic_fields_get_app_active_status($nid) {
  $activity_subquery = novo_applications_get_app_active_status_formula();
  $max_date_subquery = novo_applications_get_last_date_serving_formula();
  $min_date_subquery = novo_applications_get_first_date_serving_formula();

  $query = db_select("node", "node");
  $query->addExpression($activity_subquery, "activity");
  $query->addExpression($max_date_subquery, "max_date");
  $query->addExpression($min_date_subquery, "min_date");
  $query->condition("node.nid", $nid);
  $result = $query->execute()->fetchObject();

  return array(
    t($result->activity),
    isset($result->min_date) ? $result->min_date : NULL,
    isset($result->max_date) ? $result->max_date : NULL
  );
}
