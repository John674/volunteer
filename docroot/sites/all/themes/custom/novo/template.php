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
  // @codingStandardsIgnoreStart
  //kpr($variables);
  // @codingStandardsIgnoreEnd
}
