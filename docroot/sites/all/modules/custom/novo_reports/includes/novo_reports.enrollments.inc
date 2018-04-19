<?php

/**
 * @file
 * Novo reports enrollments table.
 */

/**
 * Render Enrollment report table.
 */
function novo_reports_enrollment_report() {
  list($header, $rows) = novo_reports_enrollment_report_get_data();

  $filters_form = drupal_get_form("novo_reports_enrollment_report_get_filters_form");
  $output = drupal_render($filters_form);

  $output .= theme('table', [
    'header' => array_merge([t('Location')], $header),
    'rows' => $rows,
    'empty' => '<div class="novo-no-data-found">No data found.</div>',
  ]);

  return $output;
}

/**
 * Build filters form.
 */
function novo_reports_enrollment_report_get_filters_form() {
  list($years, $years_default_value) = novo_reports_enrollment_report_get_year_filter_data();
  list($classes, $classes_default_value) = novo_reports_enrollment_report_get_class_filter_data();

  $form['novo_reports_filters'] = [
    '#type' => 'container',
    '#attributes' => [
      'class' => [],
    ],
    '#weight' => 1,
  ];

  $form['novo_reports_filters']['novo_reports_filter_years'] = [
    '#type' => 'select',
    '#title' => t('Filter by School Year'),
    '#options' => $years,
    '#default_value' => $years_default_value,
    '#attributes' => [
      'onChange' => 'this.form.submit();',
    ],
  ];

  $form['novo_reports_filters']['novo_reports_filter_class'] = [
    '#type' => 'select',
    '#title' => t('Filter by Class'),
    '#options' => $classes,
    '#default_value' => $classes_default_value,
    '#attributes' => [
      'onChange' => 'this.form.submit();',
    ],
  ];

  $form['novo_reports_filters']['submit'] = [
    '#type' => 'submit',
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
        'novo-report-enrollment-report-reset-btn',
      ],
    ],
  ];

  $form['#attributes']['class'][] = "novo-report-enrollment-report-form";
  $form['#submit'][] = 'novo_reports_enrollment_report_get_filters_form_submit';

  return $form;
}

/**
 * Novo reports enrollments form submit.
 */
function novo_reports_enrollment_report_get_filters_form_submit($form, &$form_state) {
  $filter_by_years = isset($form_state['values']['novo_reports_filter_years']) ? $form_state['values']['novo_reports_filter_years'] : -1;
  $filter_by_class = isset($form_state['values']['novo_reports_filter_class']) ? $form_state['values']['novo_reports_filter_class'] : -1;

  if (isset($form_state['triggering_element']['#btn_type']) && $form_state['triggering_element']['#btn_type'] == "reset") {
    $filter_by_years = -1;
    $filter_by_class = -1;
  }

  $form_state['redirect'] = [
    'enrollment-report',
    [
      'query' => [
        'filter_by_years' => $filter_by_years,
        'filter_by_class' => $filter_by_class,
      ],
    ],
  ];
}

/**
 * Get report data for table.
 */
