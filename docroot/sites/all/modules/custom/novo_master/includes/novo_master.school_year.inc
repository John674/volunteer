<?php

/**
 * @file
 * novo_master.school_year.
 */

/**
 * Implements hook_field_info().
 */
function novo_master_field_info() {
  return array(
    'school_year' => array(
      'label' => t('School Year'),
      'description' => t('School Year'),
      'settings' => array('max_length' => 4),
      'default_widget' => 'options_select',
      'default_formatter' => 'novo_master_options_list',
      'instance_settings' => array(
        'start_year' => date("Y", strtotime("-50 year")),
        'end_year' => date("Y"),
        'default_value' => 'now',
        'default_value_code' => '',
      ),
    ),
  );
}


/**
 * Implements hook_field_instance_settings_form().
 */
function novo_master_field_instance_settings_form($field, $instance) {
  $instance_settings = $instance['settings'];
  $form = array();

  $form['start_year'] = array(
    '#type' => 'textfield',
    '#title' => t('Start year'),
    '#default_value' => isset($instance_settings['start_year']) ? $instance_settings['start_year'] : "",
    '#weight' => 1,
    '#fieldset' => 'default_values',
  );

  $form['end_year'] = array(
    '#type' => 'textfield',
    '#title' => t('End year'),
    '#default_value' => isset($instance_settings['end_year']) ? $instance_settings['end_year'] : "",
    '#weight' => 2,
    '#fieldset' => 'default_values',
  );


  $form['default_value'] = array(
    '#type' => 'select',
    '#title' => t('Default date'),
    '#default_value' => isset($instance_settings['default_value']) ? $instance_settings['default_value'] : "blank",
    '#options' => array(
      'blank' => t('No default value'),
      'now' => t('Now'),
      'strtotime' => t('Relative'),
    ),
    '#weight' => 3,
    '#fieldset' => 'default_values',
  );

  $description = t("Describe a time by reference to the current day, like '+90 days' (90 days from the day the field is created) or '+1 Saturday' (the next Saturday). See !strtotime for more details.", array('!strtotime' => l(t('strtotime'), 'http://www.php.net/manual/en/function.strtotime.php')));
  $form['default_value_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Relative default value'),
    '#description' => $description,
    '#default_value' => isset($instance_settings['default_value_code']) ? $instance_settings['default_value_code'] : "",
    '#states' => array(
      'visible' => array(
        ':input[name="instance[settings][default_value]"]' => array(
          'value' => 'strtotime',
        ),
      ),
    ),
    '#weight' => 3.1,
    '#fieldset' => 'default_values',
  );

  $form['#element_validate'] = array('_novo_master_field_instance_settings_form_validate');

  return $form;
}

/**
 * Form validation handler for _date_field_instance_settings_form().
 */
function _novo_master_field_instance_settings_form_validate(&$form, &$form_state) {
  $settings = &$form_state['values']['instance']['settings'];

  if (!empty($settings['start_year'])) {
    $settings['start_year'] = intval($settings['start_year']);
  }
  if (!empty($settings['end_year'])) {
    $settings['end_year'] = intval($settings['end_year']);
  }

  if (empty($settings['start_year']) || !checkdate(12, 31, $settings['start_year'])) {
    form_set_error('instance][settings][start_year', t('The Start year value is invalid.'));
  }

  if (empty($settings['end_year']) || !checkdate(12, 31, $settings['end_year'])) {
    form_set_error('instance][settings][end_year', t('The End year value is invalid.'));
  }

  if (!empty($settings['end_year']) && empty($settings['start_year'])) {
    form_set_error('instance][settings][end_year', t('The Start year value is invalid.'));
  }

  if (empty($settings['end_year']) && !empty($settings['start_year'])) {
    form_set_error('instance][settings][end_year', t('The End year value is invalid.'));
  }

  if ($settings['end_year'] < $settings['start_year']) {
    form_set_error('instance][settings][end_year', t('The End year value is invalid.'));
  }

  if ($settings['default_value'] == 'strtotime') {
    $is_strtotime = @strtotime($settings['default_value_code']);
    if (!$is_strtotime) {
      form_set_error('instance][settings][default_value_code', t('The Strtotime default value is invalid.'));
    }
  }
}

/**
 * Implements hook_field_widget_info_alter().
 */
function novo_master_field_widget_info_alter(&$info) {
  $widgets = array(
    'options_select' => array('school_year'),
  );
  foreach ($widgets as $widget => $field_types) {
    $info[$widget]['field types'] = array_merge($info[$widget]['field types'], $field_types);
  }
}

/**
 * Field options list
 */
