<?php

/**
 * @file
 * Novo reports general functions.
 */

/**
 * Render Enrollment report table.
 */
function novo_reports_general_report() {
  list($header, $rows) = novo_reports_general_report_get_data();

  $filters_form = drupal_get_form("novo_reports_general_report_get_filters_form");
  $output = drupal_render($filters_form);

  $output .= theme('table', [
    'header' => $header,
    'rows' => $rows,
    'empty' => '<div class="novo-no-data-found">No data found.</div>',
    'attributes' => ['class' => ['novo-reports-general-report-table']]
  ]);

  return $output;
}

/**
 * Get report data for table.
 */
function novo_reports_general_report_get_data() {
  $params = drupal_get_query_parameters();
  $start_time = isset($params['filter_by_start_date']) ? strtotime($params['filter_by_start_date']) : NULL;
  $end_time = isset($params['filter_by_end_date']) ? strtotime($params['filter_by_end_date']) : NULL;

  $select = db_select("field_data_field_attendance_date", "att_date");
  // Att date.
  $select->addExpression("DATE_FORMAT(att_date.field_attendance_date_value, '%m/%d/%Y')", "att_date_value");

  if (!empty($start_time)) {
    $select->where("UNIX_TIMESTAMP(att_date.field_attendance_date_value) >= :start_time", [":start_time" => $start_time]);
  }
  if (!empty($end_time)) {
    $select->where("UNIX_TIMESTAMP(att_date.field_attendance_date_value) <= :end_time", [":end_time" => $end_time]);
  }

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

  // Attendance active volunteers.
  $active_volunteers_number_subquery = novo_reports_get_active_volunteers_number_formula("n_att.nid");
  $select->addExpression($active_volunteers_number_subquery, "active_volunteers");

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
    'active_volunteers' => t('Active Volunteers'),
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
        $volunteers_percent = (!empty($item->active_volunteers)) ? round($item->volunteers * 100 / $item->active_volunteers, 0) : 0;

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
          if ($h_key == "volunteers") {
            $val .= " (" . $volunteers_percent . "%)";
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
        'enrolled' => round($sum['enrolled'] / $num_rows, 2),
        'attendance' => round($attendance_percent_sum / $num_rows, 2) . "%",
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
      'colspan' => count($header)
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

/**
 * Build filters form.
 */
function novo_reports_general_report_get_filters_form() {
  $params = drupal_get_query_parameters();
  $start_date_default = isset($params['filter_by_start_date']) ? $params['filter_by_start_date'] : NULL;
  $end_date_default = isset($params['filter_by_end_date']) ? $params['filter_by_end_date'] : NULL;

  $form['novo_reports_filters'] = [
    '#type' => 'container',
    '#attributes' => [
      'class' => [],
    ],
    '#weight' => 1,
  ];

  $form['novo_reports_filters']['novo_reports_filter_start_date'] = [
    '#type' => 'date_popup',
    '#date_format' => 'm/d/Y',
    '#title' => t('Filter by Start Date'),
    '#default_value' => $start_date_default,
    '#field_suffix' => '<label class="novo-reports-general-filter-date-icon input-group-addon btn" for="edit-novo-reports-filter-start-date-datepicker-popup-0"><span class="glyphicon glyphicon-calendar" aria-hidden="true"></span></label>',
    '#attributes' => [
      'onChange' => 'this.form.submit();',
    ],
  ];

  $form['novo_reports_filters']['novo_reports_filter_end_date'] = [
    '#type' => 'date_popup',
    '#date_format' => 'm/d/Y',
    '#title' => t('Filter by End Date'),
    '#default_value' => $end_date_default,
    '#field_suffix' => '<label class="novo-reports-general-filter-date-icon input-group-addon btn" for="edit-novo-reports-filter-end-date-datepicker-popup-0"><span class="glyphicon glyphicon-calendar" aria-hidden="true"></span></label>',
    '#attributes' => [
      'onChange' => 'this.form.submit();',
    ],
  ];

  $form['novo_reports_filters']['submit'] = [
    '#type' => 'submit',
    '#btn_type' => 'submit',
    '#value' => t('Apply'),
    '#attributes' => [
      'style' => ['display: none;'],
    ],
  ];

  $form['novo_reports_filters']['reset'] = [
    '#type' => 'submit',
    '#btn_type' => 'reset',
    '#value' => t('Reset'),
    '#validate' => [],
    '#attributes' => [
      'class' => [
        'btn',
        'btn-default',
        'novo-report-general-report-reset-btn',
      ],
    ],
  ];

  $form['#attributes']['class'][] = "novo-report-general-report-form";
  $form['#submit'][] = 'novo_reports_general_report_get_filters_form_submit';

  return $form;
}

/**
 * Novo reports enrollments form submit.
 */
function novo_reports_general_report_get_filters_form_submit($form, &$form_state) {
  $start_date = isset($form_state['values']['novo_reports_filter_start_date']) ? $form_state['values']['novo_reports_filter_start_date'] : NULL;
  $end_date = isset($form_state['values']['novo_reports_filter_end_date']) ? $form_state['values']['novo_reports_filter_end_date'] : NULL;

  if (isset($form_state['triggering_element']['#btn_type']) && $form_state['triggering_element']['#btn_type'] == "reset") {
    $start_date = $end_date = NULL;
  }

  $form_state['redirect'] = [
    'general-report',
    [
      'query' => [
        'filter_by_start_date' => $start_date,
        'filter_by_end_date' => $end_date,
      ],
    ],
  ];
}
