<?php

/**
 * @file
 * The primary PHP file for this theme.
 */

define("NOVO_BASE_EMAIL", "volunteer@novoministries.org");
define("NOVO_BASE_PHONE", "4052084255");
define("NOVO_BASE_PHONE_LABEL", "405.208.4255");

novo_theme_load_include("inc", "novo", "includes/novo_theme_form_elements");

/**
 * Implements hook_preprocess_html().
 */
function novo_preprocess_html(&$variables) {

}

/**
 * Implements hook_preprocess_node().
 */
function novo_preprocess_node(&$variables) {
  $variables['theme_hook_suggestions'][] = "node__" . $variables['type'] . "__" . $variables['view_mode'];

  if ($variables['type'] == 'kids') {
    $node = $variables['node'];
    $field_suffix = field_get_items('node', $node, 'field_suffix');
    $suffix = $field_suffix[0]['value'];
    $variables['suffix'] = $suffix;
  }

  // Theme status and approve block.
  if (isset($variables['type']) && $variables['type'] == 'application') {
    if (isset($variables['content']['app_status']['#markup'])) {
      $variables['content']['app_status']['#markup'] = novo_wrap_app_status_label($variables['content']['app_status']['#markup']);
    }
    if (isset($variables['content']['app_approve_block'])) {
      $options = array(
        'weight' => 1000,
        'scope' => 'footer',
      );
      drupal_add_js(drupal_get_path("theme", "novo") . "/js/bootstrap-confirmation.min.js", $options);
      drupal_add_js(drupal_get_path("theme", "novo") . "/js/novo-application-approve.js", $options);
    }
  }
}

/**
 * Implements hook_hook_preprocess_views_view_field().
 */
function novo_preprocess_views_view_field(&$vars) {
  if ($vars['view']->name == "volunteers" && $vars['view']->current_display == "page") {
    if (isset($vars['field']->field) && $vars['field']->field == "novo_application_status") {
      $vars['output'] = novo_wrap_app_status_label($vars['output']);
    }
  }
}

/**
 * Get application status class.
 */
function novo_wrap_app_status_label($text) {
  switch (drupal_strtolower($text)) {
    case "started":
    case "completed":
      $label = "info";
      break;

    case "approved":
      $label = "success";
      break;

    case "not approved":
      $label = "danger";
      break;

    default:
      $label = "default";
  }

  if ($label) {
    $label_html = theme('status_label', array(
      'status' => $text,
      'label' => $label,
    ));
    return $label_html;
  }
}

/**
 * Implements hook_preprocess_page().
 */
function novo_preprocess_page(&$variables) {

  if (in_array("page__children_active_report", $variables['theme_hook_suggestions'])) {
    $variables['container_class'] = "container-fluid";
    $variables['navbar_classes_array'][] = "container-fluid";
  }
  if (isset($variables['navbar_classes_array']) && is_array($variables['navbar_classes_array'])) {
    $variables['navbar_classes_array'][] = 'novo-header';
  }

  if (user_is_anonymous()) {
    $login_pages = array(
      'page__front',
      'page__user',
    );
    if (!empty(array_intersect($login_pages, $variables['theme_hook_suggestions']))) {
      drupal_add_js(drupal_get_path('theme', 'novo') . "/js/login-page.js");
      drupal_add_css(drupal_get_path('theme', 'novo') . "/css/login-page.css", array('group' => CSS_THEME));
      if (isset($variables['page']['content']['system_main']['actions'])) {
        if (isset($variables['tabs'])) {
          $themes = array(
            'menu_local_tasks__login_user',
            $variables['tabs']['#theme'],
          );
          $variables['tabs']['#theme'] = $themes;
          $variables['page']['content']['system_main']['actions']['links'] = $variables['tabs'];
          $variables['page']['content']['system_main']['actions']['links']['#weight'] = 6;
          unset($variables['tabs']['#primary']);
        }
      }
      $variables['logo'] = drupal_get_path('theme', 'novo') . "/images/novo-logo-gray.png";
      if (isset($variables['page']['content']['system_main']['account']['pass']['pass1'])) {
        $pass_1 = &$variables['page']['content']['system_main']['account']['pass']['pass1'];

        $pass_1['#attributes']['placeholder'] = $pass_1['#title'];
        $pass_1['#title'] = '';
      }

      if (isset($variables['page']['content']['system_main']['account']['pass']['pass2'])) {
        $pass_2 = &$variables['page']['content']['system_main']['account']['pass']['pass2'];

        $pass_2['#attributes']['placeholder'] = $pass_2['#title'];
        $pass_2['#title'] = '';
      }
      if (isset($variables['page']['content']['system_main']['field_u_birthday']['und'][0])) {
        $date_of_birthday = &$variables['page']['content']['system_main']['field_u_birthday']['und'][0];

        $date_of_birthday['value']['date']['#attributes']['placeholder'] = $date_of_birthday['value']['date']['#title'];

        $date_of_birthday['#title'] = '';
        $date_of_birthday['value']['date']['#title'] = '';
        $date_of_birthday['value']['date']['#default_value'] = '';
        $date_of_birthday['value']['#date_title'] = '';
        $date_of_birthday['value']['date']['#value'] = '';

      }
    }
  }

}

