<?php

/**
 * @file
 * Admin page callbacks for the novo_cia module.
 */

/**
 * Form for configuring front page settings.
 */
function novo_cia_api_credentials($form, &$form_state) {
  $form[NOVO_CIA_API_USERNAME] = array(
    '#type' => 'textfield',
    '#title' => t('Username or email'),
    '#description' => t('Username or email in CIA account.'),
    '#default_value' => variable_get(NOVO_CIA_API_USERNAME),
    '#required' => TRUE,
  );

  $form[NOVO_CIA_API_PASSWORD] = array(
    '#type' => 'password',
    '#title' => t('Password'),
    '#required' => TRUE,
    '#default_value' => variable_get(NOVO_CIA_API_PASSWORD),
    '#description' => t('Password in CIA account.'),
  );

  $form[NOVO_CIA_API_CLIENT_NAME] = array(
    '#type' => 'textfield',
    '#title' => t('Client name'),
    '#description' => t('Client name for request to CIA.'),
    '#default_value' => variable_get(NOVO_CIA_API_CLIENT_NAME),
    '#required' => TRUE,
  );

  $form[NOVO_CIA_API_BRANCH_NAME] = array(
    '#type' => 'textfield',
    '#title' => t('Branch'),
    '#description' => t('Name of branch for request to CIA.'),
    '#default_value' => variable_get(NOVO_CIA_API_BRANCH_NAME),
    '#required' => FALSE,
  );

  $form[NOVO_CIA_API_CLIENT_CONTACT] = array(
    '#type' => 'textfield',
    '#title' => t('Client contact'),
    '#description' => t('Client contact for request to CIA.'),
    '#default_value' => variable_get(NOVO_CIA_API_CLIENT_CONTACT),
    '#required' => TRUE,
  );

  $form[NOVO_CIA_API_CLIENT_CONTACT_EMAIL] = array(
    '#type' => 'textfield',
    '#title' => t('Client contact email'),
    '#description' => t('Client contact email for request to CIA.'),
    '#default_value' => variable_get(NOVO_CIA_API_CLIENT_CONTACT_EMAIL) ,
    '#required' => TRUE,
  );
  $form[NOVO_CIA_API_ATTEMPTS] = array(
    '#type' => 'textfield',
    '#title' => t('Attempts requests'),
    '#description' => t('Number of requests allowed.'),
    '#default_value' => 10 ,
    '#required' => TRUE,
  );

  $form[NOVO_CIA_API_IS_TEST] = array(
    '#type' => 'checkbox',
    '#title' => t('Is test'),
    '#description' => t('For test request to CIA.'),
    '#default_value' => variable_get(NOVO_CIA_API_IS_TEST),
    '#required' => FALSE,
  );

  return system_settings_form($form);
}
