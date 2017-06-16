<?php

/**
 * @file
 * Applications functions.
 */

define('NOVO_APPLICATION_REALM_VOLUNTEER', 'novo_application_realm_volunteer');
define('NOVO_APPLICATION_REALM_ADMIN', 'novo_application_realm_admin');
define('NOVO_APPLICATION_SITEADMIN_RID', 3);

// @codingStandardsIgnoreStart
///**
// * Implements hook_node_access_records().
// */
//function novo_applications_node_access_records($node) {
//  $grants = array();
//  if ($node->type == 'application') {
//    $grants[] = array(
//      'gid' => $node->uid,
//      'realm' => NOVO_APPLICATION_REALM_VOLUNTEER,
//      'grant_view' => 1,
//      'grant_update' => 1,
//      'grant_delete' => 0,
//      'priority' => 0,
//    );
//
//    $grants[] = array(
//      'gid' => 1,
//      'realm' => NOVO_APPLICATION_REALM_ADMIN,
//      'grant_view' => 1,
//      'grant_update' => 1,
//      'grant_delete' => 1,
//      'priority' => 0,
//    );
//  }
//
//  return $grants;
//}
//
///**
// * Implements hook_node_grants().
// */
//function novo_applications_node_grants($account, $op) {
//  // node_access_rebuild();
//  $grants = array();
//  if (user_has_role(NOVO_APPLICATION_SITEADMIN_RID, $account)) {
//    $grants[NOVO_APPLICATION_REALM_ADMIN] = array(TRUE);
//  } else {
//    $grants[NOVO_APPLICATION_REALM_VOLUNTEER] = array($account->uid);
//  }
//
//  return $grants;
//}
// @codingStandardsIgnoreEnd