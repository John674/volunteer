<?php

/**
 * @file
 * Novo reports novo_reports.handlers_func.
 */

/**
 * Get attendance enrolled formula.
 */
function novo_reports_get_attendance_enrolled_formula($sub_query_nid = NULL) {
  // SELECT KIDS Enrolled before attendance date (23:59).
  // Select last revision on this date.
  $sub_query_nid_value = (!empty($sub_query_nid)) ? $sub_query_nid : "{node}.nid";

  $formula = "SELECT count(*) AS kids_enrolled
FROM {field_data_field_attendance_program_name} AS a_p_name
  INNER JOIN {node_revision} AS n_rev ON (n_rev.nid = a_p_name.field_attendance_program_name_target_id)
  INNER JOIN {field_revision_field_program_kids_list} AS kids ON (kids.revision_id = n_rev.vid)
  INNER JOIN {field_data_field_attendance_date} AS att_date ON (att_date.entity_id = a_p_name.entity_id)

WHERE a_p_name.entity_id = $sub_query_nid_value 
  AND (n_rev.timestamp < (UNIX_TIMESTAMP(att_date.field_attendance_date_value) + 60*60*24 -1))

GROUP BY n_rev.vid
ORDER BY n_rev.timestamp DESC
LIMIT 1";

  return "IF ((" . $formula . ") IS NULL, 0, (" . $formula . "))";
}


/**
 * Get attendance formula.
 */
function novo_reports_get_attendance_formula() {
  $formula = "SELECT COUNT(*)
    FROM {field_data_field_attendance_kids_list} AS a_kids_list
    WHERE a_kids_list.entity_id = {node}.nid";
  return "(" . $formula . ")";
}

/**
 * Get attendance NEW enrolled formula.
 */
function novo_reports_get_attendance_new_formula() {
  // Get enrolled kids for current attendance date.
  $cur = novo_reports_get_attendance_enrolled_formula();

  // Get prev attendance node for current programm.
  $sub = "SELECT a_p_name2.entity_id AS prev_entity_id

                            FROM field_data_field_attendance_program_name AS a_p_name
                              INNER JOIN field_data_field_attendance_date AS att_date ON (att_date.entity_id = a_p_name.entity_id)
                              INNER JOIN field_data_field_attendance_program_name AS a_p_name2 ON (a_p_name2.field_attendance_program_name_target_id = a_p_name.field_attendance_program_name_target_id)

                              INNER JOIN field_data_field_attendance_date AS att_date2 ON (att_date2.entity_id = a_p_name2.entity_id)

                            WHERE a_p_name.entity_id = {node}.nid
                                  AND att_date2.field_attendance_date_value < att_date.field_attendance_date_value
                            ORDER BY att_date2.field_attendance_date_value DESC
                            LIMIT 1";
  // Get enrolled kids for previous attendance date.
  $prev = novo_reports_get_attendance_enrolled_formula("(" . $sub . ")");

  return "(SELECT ($cur - $prev))";
}