function novo_reports_enrollment_report_get_data() {
  $params = drupal_get_query_parameters();
  $filter_year = isset($params['filter_by_years']) ? $params['filter_by_years'] : NULL;
  $filter_class = isset($params['filter_by_class']) ? $params['filter_by_class'] : NULL;

  $select = db_select('field_data_field_program_kids_list', 'p_kids_list');
  $select->addExpression("count(p_kids_list.entity_id)", "kids_number");

  $select->innerJoin("field_data_field_program_location", "p_locations", "p_locations.entity_id = p_kids_list.entity_id");
  $select->innerJoin("node", "n_location", "n_location.nid = p_locations.field_program_location_target_id");
  $select->condition("n_location.status", 1);
  $select->condition("n_location.type", "locations");
  $select->addField("n_location", "title", "location");

  $select->innerJoin("node", "n_program", "n_program.nid = p_kids_list.entity_id");
  $select->condition("n_program.status", 1);
  $select->condition("n_program.type", "program");
  $select->addField("n_program", "title", "program");

  // Exclude Kids moved.
  $select->leftJoin("field_data_field_p_kid_name", "p_kid_name", "p_kid_name.entity_id = p_kids_list.field_program_kids_list_value");
  $select->leftJoin("field_data_field_moved", "moved", "moved.entity_id = p_kid_name.field_p_kid_name_target_id");
  $select->condition("moved.field_moved_value", 1, '<>');

  $select->groupBy("p_kids_list.entity_id");
  $select->addTag('node_access');
  $select->orderBy("n_location.title");

  if (!empty($filter_year) && $filter_year != -1) {
    $select->innerJoin("field_data_field_program_year", "y", "y.entity_id = p_kids_list.entity_id");
    $select->condition("y.field_program_year_year", $filter_year);
  }

  if (!empty($filter_class) && $filter_class != -1) {
    $select->where("LOWER(TRIM(n_program.title)) = :filter_class", [":filter_class" => $filter_class]);
  }

  $result = $select->execute()->fetchAll();

  $totals = [];
  $new_result = [];
  $header = [];
  foreach ($result as $key => $item) {
    $p_name_key = strtolower(trim($item->program));
    $new_result[$item->location][$p_name_key] = (isset($new_result[$item->location][$p_name_key])) ? $new_result[$item->location][$p_name_key] + $item->kids_number : $item->kids_number;
    if (!isset($header[$p_name_key])) {
      $header[$p_name_key] = $item->program;
    }
  }

  $rows = [];
  foreach ($new_result as $location => $data) {
    foreach ($data as $p_name => $kids_n) {
      $p_name_key = strtolower(trim($p_name));
      $totals[$p_name_key] = (isset($totals[$p_name_key])) ? ($totals[$p_name_key] + $kids_n) : $kids_n;
    }

    $row = [$location];
    foreach ($header as $h_program) {
      $p_name_key = strtolower(trim($h_program));
      $row[] = ((isset($data[$p_name_key]))) ? $data[$p_name_key] : "";
    }
    $rows[] = $row;
  }

  // Add total row.
  if (!empty($rows)) {
    $row = [
      [
        'data' => t("Totals"),
        'class' => ["novo-reports-enrolment-total-row"],
      ],
    ];
    foreach ($header as $h_program) {
      $p_name_key = strtolower(trim($h_program));
      $val = (isset($totals[$p_name_key])) ? $totals[$p_name_key] : "";
      $row[] = [
        'data' => $val,
        'class' => ["novo-reports-enrolment-total-row"],
      ];
    }
    $rows[] = $row;
  }

  return [$header, $rows];
}

/**
 * Get enrollment class years.
 */
function novo_reports_enrollment_report_get_year_filter_data() {
  $default_value = -1;
  $params = drupal_get_query_parameters();

  $select = db_select("field_data_field_program_year", "y");
  $select->addField("y", "field_program_year_year", "year");
  $select->addField("y", "field_program_year_year", "year");
  $select->orderBy("y.field_program_year_year");
  $select->groupBy("y.field_program_year_year");
  $result = $select->execute()->fetchAllKeyed();

  $options = [
    -1 => t('Any'),
  ];

  foreach ($result as $year => $value) {
    $options[$year] = $value . " - " . ($value + 1);
  }

  $filter = isset($params['filter_by_years']) ? $params['filter_by_years'] : NULL;
  if (array_key_exists($filter, $options)) {
    $default_value = $filter;
  }

  return [$options, $default_value];
}

/**
 * Get enrollment classes (programs)
 */
function novo_reports_enrollment_report_get_class_filter_data() {
  $default_value = -1;
  $params = drupal_get_query_parameters();
  $filter_year = isset($params['filter_by_years']) ? $params['filter_by_years'] : NULL;

  $options = [
    -1 => t('Any'),
  ];

  $select = db_select("node", "n");
  $select->addExpression("LOWER(n.title)", "program_key");
  $select->addField("n", "title", "program");
  $select->innerJoin("field_data_field_program_year", "y", "y.entity_id=n.nid");
  if (!empty($filter_year) && $filter_year > 0) {
    $select->condition("y.field_program_year_year", $filter_year);
  }

  $select->condition("n.status", 1);
  $select->condition("n.type", "program");
  $result = $select->execute()->fetchAllKeyed(1, 0);

  $options = $options + $result;

  $filter = isset($params['filter_by_class']) ? $params['filter_by_class'] : NULL;
  if (array_key_exists($filter, $options)) {
    $default_value = $filter;
  }
  return [$options, $default_value];
}