/**
 * Theme theme_menu_local_tasks().
 */
function novo_menu_local_tasks__login_user(&$variables) {
  $output = '';

  if (!empty($variables['primary'])) {
    foreach ($variables['primary'] as $key => $item) {
      $theme_array = array(
        'menu_local_task__login_user',
        $variables['primary'][$key]['#theme'],
      );
      $variables['primary'][$key]['#theme'] = $theme_array;
      if (isset($item['#active']) && !empty($item['#active'])) {
        unset($variables['primary'][$key]);
      }
    }
    $output .= drupal_render($variables['primary']);
  }
  return $output;
}

/**
 * Theme theme_menu_local_task().
 */
function novo_menu_local_task__login_user(&$variables) {
  $element = $variables['element'];
  $output = '';
  switch ($element['#link']['href']) {
    case 'user/register':
      $output = l(t('Register'), $element['#link']['href'], array(
        'attributes' => array(
          'class' => array(
            'btn',
            'btn-primary',
          ),
        ),
      ));
      break;

    case 'user/password':
      $output = l(t('Restore Password'), $element['#link']['href'], array(
        'attributes' => array(
          'class' => array(
            'btn',
            'btn-rest',
          ),
        ),
      ));
      break;
  }
  return $output;

}

/**
 * Implements hook_preprocess_form().
 */
function novo_preprocess_form(&$variables) {

}

/**
 * Implements hook_preprocess_field().
 */
function novo_preprocess_field(&$variables) {
  $node = $variables['element']['#object'];

  if (isset($node->type) && ($node->type == 'application' || $node->type == 'kids' || $node->type == 'partner')) {

    switch ($variables['element']['#field_name']) {
      case 'field_phone':
        $variables['icon'] = 'phone';
        break;

      case 'field_email':
        $variables['icon'] = 'envelope';
        break;

      case 'field_address_1':
        $variables['icon'] = 'home';
        $field_address_2 = field_get_items('node', $node, 'field_address_2');
        $value_address_2 = field_view_value('node', $node, 'field_address_2', $field_address_2[0]);
        if (!empty($value_address_2['#markup'])) {
          $variables['items'][] = $value_address_2;
        }
        break;

      case 'field_dob':
        $variables['icon'] = 'calendar';
        break;

      case 'field_city':
        $variables['icon'] = 'globe';
        $field_state = field_get_items('node', $node, 'field_state');

        if (!empty($field_state)) {
          $term_id = $field_state[0]['tid'];
          $state_term = taxonomy_term_load($term_id);
          $variables['items'][0]['#markup'] .= '/' . $state_term->description;

          $field_state_info = field_info_instance('node', 'field_state', 'application');
          $variables['label'] .= '/' . $field_state_info['label'];
        }
        break;

      case 'field_reference_request_1':
      case 'field_reference_request_2':
      case 'field_reference_request_standby':
      case 'field_reference_request_parents':
      case 'field_reference_request_church':
        $variables['theme_hook_suggestions'][] = 'field__field_reference_request';

        break;
    }

    // @codingStandardsIgnoreStart

//    if ("field_reference_request_1" == $variables['element']['#field_name']) {
//      kpr($variables);
//    }

    // @codingStandardsIgnoreEnd
  }
}

