<?php

/**
 * @file
 * The primary PHP file for this theme.
 */

define("NOVO_BASE_EMAIL", "volunteer@novoministries.org");
define("NOVO_BASE_PHONE", "4052084255");
define("NOVO_BASE_PHONE_LABEL", "405.208.4255");

novo_theme_load_include("inc", "novo", "includes/novo_theme_form_elements");

/**
 * Implements hook_preprocess_html().
 */
function novo_preprocess_html(&$variables) {

}

/**
 * Implements hook_preprocess_node().
 */
function novo_preprocess_node(&$variables) {
  $variables['theme_hook_suggestions'][] = "node__" . $variables['type'] . "__" . $variables['view_mode'];

  if ($variables['type'] == 'kids') {
    $node = $variables['node'];
    $field_suffix = field_get_items('node', $node, 'field_suffix');
    $suffix = $field_suffix[0]['value'];
    $variables['suffix'] = $suffix;
  }
  // @codingStandardsIgnoreStart
  // kpr($variables);
  // @codingStandardsIgnoreEnd

}

/**
 * Implements hook_preprocess_page().
 */
function novo_preprocess_page(&$variables) {

}

/**
 * Implements hook_preprocess_form().
 */
function novo_preprocess_form(&$variables) {

}

/**
 * Implements hook_preprocess_field().
 */
function novo_preprocess_field(&$variables) {
  $node = $variables['element']['#object'];

  if ($node->type == 'application' || $node->type == 'kids') {

    switch ($variables['element']['#field_name']) {
      case 'field_masked_phone_1':
        $variables['icon'] = 'phone';
        $field_phone_2 = field_get_items('node', $node, 'field_masked_phone_2');
        $value_phone_2 = field_view_value('node', $node, 'field_masked_phone_2', $field_phone_2[0]);
        if (!empty($value_phone_2['#markup'])) {
          $variables['items'][] = $value_phone_2;
        }
        break;

      case 'field_email':
        $variables['icon'] = 'envelope';
        break;

      case 'field_address_1':
        $variables['icon'] = 'home';
        $field_address_2 = field_get_items('node', $node, 'field_address_2');
        $value_address_2 = field_view_value('node', $node, 'field_address_2', $field_address_2[0]);
        if (!empty($value_address_2['#markup'])) {
          $variables['items'][] = $value_address_2;
        }
        break;

      case 'field_dob':
        $variables['icon'] = 'calendar';
        break;

      case 'field_city':
        $variables['icon'] = 'globe';
        $field_state = field_get_items('node', $node, 'field_state');

        if (!empty($field_state)) {
          $term_id = $field_state[0]['tid'];
          $state_term = taxonomy_term_load($term_id);
          $variables['items'][0]['#markup'] .= '/' . $state_term->description;

          $field_state_info = field_info_instance('node', 'field_state', 'application');
          $variables['label'] .= '/' . $field_state_info['label'];
        }
        break;

      case 'field_app_status':
        $variables['icon'] = 'file-text-o';
        $variables['label'] = 'Application status';
        $field_app_status = field_get_items('node', $node, 'field_app_status');
        if (!empty($field_app_status)) {
          $status_labels = [
            'started' => 'info',
            'approved' => 'success',
            'completed' => 'primary',
            'expired' => 'danger',
          ];

          $term_id = $field_app_status[0]['tid'];
          $status_term = taxonomy_term_load($term_id);
          $status = $status_term->name;
          $label = $status_labels[drupal_strtolower($status)];
          $label_html = theme('status_label', array(
            'status' => $status,
            'label' => $label,
          ));
          $variables['items'][0]['#markup'] = $label_html;
        }
        break;
    }

    // @codingStandardsIgnoreStart
    // kpr($variables);
    // @codingStandardsIgnoreEnd
  }
}

/**
 * Implements hook_theme().
 */
function novo_theme($existing, $type, $theme, $path) {

  return array(
    'status_label' => array(
      'variables' => array('status' => NULL, 'label' => NULL),
      'template' => 'templates/system/status-label',
    ),
  );
}

/**
 * Analog module_load_include.
 */
function novo_theme_load_include($type, $theme, $name = NULL) {
  static $files = array();

  if (!isset($name)) {
    $name = $theme;
  }

  $key = $type . ':' . $theme . ':' . $name;
  if (isset($files[$key])) {
    return $files[$key];
  }

  if (function_exists('drupal_get_path')) {
    $file = DRUPAL_ROOT . '/' . drupal_get_path('theme', $theme) . "/$name.$type";
    if (is_file($file)) {
      require_once $file;
      $files[$key] = $file;
      return $file;
    }
    else {
      $files[$key] = FALSE;
    }
  }
  return FALSE;
}
