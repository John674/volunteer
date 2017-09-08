<?php

/**
 * @file
 * Novo reports novo_reports.handlers_func.
 */


/**
 * Select .
 */
function novo_reports_get_attendance_enrolled_formula() {
  $formula = "(SELECT COUNT(*)
    FROM {field_data_field_program_kids_list} AS p_kids_list
    INNER JOIN {field_data_field_attendance_program_name} AS a_p_name ON (a_p_name.field_attendance_program_name_target_id = p_kids_list.entity_id)
    WHERE a_p_name.entity_id = {node}.nid)";
  return $formula;
}

function novo_reports_get_attendance_new_formula() {
  $formula = "SELECT (
  (
    SELECT COUNT(*)
      FROM {field_data_field_program_kids_list} AS p_kids_list
      WHERE p_kids_list.entity_id = p_location.entity_id)
    -
    (
      SELECT COUNT(DISTINCT p_kids_list.entity_id)
        FROM {field_data_field_attendance_date} AS sub_a_date
          INNER JOIN {field_data_field_attendance_program_name} AS sub_p_name ON sub_p_name.entity_id = sub_a_date.entity_id
          INNER JOIN {field_data_field_program_kids_list} AS p_kids_list ON p_kids_list.entity_id = sub_p_name.field_attendance_program_name_target_id
          INNER JOIN {field_data_field_program_location} AS sub_p_location ON sub_p_location.entity_id = sub_p_name.field_attendance_program_name_target_id
        WHERE
          sub_a_date.field_attendance_date_value < a_date.field_attendance_date_value AND
          sub_p_location.field_program_location_target_id = p_location.field_program_location_target_id
        ORDER BY sub_a_date.field_attendance_date_value DESC
        LIMIT 1
    )
  ) as new

  FROM {field_data_field_attendance_date} AS a_date
    INNER JOIN {field_data_field_attendance_program_name} AS p_name ON p_name.entity_id = a_date.entity_id
    INNER JOIN {field_data_field_program_location} AS p_location ON p_location.entity_id = p_name.field_attendance_program_name_target_id
  WHERE a_date.entity_id = {node}.nid
 ";

  return "(" . $formula . ")";
}

function novo_reports_get_attendance_formula() {
  $formula = "(SELECT COUNT(*)
    FROM {field_data_field_attendance_kids_list} AS a_kids_list
    WHERE a_kids_list.entity_id = {node}.nid)";
  return $formula;
}