<?php

/**
 * @file
 * Applications dynamic fields.
 */

function novo_applications_attach_dynamic_fields(&$variables) {
  $variables['dynamic_fields'] = array();

  $dyn1 = array();
  $dyn1[] = array(
    "title" => t("Attendance Records"),
    //"content" => l(t("History attendancy dates (123)"), "<front>")
    "content" => '<span class="label label-danger">' . t('Coming soon') . '</span>'
  );

  $exposed_value = array("field_volunteer_mentor_name_target_id" => $variables['title'] . " (" . $variables['nid'] . ")");
  $mentored_field = novo_applications_build_view_dyn_field("Mentoring Records", "List Kids mentored", "list_kids_mentored", array(), $exposed_value);
  if (!empty($mentored_field)) {
    $dyn1[] = $mentored_field;
  }

  $dyn1[] = array(
    "title" => t("Program history"),
    //"content" => l(t("List Program Paticipated (2)"), "<front>")
    "content" => '<span class="label label-danger">' . t('Coming soon') . '</span>'
  );

  $variables['dynamic_fields'][] = $dyn1;

  $dyn2 = array();
  $dyn2[] = array(
    "title" => t("First date serving"),
    "content" => '<span class="label label-danger">' . t('Coming soon') . '</span>'
  );
  $dyn2[] = array(
    "title" => t("Last date serving"),
    "content" => '<span class="label label-danger">' . t('Coming soon') . '</span>'
  );
  $dyn2[] = array(
    "title" => t("Activity"),
    "content" => '<span class="label label-danger">' . t('Coming soon') . '</span>'
  );

  $variables['dynamic_fields'][] = $dyn2;

}

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
      "attributes" => array("target" => "_blank"),
      "query" => $exposed_value
    ))
  );

  return NULL;
}
