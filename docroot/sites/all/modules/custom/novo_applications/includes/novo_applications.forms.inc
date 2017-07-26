<?php

/**
 * @file
 * Applications forms.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function novo_applications_form_application_node_form_alter(&$form, &$form_state, $form_id) {
  global $user;
  $is_new = (isset($form['nid']['#value']) && !empty($form['nid']['#value'])) ? FALSE : TRUE;
  if ($is_new) {
    $app_node_obj = novo_applications_get_user_app($user->uid);
    $app_nid = (isset($app_node_obj->nid) && !empty($app_node_obj->nid)) ? $app_node_obj->nid : NULL;

    if ($app_nid) {
      $node = node_load($app_nid);
      $lang = isset($node->language) ? $node->language : LANGUAGE_NONE;
      $finished_app = isset($node->field_completed[$lang][0]['value']) ? ($node->field_completed[$lang][0]['value']) : FALSE;

      if ($finished_app && !user_access("edit application with any status")) {
        // User already create application. Redirect.
        drupal_set_message(t("You already submit application"));
        drupal_goto("<front>");
      }
    }
  }

  // Replace uid for admins.
  if (user_access("edit application with any status")) {
    $uid = 0;
    $arg_uid = (isset($_GET['uid'])) ? $_GET['uid'] : NULL;
    if (!empty($arg_uid)) {
      $loaded_user = user_load($arg_uid);
      if (isset($loaded_user->uid)) {
        $uid = $loaded_user->uid;
      }
    }
    $form['field_app_user']['#access'] = ($user->uid == 1) ? TRUE : FALSE;
  }
  else {
    $uid = $user->uid;
    $form['field_app_user']['#access'] = FALSE;
  }

  if (empty($form['field_app_user'][LANGUAGE_NONE][0]['value']['#default_value'])) {
    $form['field_app_user'][LANGUAGE_NONE][0]['value']['#default_value'] = $uid;
  }
  $form['field_app_user'][LANGUAGE_NONE][0]['value']['#element_validate'][] = "novo_applications_user_unique_validate";

  $form['actions']['submit']['#submit'][] = "novo_applications_form_submit";
  $form['actions']['previous']['#submit'][] = "novo_applications_form_submit";
  $form['actions']['save']['#submit'][] = "novo_applications_form_submit";
  $form['actions']['next']['#submit'][] = "novo_applications_form_submit";

  $lang = isset($form['language']['#value']) ? $form['language']['#value'] : LANGUAGE_NONE;

  $form['field_app_7_final_agree_1'][$lang][0]['value']['#smart_description'] = FALSE;
  $form['field_app_7_final_agree_2'][$lang][0]['value']['#smart_description'] = FALSE;
  $form['field_app_7_final_agree_3'][$lang][0]['value']['#smart_description'] = FALSE;
  $form['field_app_7_final_agree_4'][$lang][0]['value']['#smart_description'] = FALSE;
  $form['field_app_7_final_agree_5'][$lang][0]['value']['#smart_description'] = FALSE;
  $form['field_app_7_final_agree_6'][$lang][0]['value']['#smart_description'] = FALSE;
  $form['field_app_7_final_agree_1'][$lang][0]['value']['#title_display'] = 'invisible';
  $form['field_app_7_final_agree_2'][$lang][0]['value']['#title_display'] = 'invisible';
  $form['field_app_7_final_agree_3'][$lang][0]['value']['#title_display'] = 'invisible';
  $form['field_app_7_final_agree_4'][$lang][0]['value']['#title_display'] = 'invisible';
  $form['field_app_7_final_agree_5'][$lang][0]['value']['#title_display'] = 'invisible';
  $form['field_app_7_final_agree_6'][$lang][0]['value']['#title_display'] = 'invisible';
  $form['field_masked_emergency_phone'][$lang][0]['value']['#attributes']['class'][] = 'form-control';

  $form['field_app7_statement_agree'][$lang][0]['value']['#smart_description'] = FALSE;
  $form['field_app7_statement_agree'][$lang][0]['value']['#title_display'] = 'invisible';
  $form['field_program_policies_agree'][$lang][0]['value']['#smart_description'] = FALSE;
  $form['field_program_policies_agree'][$lang][0]['value']['#title_display'] = 'invisible';

  $form['field_ref_1_how_long']['#element_validate'][] = '_custom_ref_how_long_field_validate';
  $form['field_ref_2_how_long']['#element_validate'][] = '_custom_ref_how_long_field_validate';
  $form['field_ref_3_how_long']['#element_validate'][] = '_custom_ref_how_long_field_validate';

  // Parent section.
  $node = (isset($form_state['node'])) ? $form_state['node'] : NULL;
  if ($node) {
    $dob = (isset($node->field_dob[$node->language][0]['value'])) ? $node->field_dob[$node->language][0]['value'] : NULL;
    if ($dob) {
      $dob_date = new DateTime();
      $dob_date->setTimestamp($dob);
      $today = new DateTime();
      $age = $today->diff($dob_date)->format("%y");
      if ($age >= 18) {
        _novo_application_hide_parent_section($form);
      }
    }
  }
}

/**
 * Validate app user.
 */