/**
 * Implements hook_theme().
 */
function novo_theme($existing, $type, $theme, $path) {

  return array(
    'status_label' => array(
      'variables' => array('status' => NULL, 'label' => NULL),
      'template' => 'templates/custom/status-label',
    ),
    'textfield__calendar_icon' => array(
      'render element' => 'element',
    ),
    'date_form_element__date_of_birthday' => array(
      'render element' => 'element',
    ),
  );
}

/**
 * Analog module_load_include.
 */
function novo_theme_load_include($type, $theme, $name = NULL) {
  static $files = array();

  if (!isset($name)) {
    $name = $theme;
  }

  $key = $type . ':' . $theme . ':' . $name;
  if (isset($files[$key])) {
    return $files[$key];
  }
  //@codingStandardsIgnoreStart
  if (function_exists('drupal_get_path')) {
    $file = DRUPAL_ROOT . '/' . drupal_get_path('theme', $theme) . "/$name.$type";
    if (is_file($file)) {
      require_once $file;
      $files[$key] = $file;
      return $file;
    }
    else {
      $files[$key] = FALSE;
    }
  }
  //@codingStandardsIgnoreEnd
  return FALSE;
}

/**
 * Implements hook_menu_tree__menu_program_menu().
 */
function novo_menu_tree__menu_program_menu(&$variables) {
  return '<ul class="nav nav-tabs">' . $variables['tree'] . '</ul>';
}

/**
 * Block visibility callback for the search form block.
 *
 * @param object $block
 *   The block object.
 *
 * @return bool
 *   TRUE if the block should be displayed on the current page.
 */
function _novo_menu_menu_program_menu_block_visibility($block) {
  $arg0 = arg(0);
  $arg1 = arg(1);
  $arg2 = arg(2);
  if ($arg0 == 'node' && is_numeric($arg1) && $arg2 == 'edit') {
    $node = node_load($arg1);
    if (isset($node->type)) {
      // @codingStandardsIgnoreStart
      switch ($node->type) {
        case "program":
        case "locations":
        case "mentors":
        case "attendance":
        case "class":
          return TRUE;
          break;
      }
      // @codingStandardsIgnoreEnd
    }
  }

  $pages = isset($block->pages) ? explode(PHP_EOL, $block->pages) : array();
  $pages = array_map("trim", $pages);
  return (in_array(trim($_GET['q']), $pages)) ? TRUE : FALSE;

}

/**
 * Implements hook_preprocess_block().
 */
function novo_preprocess_block(&$variables) {
  if ($variables['block']->module == "webform") {
    $variables['theme_hook_suggestions'][] = "block__webform__contact_us";
  }
}

/**
 * Implements hook_elements_info_alter().
 */
function novo_element_info_alter(&$type) {
  if (isset($type['textfield'])) {
    $type['textfield']['#pre_render'][] = '_novo_pre_render_textfield';
  }
}

/**
 * Pre render for text field.
 */
function _novo_pre_render_textfield($variable) {
  $fields_calendar_icon = array(
    'field_dob',
    'field_attendance_date_value',
    'field_attendance_date_value_1',
  );
  if (isset($variable['#array_parents']) && (!empty(array_intersect($fields_calendar_icon, $variable['#array_parents'])))) {
    $variable['#theme'] = ['textfield__calendar_icon'];
  };
  return $variable;
}

