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
    switch ($variables['element']['#field_name']) {
      case 'field_masked_phone_1':
        $variables['icon'] = 'phone ';
        $variables['is_phone_1'] = TRUE;
        break;

      case 'field_email':
        $variables['icon'] = 'envelope';
        break;

      case 'field_address_1':
        $variables['icon'] = 'home';
        break;

      case 'field_dob':
        $variables['icon'] = 'calendar';
        break;

      case 'field_city':
        $variables['icon'] = 'globe';
        break;

      case 'field_state':
        $variables['icon'] = 'globe';
        break;
    }
    // @codingStandardsIgnoreStart
    // kpr($variables);
    // @codingStandardsIgnoreEnd
  }
}
