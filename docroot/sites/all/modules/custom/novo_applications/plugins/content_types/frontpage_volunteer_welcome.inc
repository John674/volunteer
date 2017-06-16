<?php

/**
 * @file
 * Provide short description of user account.
 */

/**
 * Frontpage plugin.
 */
$plugin = array(
  'title' => t('Frontpage: Volunteer welcome'),
  'category' => 'Novo frontpage',
  'render callback' => 'novo_frontpage_volunteer_welcome',
  'required context' => new ctools_context_required(t('User'), 'user'),
);

/**
 * Render the block with information.
 */
function novo_frontpage_volunteer_welcome($subtype, $conf, $args, $context) {
  global $user;
  $block = new stdClass();
  $account = isset($context->ctools_context->data) ? $context->ctools_context->data : $user;
  $app_nodes = novo_applications_get_app_node_for_user($account);
  $already_created_app = (!empty($app_nodes)) ? TRUE : FALSE;

  $account = user_load($user->uid);
  $user_fname = field_get_items("user", $account, "field_u_first_name");
  $user_fname = field_view_value('user', $account, 'field_u_first_name', $user_fname[0]);
  $user_lname = field_get_items("user", $account, "field_u_last_name");
  $user_lname = field_view_value('user', $account, 'field_u_last_name', $user_lname[0]);
  $user_name = trim(render($user_fname) . " " . render($user_lname));
  if (empty($user_name)) {
    $user_name = $user->name;
  }

  $block->title = '';
  $data = array(
    'already_created_app' => $already_created_app,
    'user_name' => $user_name,
  );
  $content = array(
    '#theme' => 'novo_applications_welcome_block',
    '#content' => $data,
  );

  $block->content = $content;

  return $block;
}