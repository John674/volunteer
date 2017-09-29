<?php

/**
 * @file
 * Novo reports preprocess pdf body.
 */

/**
 * Preprocess pdf body for roster_report
 */
function novo_reports_preprocess_body_roster_report(&$vars) {
  // Dismissal conditional fields.
  foreach ($vars['themed_rows'] as $row_id => &$row) {
    if (isset($row['views_conditional']) && !empty($row['views_conditional'])) {
      $row['views_conditional'] = [
        "data" => $row['views_conditional'],
        "style" => "background:#DECDDB;",
      ];
    }

    if (isset($row['views_conditional_1']) && !empty($row['views_conditional_1'])) {
      $row['views_conditional_1'] = [
        "data" => $row['views_conditional_1'],
        "style" => "background:#EBD6B6;",
      ];
    }

    if (isset($row['views_conditional_2']) && !empty($row['views_conditional_2'])) {
      $raw_row = (isset($vars['rows'][$row_id])) ? $vars['rows'][$row_id] : NULL;
      $color = novo_reports_get_group_color_value($raw_row, "field_p_canvassing_group");

      $row['views_conditional_2'] = [
        "data" => $row['views_conditional_2'],
        "style" => "background:$color;",
      ];
    }
  }
}

/**
 * Preprocess pdf table header for canvassing_report
 */
function novo_reports_preprocess_theader_canvassing_report(&$vars) {
  $rows = $vars['rows'];
  $first_row = reset($rows);
  $color = novo_reports_get_group_color_value($first_row, "field_p_canvassing_group");
  $location = isset($first_row->field_field_program_location[0]['rendered']['#label']) ? $first_row->field_field_program_location[0]['rendered']['#label'] : "";

  $vars['header_row'] = '<thead>';
  if (!empty($location)) {
    $vars['header_row'] .= '<tr class="location-header"><th colspan="' . count($vars['header']) . '">' . $location . '</th></tr>';
  }
  $vars['header_row'] .= '<tr style="background: ' . $color . '">';

  $ts = tablesort_init($vars['header']);

  foreach ($vars['header'] as $cell) {
    $cell = tablesort_header($cell, $vars['header'], $ts);
    $vars['header_row'] .= _theme_table_cell($cell, TRUE);
  }

  $vars['header_row'] .= '</tr></thead>';
  $vars['header_row'] = preg_replace('/<\/?(a|span) ?.*?>/', '', $vars['header_row']);
}

/**
 * Preprocess pdf body for canvassing_report
 */
function novo_reports_preprocess_body_canvassing_report(&$vars) {
  // Dismissal conditional fields.
  $rows = $vars['rows'];
  $first_row = reset($rows);
  $color = novo_reports_get_group_color_value($first_row, "field_p_canvassing_group");
  $title = strip_tags($vars['title']);
  if ($title != "No group") {
    $title = t("%name group", ["%name" => $title]);
  }
  $vars['title'] = '<div style="color: ' . $color . '">' . $title . '</div>';
}

/**
 * Preprocess pdf body for report_nametag
 */
function novo_reports_preprocess_body_report_nametag(&$vars) {
  $rows = $vars['rows'];
  $vars['themed_rows'] = [];
  $vars['themed_rows'][0] = [];
  $c = 0;
  $col_num = 0;

  foreach ($rows as $row) {
    if ($c > 3) {
      $col_num++;
      $c = 0;
    }

    $no_photo_icon = (isset($row->field_field_p_photo_release[0]['raw']['value']) && !empty($row->field_field_p_photo_release[0]['raw']['value'])) ? FALSE : TRUE;
    $no_photo = (!$no_photo_icon) ? "" : theme("image", [
      "path" => drupal_get_path("module", "novo_reports") . "/images/icon_no_photo.png",
      "width" => 50,
      "height" => 50,
      "attributes" => ["style" => "margin-top:3px;"],
    ]);

    $canvassing_group_entity = (isset($row->field_field_p_canvassing_group[0]['raw']['entity'])) ? $row->field_field_p_canvassing_group[0]['raw']['entity'] : NULL;
    $canvassing_group_color = isset($canvassing_group_entity->field_color[LANGUAGE_NONE][0]['rgb']) ? $canvassing_group_entity->field_color[LANGUAGE_NONE][0]['rgb'] : NULL;

    $parent_guardian = isset($row->field_field_parent_guardian) ? $row->field_field_parent_guardian : [];
    $pickup_contacts = isset($row->field_field_p_kids_pickup_contacts) ? $row->field_field_p_kids_pickup_contacts : [];

    $parent_guardian_new = [];
    $pickup_contacts_new = [];
    $cc = 0;
    for ($i = 0; $i < 4; $i++) {
      if ($cc >= 4) {
        break;
      }

      if (isset($parent_guardian[$i])) {
        $parent_guardian_new[] = $parent_guardian[$i];
        $cc++;
      }

      if (isset($pickup_contacts[$i])) {
        $pickup_contacts_new[] = $pickup_contacts[$i];
        $cc++;
      }
    }

    $parent_guardian_values = [];
    foreach ($parent_guardian_new as $contact) {
      $parent_guardian_values[] = render($contact['rendered']);
    }

    $pickup_contacts_values = [];
    foreach ($pickup_contacts_new as $contact) {
      $pickup_contacts_values[] = render($contact['rendered']);
    }

    $data = [
      'first_name' => novo_reports_render_field_for_report($row, "field_field_first_name"),
      'last_name' => novo_reports_render_field_for_report($row, "field_field_last_name"),
      'canvassing_group' => novo_reports_render_field_for_report_color($row, "field_p_canvassing_group"),
      'canvassing_group_color' => $canvassing_group_color,
      'small_group' => novo_reports_render_field_for_report_color($row, "field_p_small_group"),
      'dismissal' => novo_reports_render_field_for_report($row, "field_field_p_dismissal"),
      'no_photo' => $no_photo,
      'location' => novo_reports_render_field_for_report($row, "field_field_program_location"),
      'food_allergies' => novo_reports_render_field_for_report($row, "field_field_food_allergies"),
      'address_1' => novo_reports_render_field_for_report($row, "field_field_address_1"),
      'address_2' => novo_reports_render_field_for_report($row, "field_field_address_2"),
      'apt' => novo_reports_render_field_for_report($row, "field_field_apt"),
      'city' => novo_reports_render_field_for_report($row, "field_field_city"),
      'state' => novo_reports_render_field_for_report($row, "field_field_state"),
      'zip' => novo_reports_render_field_for_report($row, "field_field_zip"),
      'parent' => implode("", $parent_guardian_values),
      'pickup_contacts' => implode("", $pickup_contacts_values),
    ];

    $rendered_kid_date = theme("novo_reports_nametag_kid", ['data' => $data]);
    $vars['themed_rows'][$col_num][] = $rendered_kid_date;
    $c++;
  }
}
