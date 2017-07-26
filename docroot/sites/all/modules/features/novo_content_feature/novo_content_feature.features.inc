<?php
/**
 * @file
 * novo_content_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function novo_content_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function novo_content_feature_node_info() {
  $items = array(
    'application' => array(
      'name' => t('Application'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Legal First Name'),
      'help' => '',
    ),
    'attendance' => array(
      'name' => t('Attendance'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'class' => array(
      'name' => t('Class'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Class name'),
      'help' => '',
    ),
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
    'mentors' => array(
      'name' => t('Mentors'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'partner' => array(
      'name' => t('Partner'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Partner name'),
      'help' => '',
    ),
    'program' => array(
      'name' => t('Program'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'reference_request' => array(
      'name' => t('Reference request'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
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