/**
 * Theme function for textfield__calendar_icon.
 */
function novo_textfield__calendar_icon($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'text';
  element_set_attributes($element, [
    'id',
    'name',
    'value',
    'size',
    'maxlength',
  ]);
  _form_set_class($element, ['form-text']);

  $output = '<input' . drupal_attributes($element['#attributes']) . ' />';
  $input_id = isset($element['#attributes']['id']) ? $element['#attributes']['id'] : '';

  $output .= '<label class="input-group-addon btn" for="' . $input_id . '"><span class="glyphicon glyphicon-calendar" aria-hidden="true"></span></label>';
  if (!isset($element['#input_group']) && !isset($element['#input_group_button'])) {
    $input_group_attributes = isset($element['#input_group_attributes']) ? $element['#input_group_attributes'] : [];
    if (!isset($input_group_attributes['class'])) {
      $input_group_attributes['class'] = [];
    }
    if (!in_array('input-group', $input_group_attributes['class'])) {
      $input_group_attributes['class'][] = 'input-group';
      $input_group_attributes['class'][] = 'novo-input-group';
    }
    $output = '<div' . drupal_attributes($input_group_attributes) . '>' . $output . '</div>';
  }

  return $output;
}

/**
 * Implements hook_menu_link__user_menu().
 */
function novo_menu_link__user_menu(array $variables) {

  $element = $variables['element'];
  $sub_menu = '';

  $options = !empty($element['#localized_options']) ? $element['#localized_options'] : [];

  // Check plain title if "html" is not set, otherwise, filter for XSS attacks.
  $title = empty($options['html']) ? check_plain($element['#title']) : filter_xss_admin($element['#title']);

  // Ensure "html" is now enabled so l() doesn't double encode. This is now
  // safe to do since both check_plain() and filter_xss_admin() encode HTML
  // entities. See: https://www.drupal.org/node/2854978
  $options['html'] = TRUE;

  $href = $element['#href'];
  $attributes = !empty($element['#attributes']) ? $element['#attributes'] : [];

  if ($element['#below']) {
    // Prevent dropdown functions from being added to management menu so it
    // does not affect the navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }
    elseif ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] == 1)) {
      // Add our own wrapper.
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';

      // Generate as standard dropdown.
      $title .= ' <span class="caret"></span>';
      $attributes['class'][] = 'dropdown';

      // Set dropdown trigger element to # to prevent inadvertant page loading
      // when a submenu link is clicked.
      $options['attributes']['data-target'] = '#';
      $options['attributes']['class'][] = 'dropdown-toggle';
      $options['attributes']['data-toggle'] = 'dropdown';
    }
  }

  if (trim(strtolower($title)) == 'my account') {
    $title = '<span class="glyphicon novo-glyphicon glyphicon-user" aria-hidden="true"></span>';
  }

  if (trim(strtolower($title)) == 'log out') {
    $title = '<span class="glyphicon novo-glyphicon glyphicon-arrow-right" aria-hidden="true"></span>';
  }
  $attributes['class'][] = 'novo-leaf';

  return '<li' . drupal_attributes($attributes) . '>' . l($title, $href, $options) . $sub_menu . "</li>\n";
}

/**
 * Implements hook_preprocess_button().
 */
function novo_preprocess_button(&$vars) {
  if (isset($vars['element']['#value'])) {

    if ($vars['element']['#value'] == 'Remove') {
      $vars['element']['#icon'] = '<span class="glyphicon glyphicon-remove novo-glyphicon-remove" aria-hidden="true"></span>';
      $vars['element']['#value'] = '';
    }

    if ($vars['element']['#value'] == 'Add another item') {
      $vars['element']['#value'] = 'Add';
      $vars['element']['#icon_position'] = 'after';
    }
    if (isset($vars['element']['#attributes']['class']) && !user_is_anonymous()) {
      $vars['element']['#attributes']['class'][] = 'btn-sm';
    }
  }
}

