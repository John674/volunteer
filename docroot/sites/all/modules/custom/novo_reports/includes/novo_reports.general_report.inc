<?php

/**
 * @file
 * Novo reports general functions.
 */

/**
 * General report: prerender view.
 */
function novo_reports_views_pre_render_report_general(&$view) {
  /*// kpr($view->result);
  //
  //  $tmp_result = [];
  //  foreach ($view->result as $key => $row) {
  //  $location = $row->field_field_program_location[0]['raw']['target_id'];
  //  $tmp_result[$location][] = $row;
  //  }
  //
  //  //kpr($tmp_result);
  //
  //  foreach ($tmp_result as $loc_id => $rows) {
  //  $total_row = $rows[0];
  //
  //    $total_row->nid = NULL;
  //    $total_row->node_field_data_field_attendance_program_name_nid = NULL;
  //    $total_row->field_field_attendance_program_name = [0 => ['raw' => ['access' => FALSE]]];
  //    $total_row->field_field_attendance_date = [0 => ['rendered' => ['#markup' => t('Totals:')]]];
  //
  //    $total_row->field_data_field_attendance_date_field_attendance_date_value = NULL;
  //    $total_row->node_created = NULL;
  //    $total_row->_field_data = NULL;
  //
  //
  //    $count_new = 0;
  //    $count_attendance = 0;
  //    foreach($rows as $k=> $v) {
  //      $count_new += $v->nid_3;
  //      $count_attendance += $v->nid_2;
  //    }
  //
  //    $total_row->nid_1 = ''; // Enrolled
  //    $total_row->nid_2 = $count_attendance; // Attendance
  //    $total_row->nid_3 = $count_new; // New
  //
  //    $tmp_result[$loc_id][] = $total_row;
  //  }
  //
  //
  //  $new_result = [];
  //  foreach ($tmp_result as $loc_id => $items) {
  //    foreach ($items as $item) {
  //      $new_result[] = $item;
  //    }
  //  }
  //
  //  $view->result = $new_result;

  //  $tmp_result = [];
  //  foreach ($view->result as $key => $row) {
  //    $tmp_result[$row->field_data_field_program_location_field_program_location_tar][] = $row;
  //  }
  //
  //  foreach ($tmp_result as $loc_id => $rows) {
  //    $count = 0;
  //    foreach ($rows as $key => $row) {
  //      $count += $row->field_data_field_program_kids_list_field_program_kids_list_v;
  //    }
  //    $total_row = clone $row;
  //    $total_row->nid = "total-label";
  //    $total_row->node_title = t("Total");
  //    $total_row->field_data_field_program_kids_list_field_program_kids_list_v = $count;
  //    $tmp_result[$loc_id][] = $total_row;
  //  }
  //
  //  $new_result = [];
  //  foreach ($tmp_result as $loc_id => $rows) {
  //  foreach ($rows as $key => $row) {
  //  $new_result[] = $row;
  //  }
  //  }
  //
  //  $view->result = $new_result;*/
}

/**
 * Render Enrollment report table.
 */
function novo_reports_general_report() {
  list($header, $rows) = novo_reports_genera_report_get_data();

  // $filters_form = drupal_get_form("novo_reports_enrollment_report_get_filters_form");
  // $output = drupal_render($filters_form);
  $output = "";
  $output .= theme('table', [
    'header' => $header,
    'rows' => $rows,
    'empty' => '<div class="novo-no-data-found">No data found.</div>',
  ]);

  return $output;
}

/**
 * Get report data for table.
 */
