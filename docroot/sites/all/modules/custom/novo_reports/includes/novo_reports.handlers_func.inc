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
function novo_reports_get_attendance_formula($sub_query_nid = NULL) {
  $sub_query_nid_value = (!empty($sub_query_nid)) ? $sub_query_nid : "{node}.nid";
  $formula = "SELECT COUNT(*)
    FROM {field_data_field_attendance_kids_list} AS a_kids_list
    WHERE a_kids_list.entity_id = $sub_query_nid_value";
  return "(" . $formula . ")";
}

/**
 * Get attendance NEW enrolled formula.
 */
function novo_reports_get_attendance_new_formula($sub_query_nid = NULL) {
  $sub_query_nid_value = (!empty($sub_query_nid)) ? $sub_query_nid : "{node}.nid";

  // Get enrolled kids for current attendance date.
  $cur = novo_reports_get_attendance_enrolled_formula($sub_query_nid_value);

  // Get prev attendance node for current programm.
  $sub = "SELECT a_p_name2.entity_id AS prev_entity_id

                            FROM field_data_field_attendance_program_name AS a_p_name
                              INNER JOIN field_data_field_attendance_date AS att_date ON (att_date.entity_id = a_p_name.entity_id)
                              INNER JOIN field_data_field_attendance_program_name AS a_p_name2 ON (a_p_name2.field_attendance_program_name_target_id = a_p_name.field_attendance_program_name_target_id)

                              INNER JOIN field_data_field_attendance_date AS att_date2 ON (att_date2.entity_id = a_p_name2.entity_id)

                            WHERE a_p_name.entity_id = $sub_query_nid_value
                                  AND att_date2.field_attendance_date_value < att_date.field_attendance_date_value
                            ORDER BY att_date2.field_attendance_date_value DESC
                            LIMIT 1";
  // Get enrolled kids for previous attendance date.
  $prev = novo_reports_get_attendance_enrolled_formula("(" . $sub . ")");

  return "(SELECT ($cur - $prev))";
}

/**
 * Get mentoring_conversation_formula formula.
 */
function novo_reports_get_mentoring_conversation_formula($att_nid, $type_filter = NULL) {
  $prev_att_date_formula = "SELECT UNIX_TIMESTAMP(att_prev_date.field_attendance_date_value) FROM {field_data_field_attendance_date} AS att_prev_date 
  WHERE att_prev_date.entity_id = (SELECT a_p_name2.entity_id AS prev_entity_id
                            FROM field_data_field_attendance_program_name AS a_p_name
                              INNER JOIN field_data_field_attendance_date AS att_date ON (att_date.entity_id = a_p_name.entity_id)
                              INNER JOIN field_data_field_attendance_program_name AS a_p_name2 ON (a_p_name2.field_attendance_program_name_target_id = a_p_name.field_attendance_program_name_target_id)
                              INNER JOIN field_data_field_attendance_date AS att_date2 ON (att_date2.entity_id = a_p_name2.entity_id)
                            WHERE a_p_name.entity_id = $att_nid
                                  AND att_date2.field_attendance_date_value < att_date.field_attendance_date_value
                            ORDER BY att_date2.field_attendance_date_value DESC
                            LIMIT 1)
                            LIMIT 1";

  $type_filter_formula = (!empty($type_filter)) ? "AND LOWER(ment_type.field_mentoring_value) = '" . $type_filter . "'" : "";

  $formula = "SELECT count(*) AS mentors
FROM {field_data_field_attendance_program_name} AS a_p_name
  INNER JOIN {field_data_field_attendance_date} AS att_date ON (att_date.entity_id = a_p_name.entity_id)

  INNER JOIN {field_data_field_mentor_program_name} AS m_p_name ON m_p_name.field_mentor_program_name_target_id = a_p_name.field_attendance_program_name_target_id 
  INNER JOIN {field_data_field_mentoring_date} AS ment_date ON ment_date.entity_id = m_p_name.entity_id
  
  LEFT JOIN {field_data_field_mentoring} AS ment_type ON ment_type.entity_id = ment_date.entity_id
  
WHERE a_p_name.entity_id = $att_nid
  $type_filter_formula  
  AND (ment_date.field_mentoring_date_value < (UNIX_TIMESTAMP(att_date.field_attendance_date_value) + 60*60*24 -1))
  AND (ment_date.field_mentoring_date_value > (IF ((" . $prev_att_date_formula . ") IS NULL, 0, (" . $prev_att_date_formula . "))))

";

  return "IF ((" . $formula . ") IS NULL, 0, (" . $formula . "))";
}

/**
 * Get staff number formula.
 */
function novo_reports_get_staff_number_formula($att_nid) {
  $formula = "SELECT COUNT(att_staff_list.field_attendance_staff_list_target_id) 
FROM {field_data_field_attendance_staff_list} AS att_staff_list 
WHERE att_staff_list.entity_id = $att_nid";

  return "IF ((" . $formula . ") IS NULL, 0, (" . $formula . "))";
}

/**
 * Get volunteers number formula.
 */
function novo_reports_get_volunteers_number_formula($att_nid) {
  $formula = "SELECT COUNT(att_vol_list.field_attendance_volunteer_list_target_id) 
FROM {field_data_field_attendance_volunteer_list} AS att_vol_list 
WHERE att_vol_list.entity_id = $att_nid";

  return "IF ((" . $formula . ") IS NULL, 0, (" . $formula . "))";
}


/**
 * Get volunteers number formula.
 */
function novo_reports_get_active_volunteers_number_formula($att_nid) {

  $formula = "
  SELECT count(DISTINCT att_vol_list.field_attendance_volunteer_list_target_id)

FROM field_data_field_attendance_location AS att_orig_loc
  INNER JOIN field_data_field_attendance_date AS att_date_orig ON (att_date_orig.entity_id = att_orig_loc.entity_id)

  INNER JOIN field_data_field_attendance_location AS att_loc
    ON att_loc.field_attendance_location_target_id = att_orig_loc.field_attendance_location_target_id
  INNER JOIN field_revision_field_attendance_volunteer_list AS att_vol_list
    ON att_vol_list.entity_id = att_loc.entity_id
  INNER JOIN node_revision AS n_rev ON (n_rev.nid = att_vol_list.entity_id AND n_rev.vid = att_vol_list.revision_id)

WHERE att_orig_loc.entity_id = $att_nid AND
  n_rev.timestamp < UNIX_TIMESTAMP(att_date_orig.field_attendance_date_value) AND
  n_rev.timestamp > UNIX_TIMESTAMP(att_date_orig.field_attendance_date_value) - (60 * 60 * 24 * 30 * 18)";

  return "IF ((" . $formula . ") IS NULL, 0, (" . $formula . "))";
}
