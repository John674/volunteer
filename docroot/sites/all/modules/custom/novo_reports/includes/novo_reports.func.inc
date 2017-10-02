<?php

/**
 * @file
 * Novo reports functions.
 */

/**
 * Reports list from views list.
 */
function novo_reports_list() {
  if ($cached = cache_get('novo_reports:list')) {
    return $cached->data;
  }

  $views = views_get_all_views();
  $links = [];

  foreach ($views as $view_name => $view) {
    if (strtolower($view->tag) == "report") {
      $path = isset($view->display['page']->display_options['path']) ? $view->display['page']->display_options['path'] : NULL;
      if ($path) {
        $title = $view->human_name;

        $export_links = [];
        foreach ($view->display as $key => $display) {
          if (in_array($display->display_plugin, [
            "views_data_export_pdf",
            "views_data_export",
          ])) {
            $export_path = isset($view->display[$key]->display_options['path']) ? $view->display[$key]->display_options['path'] : NULL;
            $style_plugin = isset($view->display[$key]->display_options['style_plugin']) ? $view->display[$key]->display_options['style_plugin'] : NULL;
            $display_plugin = isset($view->display[$key]->display_plugin) ? $view->display[$key]->display_plugin : NULL;

            switch ($display_plugin) {
              case "views_data_export_pdf":
                $image_path = drupal_get_path("module", "views_data_export_pdf") . "/images/pdf.png";
                $type = "pdf";
                break;

              case "views_data_export":
                switch ($style_plugin) {
                  case "views_data_export_xls":
                    $image_path = drupal_get_path("module", "views_data_export") . "/images/xls.png";
                    $type = "xls";
                    break;

                  default:
                    $type = "";
                    $image_path = "";
                }
                break;

              default:
                $type = "";
                $image_path = "";
            }

            if (!empty($export_path)) {
              $theme_pattern = [
                'views_data_export_feed_icon__' . $type,
                'views_data_export_feed_icon',
              ];

              $export_links[] = theme($theme_pattern,
                [
                  'image_path' => $image_path,
                  'url' => $export_path,
                  'text' => $view->human_name,
                  'title' => $view->human_name,
                  'style_plugin' => $style_plugin,
                ]
              );
            }
          }
        }

        if (!empty($export_links)) {
          $title .= " " . implode(" ", $export_links);
        }

        $links[] = [
          'href' => $path,
          'title' => $title,
          'html' => TRUE,
        ];
      }
    }
  }

  $links[] = [
    'href' => "enrollment-report",
    'title' => t("Enrollment report"),
    'html' => TRUE,
  ];

  $links = theme("links", [
    "links" => $links,
    "attributes" => ["class" => ["novo-reports-list-wrapper"]],
    "heading" => "",
  ]);
  cache_set('novo_reports:list', $links);

  return $links;
}

/**
 * Get all reports paths.
 */
function novo_reports_get_report_view_list_paths() {
  if ($cached = cache_get('novo_reports:get_report_view_list_paths')) {
    return $cached->data;
  }

  $views = views_get_all_views();
  $paths = [];
  foreach ($views as $view_name => $view) {
    if (strtolower($view->tag) == "report") {
      if (isset($view->display['page']->display_options['path'])) {
        $paths[] = $view->display['page']->display_options['path'];
      }
    }
  }
  cache_set('novo_reports:get_report_view_list_paths', $paths);

  return $paths;
}

/**
 * Get group color.
 */
function novo_reports_get_group_color_value($raw_row, $field) {
  $field_field = "field_$field";
  $color_entity = (isset($raw_row->{$field_field}[0]['raw']['entity'])) ? $raw_row->{$field_field}[0]['raw']['entity'] : NULL;
  $color = isset($color_entity->field_color[LANGUAGE_NONE][0]['rgb']) ? $color_entity->field_color[LANGUAGE_NONE][0]['rgb'] : NULL;
  return $color;
}