/**
 * Implements hook_preprocess_taxonomy_term().
 */
function novo_preprocess_taxonomy_term(&$variables) {
  // kpr($variables);
}

/**
 * Implements hook_preprocess_views_view_table().
 */
function novo_preprocess_views_view_table(&$vars) {
  // Moved kids.
  if ($vars['view']->name == "kids") {
    foreach ($vars['rows'] as $key => $value) {
      if (strpos($value['title'], "novo-title-moved-1") !== FALSE) {
        $vars['row_classes'][$key][] = "novo-title-moved-wrapper";
      }
    }
  }

  // If this view is not the sort view, then stop here.
  if (!isset($vars['view']->field['draggableviews'])) {
    return;
  }

  // Check permissions.
  if (!user_access('access draggableviews')) {
    // Remove column "draggableviews" from results and header.
    foreach ($vars['rows'] as &$row) {
      unset($row['draggableviews']);
    }
    unset($vars['header']['draggableviews']);
    return;
  }

  // Add JavaScript for auto-save functionality.
  if ($vars['view']->field['draggableviews']->options['draggableviews']['ajax']) {
    drupal_add_js(drupal_get_path('theme', 'novo') . '/js/novo_draggableviews_table.js', array('scope' => 'footer'));
  }
}

/**
 * Implements hook_form_alter().
 */
function novo_form_alter(&$form, &$form_state, &$form_id) {
  $login_forms = array(
    'user_login',
    'user_login_block',
    'user_register_form',
    'user_pass',
  );
  $lang = isset($form['language']['#value']) ? $form['language']['#value'] : LANGUAGE_NONE;

  if (strpos($form_id, 'webform_client_form') !== FALSE) {
    if (isset($form['#attributes']['class'])) {
      $form['#attributes']['class'][] = 'novo-web-form';
    }
  }
  if (isset($form['field_dob'])) {
    $form['field_dob'][$lang][0]['#theme_wrappers'][0] = 'date_form_element__date_of_birthday';
  }
  if (isset($form['#attributes']['class']) && !in_array($form_id, $login_forms)) {
    $form['#attributes']['class'][] = 'novo-form';
  }
  if ($form_id == "user_login_block") {
    if (isset($form['actions']) && isset($form['links'])) {
      $items[] = l(t('Register'), 'user/register', array('attributes' => array('title' => t('Create a new user account.'))));
      $items[] = l(t('Restore Password'), 'user/password', array('attributes' => array('title' => t('Request new password via e-mail.'))));
      $form['actions']['links'] = array('#markup' => theme('item_list', array('items' => $items)));
      unset($form['links']);
    }
  }
  if (in_array($form_id, $login_forms)) {
    $form['#attributes']['class'][] = 'novo-login-form';
    if (isset($form['pass'])) {
      $form['pass']['#attributes']['placeholder'] = $form['pass']['#title'];
      $form['pass']['#title'] = '';
    }

    if (isset($form['name'])) {
      $form['name']['#attributes']['placeholder'] = $form['name']['#title'];
      $form['name']['#title'] = '';
    }

    $form['help'] = array(
      '#markup' => l('<span class="glyphicon glyphicon-question-sign "></span>' . t('Need help logging in?'), '/\#', array(
        'attributes' => array(
          'data-target' => '#novo-contact-us-block',
          'data-toggle' => 'modal',
          'class' => array(
            'novo-login-help',
          ),
        ),
        'html' => TRUE,
      )),
    );
    $form['help']['#weight'] = 110;
    if (($form_id == 'user_register_form' || $form_id == 'user_pass') && isset($form['actions'])) {

      if ($form_id == 'user_register_form') {
        $form['actions']['submit']['#value'] = t('Register');
        $form['actions']['submit']['#weight'] = 5;
      }

      if ($form_id == 'user_pass') {
        $form['actions']['submit']['#value'] = t('Send password');
        $form['actions']['submit']['#weight'] = 10;
      }

      $form['actions']['submit']['#attributes']['class'] = array(
        'btn',
        'btn-primary',
        'btn-submit',
      );
      $login_txt = '<span class="icon glyphicon glyphicon-log-in" aria-hidden="true"></span>  ' . t('Log in');
      $form['actions']['login']['#markup'] = l($login_txt, '/', array(
        'attributes' => array(
          'class' => array(
            'btn',
            'btn-primary',
            'btn-login',
          ),
        ),
        'html' => TRUE,
      ));
    }

    $form_fields = array(
      'field_u_first_name',
      'field_u_last_name',
    );
    foreach ($form_fields as $field) {
      if (array_key_exists($field, $form)) {
        if (isset($form[$field][$lang][0]['value'])) {
          $form[$field][$lang][0]['value']['#attributes']['placeholder'] = $form[$field][$lang][0]['#title'];
          $form[$field][$lang][0]['value']['#title'] = '';
        }
      }
    }

    if (isset($form['field_u_birthday'])) {
      $form['field_u_birthday']['#weight'] = 10;
    }
    if (isset($form['account']['mail'])) {
      $form['account']['mail']['#attributes']['placeholder'] = $form['account']['mail']['#title'];
      $form['account']['mail']['#title'] = '';
    }
  }
}

