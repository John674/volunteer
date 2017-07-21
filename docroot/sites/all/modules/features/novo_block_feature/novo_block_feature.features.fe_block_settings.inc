<?php
/**
 * @file
 * novo_block_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function novo_block_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu-menu-program-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-program-menu',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => 'locations
programs
attendance
mentors',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'novo' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'novo',
        'weight' => 0,
      ),
    ),
    'title' => ' ',
    'visibility' => 1,
  );

  $export['multistep-application'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'application',
    'module' => 'multistep',
    'node_types' => array(
      0 => 'application',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'novo' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'novo',
        'weight' => -7,
      ),
    ),
    'title' => ' ',
    'visibility' => 0,
  );

  $export['user-login'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'login',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'novo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'novo',
        'weight' => -8,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
