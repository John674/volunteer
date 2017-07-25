<?php

/**
 * @file
 * The primary PHP file for this theme.
 */

define("NOVO_BASE_EMAIL", "volunteer@novoministries.org");
define("NOVO_BASE_PHONE", "4052084255");
define("NOVO_BASE_PHONE_LABEL", "405.208.4255");

define("NOVO_BASE_APPLICATION_STATUS_LABELS", serialize(array(
  'approved' => 'success',
  'not approved' => 'danger',
)));

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

  if (isset($node->type) && ($node->type == 'application' || $node->type == 'kids' || $node->type == 'partner')) {
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
          $status_labels = unserialize(NOVO_BASE_APPLICATION_STATUS_LABELS);

          $term_id = $field_app_status[0]['tid'];
          $status_term = taxonomy_term_load($term_id);
          $status = $status_term->name;
          $label = !empty($status_labels[drupal_strtolower($status)]) ? $status_labels[drupal_strtolower($status)] : "default";
          $label_html = theme('status_label', array(
            'status' => $status,
            'label' => $label,
          ));
          $variables['items'][0]['#markup'] = $label_html;
        }
        break;

      case 'field_reference_request_1':
      case 'field_reference_request_2':
      case 'field_reference_request_standby':
      case 'field_reference_request_parents':
      case 'field_reference_request_church':
        $variables['theme_hook_suggestions'][] = 'field__field_reference_request';

        break;
    }

    // @codingStandardsIgnoreStart

//    if ("field_reference_request_1" == $variables['element']['#field_name']) {
//      kpr($variables);
//    }

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
      'template' => 'templates/custom/status-label',
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
  //@codingStandardsIgnoreStart
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
  //@codingStandardsIgnoreEnd
  return FALSE;
}

/**
 * Implements hook_menu_tree__menu_program_menu().
 */
function novo_menu_tree__menu_program_menu(&$variables) {
  return '<ul class="nav nav-tabs">' . $variables['tree'] . '</ul>';
}

/**
 * Block visibility callback for the search form block.
 *
 * @param object $block
 *   The block object.
 *
 * @return bool
 *   TRUE if the block should be displayed on the current page.
 */
function _novo_menu_menu_program_menu_block_visibility($block) {
  $arg0 = arg(0);
  $arg1 = arg(1);
  $arg2 = arg(2);
  if ($arg0 == 'node' && is_numeric($arg1) && $arg2 == 'edit') {
    $node = node_load($arg1);
    if (isset($node->type)) {
      switch ($node->type) {
        case "program":
        case "locations":
        case "mentors":
        case "attendance":
          return TRUE;
          break;
      }

    }
  }

  $pages = isset($block->pages) ? explode(PHP_EOL, $block->pages) : array();
  $pages = array_map("trim", $pages);
  return (in_array(trim($_GET['q']), $pages)) ? TRUE : FALSE;

}
