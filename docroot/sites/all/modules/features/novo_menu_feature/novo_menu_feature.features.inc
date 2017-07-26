<?php
/**
 * @file
 * novo_menu_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function novo_menu_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
