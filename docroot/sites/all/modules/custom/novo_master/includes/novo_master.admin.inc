<?php

/**
 * @file
 * Admin page callbacks for the novo_cia module.
 */

/**
 * Form for configuring front page settings.
 */
function novo_master_settings($form, &$form_state) {
  $form['novo_master_exp_period'] = array(
    '#type' => 'textfield',
    '#title' => t('Expiration period'),
    '#description' => t('Application expiration period in php Date and Time Formats. (Example: +36 months)'),
    '#default_value' => variable_get('novo_master_exp_period', '+36 months'),
    '#required' => TRUE,
    '#element_validate' => ['_novo_master_exp_period_field_validate']
  );

  return system_settings_form($form);
}

/**
 * Validate strtotime string.
 */
function _novo_master_exp_period_field_validate($element, $form_state) {
  $time_string = $element['#value'] ?? NULL;
  if (!$time_string || !strtotime($time_string)) {
    form_error($element, t('@field_name field has wrong format.', array('@field_name' => $element['#title'])));
  }
}
