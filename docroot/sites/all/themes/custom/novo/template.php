<?php

/**
 * @file
 * The primary PHP file for this theme.
 */

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
  // @codingStandardsIgnoreStart
  //kpr($variables);
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
  $type = $variables['element']['#object']->type;

  if ($type == 'application') {
    $node = $variables['element']['#object'];
    switch ($variables['element']['#field_name']) {
      case 'field_masked_phone_1':
        $variables['icon'] = 'phone';
        $variables['label'] = 'Phone';
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
        $variables['label'] = 'Address';
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
