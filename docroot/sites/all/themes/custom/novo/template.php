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

  // Theme status and approve block.
  if (isset($variables['type']) && $variables['type'] == 'application') {
    if (isset($variables['content']['app_status']['#markup'])) {
      $variables['content']['app_status']['#markup'] = novo_wrap_app_status_label($variables['content']['app_status']['#markup']);
    }
    if (isset($variables['content']['app_approve_block'])) {
      $options = array(
        'weight' => 1000,
        'scope' => 'footer'
      );
      drupal_add_js(drupal_get_path("theme", "novo") . "/js/bootstrap-confirmation.min.js", $options);
      drupal_add_js(drupal_get_path("theme", "novo") . "/js/novo-application-approve.js", $options);
    }
  }
}

/**
 * Implements hook_hook_preprocess_views_view_field().
 */
function novo_preprocess_views_view_field(&$vars) {
  if ($vars['view']->name == "volunteers" && $vars['view']->current_display == "page") {
    if (isset($vars['field']->field) && $vars['field']->field == "novo_application_status") {
      $vars['output'] = novo_wrap_app_status_label($vars['output']);
    }
  }
}

/**
 * Get application status class.
 */
function novo_wrap_app_status_label($text) {
  switch (drupal_strtolower($text)) {
    case "started":
    case "completed":
      $label = "info";
      break;

    case "approved":
      $label = "success";
      break;

    case "not approved":
      $label = "danger";
      break;

    default:
      $label = "default";
  }

  if ($label) {
    $label_html = theme('status_label', array(
      'status' => $text,
      'label' => $label,
    ));
    return $label_html;
  }
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
      case 'field_phone':
        $variables['icon'] = 'phone';
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
      // @codingStandardsIgnoreStart
      switch ($node->type) {
        case "program":
        case "locations":
        case "mentors":
        case "attendance":
        case "class":
          return TRUE;
          break;
      }
      // @codingStandardsIgnoreEnd
    }
  }

  $pages = isset($block->pages) ? explode(PHP_EOL, $block->pages) : array();
  $pages = array_map("trim", $pages);
  return (in_array(trim($_GET['q']), $pages)) ? TRUE : FALSE;

}

/**
 * Implements hook_preprocess_block().
 */
function novo_preprocess_block(&$variables) {
  if ($variables['block']->module == "webform") {
    $variables['theme_hook_suggestions'][] = "block__webform__contact_us";
  }
}

function novo_preprocess_taxonomy_term(&$variables) {
  //kpr($variables);
}


/**
 * Implements hook_preprocess_views_view_table()
 */
function novo_preprocess_views_view_table(&$vars) {
  // If this view is not the sort view, then stop here.
  if (!isset($vars['view']->field['draggableviews'])) {
    return;
  }

  // Check permissions.
  if (!user_access('access draggableviews')) {
    // Remove column "draggableviews" from results and header.
    foreach ($vars['rows'] as &$row) {
      unset($row['draggableviews']);
    }
    unset($vars['header']['draggableviews']);
    return;
  }

  // Add JavaScript for auto-save functionality.
  if ($vars['view']->field['draggableviews']->options['draggableviews']['ajax']) {
    drupal_add_js(drupal_get_path('theme', 'novo') . '/js/novo_draggableviews_table.js', array('scope' => 'footer'));
  }
}
