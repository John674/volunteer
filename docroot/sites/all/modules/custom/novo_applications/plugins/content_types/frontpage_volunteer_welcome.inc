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

  $block->title = '';
  $data = array(
    'already_created_app' => $already_created_app
  );
  $content = array(
    '#theme' => 'novo_applications_welcome_block',
    '#content' => $data,
  );

  $block->content = $content;

  return $block;
}
