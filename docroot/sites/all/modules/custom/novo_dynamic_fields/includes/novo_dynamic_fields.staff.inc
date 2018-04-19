<?php

/**
 * @file
 * Staff dynamic fields.
 */

/**
 * Dyn fields for kids.
 */
function novo_dynamic_fields_attach_dynamic_fields_staff($nid) {
  $output = "";

  $node = node_load($nid);
  $exposed_value = array("title" => htmlspecialchars_decode($node->title));

  $output .= theme("novo_dynamic_fields_row", novo_dynamic_fields_build_view_dyn_field("Attendance Records", "History attendance dates", "attendance_records_of_staff", array(), $exposed_value));
  $output .= theme("novo_dynamic_fields_row", novo_dynamic_fields_build_view_dyn_field("Mentoring Records", "List kids mentors", "list_kids_mentored_for_staff", array(), $exposed_value));
  $output .= theme("novo_dynamic_fields_row", novo_dynamic_fields_build_view_dyn_field("Program history", "List Program Participated", "list_programm_participated_staff", array(), $exposed_value));

  return $output;
}
