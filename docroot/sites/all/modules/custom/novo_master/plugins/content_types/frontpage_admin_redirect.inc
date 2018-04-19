<?php

/**
 * @file
 * Provide short description of user account.
 */

/**
 * Frontpage plugin.
 */
$plugin = array(
  'title' => t('Frontpage: Admin redirect'),
  'category' => 'Novo frontpage',
  'render callback' => 'novo_frontpage_admin_redirect',
  'edit form' => 'novo_frontpage_admin_redirect_edit_form',
  'required context' => new ctools_context_required(t('User'), 'user'),
  'single' => TRUE,
);

/**
 * Render the block with information.
 */
function novo_frontpage_admin_redirect($subtype, $conf, $args, $context) {
  $redirect_url = (!empty($conf['redirect_url'])) ? $conf['redirect_url'] : "";
  if (!empty($redirect_url)) {
    drupal_goto($redirect_url);
  }

  return NULL;
}

/**
 * Edit callback for plugin.
 */
function novo_frontpage_admin_redirect_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['redirect_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Url for redirect'),
    '#default_value' => !empty($conf['redirect_url']) ? $conf['redirect_url'] : '',
  );

  return $form;
}

/**
 * Save callback for plugin.
 */
function novo_frontpage_admin_redirect_edit_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (!empty($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