function novo_reports_genera_report_get_data() {
  $select = db_select("field_data_field_attendance_date", "att_date");
  // Att date.
  $select->addExpression("DATE_FORMAT(att_date.field_attendance_date_value, '%m/%d/%Y')", "att_date_value");

  // Location.
  $select->innerJoin("field_data_field_attendance_location", "att_loc", "att_date.entity_id = att_loc.entity_id");
  $select->innerJoin("node", "n_loc", "n_loc.nid = att_loc.field_attendance_location_target_id");
  $select->condition("n_loc.status", 1);
  $select->condition("n_loc.type", "locations");
  $select->addField("n_loc", "title", "location");

  // Join attendance node.
  $select->innerJoin("node", "n_att", "n_att.nid = att_date.entity_id");
  $select->condition("n_att.status", 1);
  $select->condition("n_att.type", "attendance");
  // Add enrolled.
  $enrolled_subquery = novo_reports_get_attendance_enrolled_formula("n_att.nid");
  $select->addExpression($enrolled_subquery, "enrolled");
  // Add Attendance.
  $attendance_subquery = novo_reports_get_attendance_formula("n_att.nid");
  $select->addExpression($attendance_subquery, "attendance");
  // Add New.
  $attendance_new_subquery = novo_reports_get_attendance_new_formula("n_att.nid");
  $select->addExpression($attendance_new_subquery, "new");

  // Join Programm.
  $select->innerJoin("field_data_field_attendance_program_name", "att_program", "att_date.entity_id = att_program.entity_id");
  $select->innerJoin("node", "n_program", "n_program.nid = att_program.field_attendance_program_name_target_id");
  $select->condition("n_program.status", 1);
  $select->condition("n_program.type", "program");
  $select->addField("n_program", "title", "program");

  // Add Mentoring Conversation.
  $ment_conv_subquery = novo_reports_get_mentoring_conversation_formula("n_att.nid");
  $select->addExpression($ment_conv_subquery, "mentoring_conversation");

  // Add Mentoring Salvation.
  $ment_salvation_subquery = novo_reports_get_mentoring_conversation_formula("n_att.nid", 'salvation');
  $select->addExpression($ment_salvation_subquery, "mentoring_salvation");

  // Add Mentoring Discipline.
  $ment_discipline_subquery = novo_reports_get_mentoring_conversation_formula("n_att.nid", 'discipline');
  $select->addExpression($ment_discipline_subquery, "mentoring_disciplined");

  // Add Mentoring Other.
  $ment_other_subquery = novo_reports_get_mentoring_conversation_formula("n_att.nid", 'other');
  $select->addExpression($ment_other_subquery, "mentoring_other");

  // Attendance total staff.
  $staff_number_subquery = novo_reports_get_staff_number_formula("n_att.nid");
  $select->addExpression($staff_number_subquery, "att_staff_list");

  // Attendance total volunteers.
  $volunteers_number_subquery = novo_reports_get_volunteers_number_formula("n_att.nid");
  $select->addExpression($volunteers_number_subquery, "volunteers");

  $select->orderBy("att_date_value");
  $result = $select->execute()->fetchAll();


  $new_result = [];
  $header = [
    'att_date_value' => t('Date'),
    'program' => 'Program name',
    'enrolled' => t('Enrolled'),
    'attendance' => t('Attendance'),
    'new' => t('New'),
    'programming_days' => t('Programming_days'),
    'mentoring_conversation' => t('Mentoring Conversation'),
    'mentoring_salvation' => t('Salvations'),
    'mentoring_disciplined' => t('Disciplined'),
    'mentoring_other' => t('Other'),
    'incident_reports' => t('Incident Reports'),
    'att_staff_list' => t('Paid Staff'),
    'volunteers' => t('Volunteers'),
  ];

  foreach ($result as $key => $item) {
    $new_result[$item->location][] = $item;
  }

  $rows = [];
  foreach ($new_result as $location => $data) {

    $num_rows = count($data);
    if (!empty($num_rows)) {
      // Location row.
      $rows[] = novo_reports_genera_report_get_location_row($location, $header);

      $attendance_percent_sum = 0;
      $sum = [];
      foreach ($data as $key => $item) {
        $attendance_percent = (!empty($item->enrolled)) ? round($item->attendance * 100 / $item->enrolled, 0) : 0;

        $row = [];
        foreach ($header as $h_key => $h_value) {
          $val = isset($item->{$h_key}) ? $item->{$h_key} : "";

          if ($h_key == "incident_reports") {
            $val = 0;
          }

          $sum[$h_key] = (isset($sum[$h_key])) ? $sum[$h_key] + intval($val) : intval($val);
          if ($h_key == "attendance") {
            $val .= " (" . $attendance_percent . "%)";
          }
          $row[] = $val;

        }
        $rows[] = $row;

        $attendance_percent_sum += $attendance_percent;
      }

      $totals = [
        'attendance' => $sum['attendance'],
        'new' => $sum['new'],
        'programming_days' => $num_rows,
        'mentoring_conversation' => $sum['mentoring_conversation'],
        'mentoring_salvation' => $sum['mentoring_salvation'],
        'mentoring_disciplined' => $sum['mentoring_disciplined'],
        'mentoring_other' => $sum['mentoring_other'],
        'incident_reports' => $sum['incident_reports'],
        'att_staff_list' => $sum['att_staff_list'],
        'volunteers' => $sum['volunteers'],
      ];
      $average = [
        'enrolled' => $sum['enrolled'] / $num_rows,
        'attendance' => ($attendance_percent_sum / $num_rows) . "%",
      ];

      // Total for location.
      $rows[] = novo_reports_genera_report_get_total_row(t("Totals"), "novo-reports-general-total-row", $header, $totals);
      // Average for location.
      $rows[] = novo_reports_genera_report_get_total_row(t("Average"), "novo-reports-general-average-row", $header, $average);
    }
  }


  return [$header, $rows];

}

/**
 * Get location row.
 */
function novo_reports_genera_report_get_location_row($location, $header) {

  $header_row = [
    [
      'data' => $location,
      'class' => ["novo-reports-general-header-row"],
      'colspan' => count($header),
    ],
  ];
  return $header_row;
}

/**
 * Get total row.
 */
function novo_reports_genera_report_get_total_row($title, $class, $header, $totals) {
  $row = [];
  foreach ($header as $h_key => $h_value) {
    $val = isset($totals[$h_key]) ? $totals[$h_key] : "";
    $row[] = [
      'data' => $val,
      'class' => [$class],
    ];
  }

  // Add title.
  $row[0] = [
    'data' => $title,
    'class' => [$class],
  ];

  return $row;
}
