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

  $form['field_edu_level_years'][LANGUAGE_NONE][0]['value']['#title_display'] = 'invisible';

  if (user_access("disable multistep application form") && $user->uid > 1) {
    // Disable multistep.
    unset($form['#multistep']);
    $form['actions']['submit']['#access'] = TRUE;
    $form['actions']['previous']['#access'] = FALSE;
    $form['actions']['save']['#access'] = FALSE;
    $form['actions']['next']['#access'] = FALSE;
  }

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
      else {
        drupal_goto("node/$app_nid/edit");
      }
    }
    else {
      $uid = $user->uid;
      if (user_access("edit application with any status")) {
        $uid = (isset($_GET['uid'])) ? $_GET['uid'] : $uid;
      }

      // Add default values from user profile.
      $account = user_load($uid);
      if (!empty($account)) {
        $email = $account->mail;
        $first_name = novo_applications_get_field_value("user", $account, "field_u_first_name");
        $last_name = novo_applications_get_field_value("user", $account, "field_u_last_name");
        $birthday = novo_applications_get_field_value("user", $account, "field_u_birthday");
        $birthday_formatted = (!empty($birthday)) ? date("m/d/Y", strtotime($birthday)) : "";
        $form['field_first_name'][LANGUAGE_NONE][0]['value']['#default_value'] = $first_name;
        $form['field_last_name'][LANGUAGE_NONE][0]['value']['#default_value'] = $last_name;
        $form['field_dob'][LANGUAGE_NONE][0]['#default_value']['value'] = $birthday_formatted;
        $form['field_email'][LANGUAGE_NONE][0]['email']['#default_value'] = $email;
      }
    }
  }

  // Add exp date default value.
  $form['#validate'][] = 'novo_applications_add_exp_date_validate';

  // Add sites virtual field.
  novo_applications_add_sites_virtual_field($form, $form_state);

  // Validate Date of Birth.
  if (function_exists("novo_master_dob_validate")) {
    $form['field_dob'][LANGUAGE_NONE][0]['#element_validate'][] = "novo_master_dob_validate";
  }

  // Replace uid for admins.
  $form['field_app_user']['#access'] = ($user->uid == 1) ? TRUE : FALSE;

  if (empty($form['field_app_user'][LANGUAGE_NONE][0]['value']['#default_value'])) {
    $form['field_app_user'][LANGUAGE_NONE][0]['value']['#default_value'] = $uid;
  }
  $form['field_app_user'][LANGUAGE_NONE][0]['value']['#element_validate'][] = "novo_applications_user_unique_validate";

  $form['actions']['submit']['#submit'][] = "novo_applications_form_submit";
  $form['actions']['previous']['#submit'][] = "novo_applications_form_submit";
  $form['actions']['save']['#submit'][] = "novo_applications_form_submit";
  $form['actions']['next']['#submit'][] = "novo_applications_form_submit";
  $form['actions']['done']['#submit'][] = "novo_applications_form_submit";

  $form['actions']['save']['#access'] = FALSE;

  $lang = isset($form['language']['#value']) ? $form['language']['#value'] : LANGUAGE_NONE;

  $form['field_app_7_final_agree_1'][$lang][0]['value']['#attributes']['placeholder'] = t("INITIALS HERE");
  $form['field_app_7_final_agree_2'][$lang][0]['value']['#attributes']['placeholder'] = t("INITIALS HERE");
  $form['field_app_7_final_agree_3'][$lang][0]['value']['#attributes']['placeholder'] = t("INITIALS HERE");
  $form['field_app_7_final_agree_4'][$lang][0]['value']['#attributes']['placeholder'] = t("INITIALS HERE");
  $form['field_app_7_final_agree_5'][$lang][0]['value']['#attributes']['placeholder'] = t("INITIALS HERE");
  $form['field_app_7_final_agree_6'][$lang][0]['value']['#attributes']['placeholder'] = t("INITIALS HERE");

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
  $form['field_app7_statement_agree'][$lang][0]['value']['#attributes']['placeholder'] = t("INITIALS HERE");

  $form['field_program_policies_agree'][$lang][0]['value']['#smart_description'] = FALSE;
  $form['field_program_policies_agree'][$lang][0]['value']['#title_display'] = 'invisible';
  $form['field_program_policies_agree'][$lang][0]['value']['#attributes']['placeholder'] = t("INITIALS HERE");

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
  $query->fields('u', ['uid']);
  $query->condition('uid', $uid);
  $query->leftJoin("field_data_field_app_user", "app_user", "app_user.field_app_user_value = u.uid");

  if (!empty($nid)) {
    $query->addExpression("CASE WHEN app_user.entity_id = :nid THEN null ELSE app_user.entity_id END", "app_nid", [":nid" => $nid]);
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
      $error_message = user_access("edit application with any status") ? t("Application for this user already exist. Please edit this !link", ["!link" => l(t("application"), "node/" . $exist->app_nid)]) : t("You already submit application");
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
      $is_done_btn = (isset($form_state['triggering_element']['#id']) && $form_state['triggering_element']['#id'] === "edit-done") ? TRUE : FALSE;

      if (!$node_completed && $is_done_btn) {
        $node->field_completed[$lang][0]['value'] = 1;
        node_save($node);
        cache_clear_all("field:node:{$node->nid}", 'cache_field');
        entity_get_controller('node')->resetCache(array($node->nid));

        // Expired application checked by applicant.
        $app_expired_date = $node->field_expired_date[LANGUAGE_NONE][0]['value'] ?? NULL;
        if ($app_expired_date && $app_expired_date < REQUEST_TIME) {
          if (function_exists("novo_mail_app_exp_app_checked_by_applicant_to_admin")) {
            novo_mail_app_exp_app_checked_by_applicant_to_admin($node->nid);
          }
        }
        else {
          if (function_exists("novo_mail_app_submitted")) {
            novo_mail_app_submitted($node->nid);
          }
        }
        if (!user_access("disable auto complete redirect")) {
          drupal_get_messages("status");
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
  $lang = isset($form_state['language']['#value']) ? $form_state['language']['#value'] : LANGUAGE_NONE;
  $field_how_long_name = $element[$lang]['#field_name'];
  $field_how_long_period_name = $field_how_long_name . '_period';
  $field_how_long_period_value = isset($form_state['values'][$field_how_long_period_name][$lang]) ? $form_state['values'][$field_how_long_period_name][$lang] : NULL;

  if (!empty($field_how_long_period_value)) {
    $field_how_long_value = isset($field_how_long_period_value) ? intval($element[$lang][0]['value']['#value']) : NULL;
    if (empty($field_how_long_value)) {
      form_error($element, t('@field_name field should be minimum 6 months.', array('@field_name' => $element[$lang]['#title'])));
    }
    elseif (($field_how_long_period_value == 'months') && $field_how_long_value < 6) {
      form_error($element, t('@field_name field should be minimum 6 months.', array('@field_name' => $element[$lang]['#title'])));
    }
  }
}

/**
 * Add site virtual field.
 */
function novo_applications_add_sites_virtual_field(&$form, &$form_state) {
  $is_new = (isset($form['nid']['#value']) && !empty($form['nid']['#value'])) ? FALSE : TRUE;
  if ($is_new) {
    $multi = (isset($form['field_what_site_you_want'][LANGUAGE_NONE]['#cardinality']) && $form['field_what_site_you_want'][LANGUAGE_NONE]['#cardinality'] == -1) ? TRUE : FALSE;
    $weight = (isset($form['field_what_site_you_want']['#weight'])) ? $form['field_what_site_you_want']['#weight'] : 100;
    $options = novo_applications_get_sites_for_virtual_field();
    if (!empty($options)) {
      $form['field_what_site_you_want_virtual'] = [
        '#title' => t('At what site do you want to volunteer?'),
        '#type' => ($multi) ? "checkboxes" : "radios",
        '#options' => $options,
        '#weight' => $weight,
      ];
    }

    $form['#validate'][] = 'novo_applications_add_sites_virtual_validate';
    $form['#groups']['group_app_1_contact']->children[] = "field_what_site_you_want_virtual";
    $form['#group_children']['field_what_site_you_want_virtual'] = 'group_app_1_contact';
    $form['field_what_site_you_want']['#access'] = FALSE;
  }
}

/**
 * Get options for site field.
 */
function novo_applications_get_sites_for_virtual_field() {
  $options = [];
  $result = views_get_view_result("site_field_options_list");
  // Distinct.
  $new_results = [];
  if (!empty($result)) {
    foreach ($result as $item) {
      $new_results[$item->nid] = $item;
    }
  }

  if (!empty($new_results)) {
    foreach ($new_results as $item) {
      $class = $item->node_title;
      $location = (isset($item->field_field_class_location[0]['rendered']['#label'])) ? $item->field_field_class_location[0]['rendered']['#label'] : "";
      $fc_items = (isset($item->field_field_program_day)) ? $item->field_field_program_day : [];
      $p_date = [];
      foreach ($fc_items as $item) {
        $fc_item = reset($item['rendered']['entity']['field_collection_item']);
        $w = isset($fc_item['field_program_weekday'][0]['#markup']) ? $fc_item['field_program_weekday'][0]['#markup'] : "";
        $t_from = isset($fc_item['field_program_time'][0]['#time']['value_formatted']) ? $fc_item['field_program_time'][0]['#time']['value_formatted'] : "";
        $t_to = isset($fc_item['field_program_time'][0]['#time']['value2_formatted']) ? $fc_item['field_program_time'][0]['#time']['value2_formatted'] : "";
        $p_date[$w][] = $t_from . " - " . $t_to;
      }
      $p_date = novo_applications_field_weekday_sort($p_date);
      foreach ($p_date as $weekday => $time_arr) {
        $key = $weekday . ", " . $location . ", " . implode(", ", $time_arr) . " (" . $class . ")";
        $options[$key] = $key;
      }
    }
  }

  return $options;
}

/**
 * Sort weekdays for site virtual field.
 */
function novo_applications_field_weekday_sort($p_date) {
  $week_order = unserialize(NOVO_APPLICATION_WEEKDAY_ORDER);

  uksort($p_date,
    function ($a, $b) use ($week_order) {
      return $week_order[$a] - $week_order[$b];
    });
  return $p_date;
}

/**
 * Sites virtual field custom submit.
 */
function novo_applications_add_sites_virtual_validate(&$form, &$form_state) {
  $virtual = (isset($form_state['values']['field_what_site_you_want_virtual'])) ? $form_state['values']['field_what_site_you_want_virtual'] : NULL;
  $original_field = isset($form['field_what_site_you_want'][LANGUAGE_NONE]) ? $form['field_what_site_you_want'][LANGUAGE_NONE] : NULL;

  if ($virtual && $original_field) {
    if (is_array($virtual)) {
      $names = [];
      // Multi.
      foreach ($virtual as $key => $status) {
        if ($status) {
          $names[] = ['value' => $key];
        }
      }
      form_set_value($original_field, $names, $form_state);
    }
    else {
      // Single.
      form_set_value($original_field[0]['value'], $virtual, $form_state);
    }
  }
}

/**
 * Add dafault expired date.
 */
function novo_applications_add_exp_date_validate(&$form, &$form_state) {
  $lang = isset($form['language']['#value']) ? $form['language']['#value'] : LANGUAGE_NONE;
  $exp_date_value = (isset($form_state['values']['field_expired_date'][$lang][0]['value'])) ? trim($form_state['values']['field_expired_date'][$lang][0]['value']) : NULL;
  if (empty($exp_date_value)) {
    $exp_period = variable_get('novo_master_exp_period', '+36 months');
    $new_exp_date = [$lang => [['value' => strtotime($exp_period)]]];
    form_set_value($form['field_expired_date'], $new_exp_date, $form_state);
  }
}

/**
 * Get first value of field.
 */
function novo_applications_get_field_value($entity_type, $entity, $field) {
  $field = field_get_items($entity_type, $entity, $field);
  return isset($field[0]['value']) ? $field[0]['value'] : "";
}
