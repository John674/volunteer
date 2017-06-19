<?php

/**
 * @file
 * Theme and preprocess form elements.
 */

/**
 * Theme_select.
 */
function novo_select($variables) {
  $element = $variables['element'];
  element_set_attributes($element, array('id', 'name', 'size'));

  // Theme Color selects.
  if (isset($element['#field_name'])) {
    switch ($element['#field_name']) {
      case "field_p_small_group":
      case "field_p_canvassing_group":
        _form_set_class($element, array('form-select', 'selectpicker'));
        return '<select' . drupal_attributes($element['#attributes']) . '>' . novo_form_select_options_color($element) . '</select>';

      break;
    }
  }

  // Theme School year.
  if (strpos($element['#name'], "field_program_school_year") === 0) {
    foreach ($element['#options'] as $key => $value) {
      $element['#options'][$key] = $value . " - " . ($value + 1);
    }
  }

  // Default select.
  _form_set_class($element, array('form-select'));
  return '<select' . drupal_attributes($element['#attributes']) . '>' . form_select_options($element) . '</select>';
}

/**
 * Custom form_select_options.
 */
function novo_form_select_options_color($element, $choices = NULL) {
  if (!isset($choices)) {
    $choices = $element['#options'];
  }
  // array_key_exists() accommodates the rare event where $element['#value'] is NULL.
  // isset() fails in this situation.
  $value_valid = isset($element['#value']) || array_key_exists('#value', $element);
  $value_is_array = $value_valid && is_array($element['#value']);
  $options = '';
  foreach ($choices as $key => $choice) {
    if (is_array($choice)) {
      $options .= '<optgroup label="' . check_plain($key) . '">';
      $options .= novo_form_select_options_color($element, $choice);
      $options .= '</optgroup>';
    }
    elseif (is_object($choice)) {
      $options .= novo_form_select_options_color($element, $choice->option);
    }
    else {
      $key = (string) $key;
      if ($value_valid && (!$value_is_array && (string) $element['#value'] === $key || ($value_is_array && in_array($key, $element['#value'])))) {
        $selected = ' selected="selected"';
      }
      else {
        $selected = '';
      }

      $choice_data = explode("|", $choice);
      if (isset($choice_data[1])) {
        $color = !empty(trim($choice_data[1])) ? $choice_data[1] : NULL;
        $choice = trim($choice_data[0]);
        if (!empty($color)) {
          $options .= '<option data-content="<span style=\'background:' . $color . ';\' class=\'novo-select-color-block\'></span> ' . check_plain($choice) . '" value="' . check_plain($key) . '"' . $selected . '>' . check_plain($choice) . '</option>';
        }
        else {
          $options .= '<option value="' . check_plain($key) . '"' . $selected . '>' . check_plain($choice) . '</option>';
        }
      }
      else {
        $options .= '<option value="' . check_plain($key) . '"' . $selected . '>' . check_plain($choice) . '</option>';
      }
    }
  }
  return $options;
}
