<?php
/**
 * @file
 * novo_content_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function novo_content_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function novo_content_feature_node_info() {
  $items = array(
    'kids' => array(
      'name' => t('Kids'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('First Name'),
      'help' => '',
    ),
    'locations' => array(
      'name' => t('Locations'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Location Name'),
      'help' => '',
    ),
    'staff' => array(
      'name' => t('Staff'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('First Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