function novo_applications_user_unique_validate($element, &$form_state) {
  $uid = isset($element['#value']) ? $element['#value'] : NULL;
  $nid = isset($form_state['values']['nid']) ? $form_state['values']['nid'] : NULL;

  if (empty($uid)) {
    form_set_error("field_app_user", t("Error. Can't create application."));
  }

  $query = db_select('users', 'u');
  $query->fields('u', array('uid'));
  $query->condition('uid', $uid);
  $query->leftJoin("field_data_field_app_user", "app_user", "app_user.field_app_user_value = u.uid");

  if (!empty($nid)) {
    $query->addExpression("CASE WHEN app_user.entity_id = :nid THEN null ELSE app_user.entity_id END", "app_nid", array(":nid" => $nid));
  }
  else {
    $query->addField('app_user', 'entity_id', 'app_nid');
  }

  $exist = $query->range(0, 1)->execute()->fetchObject();

  if (!isset($exist->uid)) {
    form_set_error(NULL, t("User not exist"));
  }
  else {
    if (isset($exist->app_nid)) {
      $error_message = user_access("edit application with any status") ? t("Application for this user already exist. Please edit this !link", array("!link" => l(t("application"), "node/" . $exist->app_nid))) : t("You already submit application");
      form_set_error("field_app_user", $error_message);
    }
  }
}

/**
 * Node application form submit.
 */
function novo_applications_form_submit(&$form, &$form_state) {
  if (!user_access("disable auto complete")) {
    // Set completed field for node when multistep completed.
    $complete = isset($form_state['#multistep_complete']) ? ($form_state['#multistep_complete']) : FALSE;
    if ($complete) {
      $node = isset($form_state['node']) ? $form_state['node'] : NULL;
      $lang = isset($node->language) ? $node->language : LANGUAGE_NONE;
      $node_completed = isset($node->field_completed[$lang][0]['value']) ? ($node->field_completed[$lang][0]['value']) : FALSE;
      if (!$node_completed) {
        $node->field_completed[$lang][0]['value'] = 1;
        node_save($node);
        cache_clear_all("field:node:{$node->nid}", 'cache_field');
        if (!user_access("disable auto complete redirect")) {
          drupal_set_message("Your application will begin processing now!");
          drupal_goto("<front>");
        }
        else {
          drupal_set_message("Application has been completed!");
        }
      }
    }
  }
}

/**
 * Hide parents section if age more 18.
 */
function _novo_application_hide_parent_section(&$form) {
  $form['field_parent_email']['#access'] = FALSE;
  $form['field_parent_guardian_first_name']['#access'] = FALSE;
  $form['field_parent_guardian_last_name']['#access'] = FALSE;
  $form['field_parent_phone']['#access'] = FALSE;
  $form['field_parent_prefix']['#access'] = FALSE;
}

/**
 * Validate 'How do you know this reference?' fields, value should be minimum 6 months.
 */
function _custom_ref_how_long_field_validate($element, $form_state) {
  $lang = isset($form['language']['#value']) ? $form['language']['#value'] : LANGUAGE_NONE;
  $field_how_long_name = $element[$lang]['#field_name'];
  $field_how_long_period_name = $field_how_long_name . '_period';
  $field_how_long_period_value = isset($form_state['values'][$field_how_long_period_name][$lang]) ? $form_state['values'][$field_how_long_period_name][$lang] : NULL;

  if (!empty($field_how_long_period_value) && ($field_how_long_period_value == 'months')) {
    $field_how_long_value = isset($field_how_long_period_value) ? intval($element[$lang][0]['value']['#value']) : NULL;
    if (!empty($field_how_long_value) && ($field_how_long_value < 6)) {
      form_error($element, t('@field_name field should be minimum 6 months.', array('@field_name' => $element[$lang]['#title'])));
    }
  }
}
