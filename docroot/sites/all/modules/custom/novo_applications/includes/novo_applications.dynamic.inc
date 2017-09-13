<?php

/**
 * @file
 * Applications dynamic fields.
 */

/**
 * Attach dynamic fields to node.
 */
function novo_applications_attach_dynamic_fields(&$variables) {
  $variables['dynamic_fields'] = array();
  $exposed_value = array("title" => $variables['title']);

  $attendance_field = novo_applications_build_view_dyn_field("Attendance Records", "History attendancy dates", "attendance_records_of_volunteer", array(), $exposed_value);
  if (!empty($attendance_field)) {
    $variables['dynamic_fields'][0][] = $attendance_field;
  }

  $mentored_field = novo_applications_build_view_dyn_field("Mentoring Records", "List Kids mentored", "list_kids_mentored", array(), $exposed_value);
  if (!empty($mentored_field)) {
    $variables['dynamic_fields'][0][] = $mentored_field;
  }

  $mentored_field = novo_applications_build_view_dyn_field("Program history", "List Program Paticipated", "programm_participated", array(), $exposed_value);
  if (!empty($mentored_field)) {
    $variables['dynamic_fields'][0][] = $mentored_field;
  }

  // GEt min/max volunter attached to attendance dates.
  list($activity, $min_date, $max_date) = novo_applications_get_app_active_status($variables['nid']);

  $variables['dynamic_fields'][1][] = array(
    "title" => t("First date serving"),
    "content" => (!empty($min_date) ? format_date($min_date, "short") : " - ")
  );
  $variables['dynamic_fields'][1][] = array(
    "title" => t("Last date serving"),
    "content" => (!empty($max_date) ? format_date($max_date, "short") : " - ")
  );
  $variables['dynamic_fields'][1][] = array(
    "title" => t("Activity"),
    "content" => $activity
  );

}

/**
 * Get application Active status.
 */
function novo_applications_get_app_active_status($nid) {
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

/**
 * Build view for dynamic field.
 */
function novo_applications_build_view_dyn_field($label, $link_label, $view_machine_name, $args = array(), $exposed_value = array(), $display = "page") {
  $view = views_get_view($view_machine_name);
  if ($view) {
    $path = isset($view->display[$display]->display_options['path']) ? $view->display[$display]->display_options['path'] : NULL;
    if (!empty($args)) {
      $view->set_arguments($args);
    }

    if ($exposed_value) {
      foreach ($exposed_value as $key => $value) {
        $view->exposed_input[$key] = $value;
      }
    }

    $view->execute($display);
    $count = (isset($view->total_rows)) ? $view->total_rows : 0;
  }

  if (!empty($count)) {
    return array(
      "title" => t("@label", array("@label" => $label)),
      "content" => l(t("@link_label (@count)", array(
        "@link_label" => $link_label,
        "@count" => $count
      )), $path, array(
        "query" => $exposed_value
      ))
    );
  }
  else {
    return array(
      "title" => t("@label", array("@label" => $label)),
      "content" => t("@link_label (@count)", array(
        "@link_label" => $link_label,
        "@count" => $count
      ))
    );
  }
}