/**
 * Theme function for date_form_element__date_of_birthday.
 */
function novo_date_form_element__date_of_birthday($variables) {
  $element = &$variables['element'];

  // Detect whether element is multiline.
  $count = preg_match_all('`<(?:div|span)\b[^>]* class="[^"]*\b(?:date-no-float|date-clear)\b`', $element['#children'], $matches, PREG_OFFSET_CAPTURE);
  $multiline = FALSE;
  if ($count > 1) {
    $multiline = TRUE;
  }
  elseif ($count) {
    $before = substr($element['#children'], 0, $matches[0][0][1]);
    if (preg_match('`<(?:div|span)\b[^>]* class="[^"]*\bdate-float\b`', $before)) {
      $multiline = TRUE;
    }
  }

  // Detect if there is more than one subfield.
  $element['#title_display'] = 'none';

  // Wrap children with a div and add an extra class if element is multiline.
  $element['#children'] = '<div class="date-form-element-content' . ($multiline ? ' date-form-element-content-multiline' : '') . '">' . $element['#children'] . '</div>';

  return theme('form_element', $variables);
}

/**
 * Implements hook_field_widget_form_alter().
 */
function novo_field_widget_form_alter(&$element, &$form_state, $context) {
  if (isset($element['#field_name']) && ($element['#field_name'] == 'field_program_time')) {
    if (isset($element['value'])) {
      $element['value']['#title'] = t('Start Time');
    }
  }
}

/**
 * Implements theme_views_data_export_feed_icon__xls().
 */
function novo_views_data_export_feed_icon__xls($variables) {
  extract($variables, EXTR_SKIP);
  $url_options = array('html' => TRUE);
  if ($query) {
    $url_options['query'] = $query;
  }
  $url_options['attributes']['class'] = array(
    "btn",
    "btn-default",
    "btn-xs",
    "novo-export-feed-icon",
  );
  $text = '<i class="glyphicon glyphicon-file"></i>' . t("XLS");
  return l($text, $url, $url_options);
}

/**
 * Implements theme_views_data_export_feed_icon__pdf().
 */
function novo_views_data_export_feed_icon__pdf($variables) {
  extract($variables, EXTR_SKIP);
  $url_options = array('html' => TRUE);
  if ($query) {
    $url_options['query'] = $query;
  }
  $url_options['attributes']['class'] = array(
    "btn",
    "btn-default",
    "btn-xs",
    "novo-export-feed-icon",
  );
  $text = '<i class="glyphicon glyphicon-file"></i>' . t("PDF");
  return l($text, $url, $url_options);
}
