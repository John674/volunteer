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
  $dates = novo_application_get_serving_dates($variables['nid']);
  $activity = t("Inactive");

  if (isset($dates->max_date)) {
    $sec = $dates->max_date - REQUEST_TIME;
    $diff_days = $sec * 60 * 60 * 24;
    if ($diff_days <= 6) {
      $activity = t("Current");
    }
    elseif ($diff_days < 18) {
      $activity = t("Lapsed");
    }
  }

  $variables['dynamic_fields'][1][] = array(
    "title" => t("First date serving"),
    "content" => (isset($dates->min_date) ? format_date($dates->min_date, "short") : " - ")
  );
  $variables['dynamic_fields'][1][] = array(
    "title" => t("Last date serving"),
    "content" => (isset($dates->max_date) ? format_date($dates->max_date, "short") : " - ")
  );
  $variables['dynamic_fields'][1][] = array(
    "title" => t("Activity"),
    "content" => $activity
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

  return array(
    "title" => t("@label", array("@label" => $label)),
    "content" => l(t("@link_label (@count)", array(
      "@link_label" => $link_label,
      "@count" => $count
    )), $path, array(
      "query" => $exposed_value
    ))
  );

  return NULL;
}

/**
 * Get min/max serving dates.
 */
function novo_application_get_serving_dates($nid) {
  $subquery = db_select("field_revision_field_attendance_volunteer_list", "rev_av");
  $subquery->fields("rev_av", array("entity_id", "revision_id"));
  $subquery->innerJoin("node_revision", "n_rev", "n_rev.nid = rev_av.entity_id AND n_rev.vid = rev_av.revision_id");
  $subquery->fields("n_rev", array("timestamp"));
  $subquery->condition("rev_av.field_attendance_volunteer_list_target_id", $nid);

  $query = db_select($subquery, "sub");
  $query->addExpression("MIN(timestamp)", "min_date");
  $query->addExpression("MAX(timestamp)", "max_date");

  return $query->execute()->fetchObject();
}