function novo_master_options_list($field, $instance, $entity_type, $entity) {
  return novo_master_available_options_list($instance);
}

/**
 * Field available options list
 */
function novo_master_available_options_list($instance) {
  $start_year = isset($instance['settings']['start_year']) ? $instance['settings']['start_year'] : date("Y", strtotime("-50 year", time()));
  $end_year = isset($instance['settings']['end_year']) ? $instance['settings']['end_year'] : date("Y");
  $years_list = array();
  for ($i = $start_year; $i <= $end_year; $i++) {
    $years_list[$i] = $i;
  }
  return $years_list;
}

/**
 * Implements hook_field_formatter_info().
 */
function novo_master_field_formatter_info() {
  return array(
    'school_year_default' => array(
      'label' => t('Default'),
      'field types' => array('school_year'),
    ),
  );
}

/**
 * Implements hook_field_formatter_view().
 */
function novo_master_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  //Currently we only have one display option, use switch
  //to prepare for future options.
  switch ($display['type']) {
    case 'school_year_default':
      foreach ($items as $delta => $item) {
        if (isset($options[$item['option']]['option'])) {
          $output = field_filter_xss($options[$item['option']]['option']);
        }
        else {
          $output = t("Not Supplied");
        }
        $element[$delta] = array('#markup' => $output);
      }
      break;
    default:
  }
  return $element;
}

/**
 * Implements hook_content_is_empty().
 */
function novo_master_field_is_empty($item, $field) {
  if (empty($item['school_year'])) {
    return TRUE;
  }
  return FALSE;
}

/**
 * Implements hook_field_widget_form_alter().
 */
function novo_master_field_widget_form_alter(&$element, &$form_state, $context) {
  if (isset($context['field']['type']) && $context['field']['type'] == "school_year") {
    $settings_default_value = isset($context['instance']['settings']['default_value']) ? $context['instance']['settings']['default_value'] : NULL;
    $element_default_value = NULL;
    if (!empty($context['instance']['widget']['is_new'])) {
      if (!empty($settings_default_value)) {

        switch ($settings_default_value) {
          case "now":
            $element_default_value = date("Y");
            break;

          case "strtotime":
            $settings_default_value_code = isset($context['instance']['settings']['default_value_code']) ? $context['instance']['settings']['default_value_code'] : NULL;
            $element_default_value = date("Y", strtotime($settings_default_value_code));
            break;
        }
      }

      if (!empty($element_default_value)) {
        $element['#default_value'] = $element_default_value;
      }
    }
  }
}

/**
 * Implements hook_field_widget_properties_alter().
 *
 * Alters the widget properties of a field instance before it gets displayed.
 * Used here to flag new entities so we can later tell if they need default values.
 */
function novo_master_field_widget_properties_alter(&$widget, $context) {
  if (isset($context['field']['type']) && $context['field']['type'] == "school_year") {
    $entity_type = $context['entity_type'];
    $entity = $context['entity'];
    $info = entity_get_info($entity_type);
    $id = $info['entity keys']['id'];
    $widget['is_new'] = FALSE;
    if (empty($entity->$id)) {
      $widget['is_new'] = TRUE;
    }
  }
}

/**
 * Implements hook_form_FORM_ID_alter() for field_ui_field_edit_form().
 */
function novo_master_form_field_ui_field_edit_form_alter(&$form, &$form_state, $form_id) {
  $form['instance']['default_value_widget']['#access'] = FALSE;
  $field = $form['#field'];
  $instance = $form['#instance'];

  if (!in_array($field['type'], array('school_year'))) {
    return;
  }

  // Reorganize the instance settings and widget settings sections into a more
  // intuitive combined fieldset.
  $form['instance']['default_values'] = array(
    '#type' => 'fieldset',
    '#title' => t('Default values'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['instance']['#pre_render'][] = 'novo_master_field_ui_field_edit_form_pre_render';
}

/**
 * Rearrange form elements into fieldsets for presentation only.
 */
function novo_master_field_ui_field_edit_form_pre_render($form) {
  foreach ($form as $name => $element) {
    if (is_array($element) && isset($element['#fieldset'])) {
      $fieldset = $element['#fieldset'];
      $form[$fieldset][$name] = $element;
      unset($form[$name]);
    }
  }
  foreach (array('default_values') as $name) {
    if (element_children($form[$name])) {
      // Force the items in the fieldset to be resorted now that the instance
      // and widget settings are combined.
      $form[$name]['#sorted'] = FALSE;
      $form['defaults'][$name] = $form[$name];
    }
    unset($form[$name]);
  }
  return $form;
}
