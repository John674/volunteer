<?php
/**
 * @file
 * novo_views_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function novo_views_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'attendance';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Attendance';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Attendance';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'plain_text',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'field_program_location_target_id_entityreference_filter' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_attendance_program_name_target_id_entityreference_filter' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'status' => 'status',
    'nid' => 'nid',
    'field_attendance_program_name' => 'field_attendance_program_name',
    'field_attendance_date' => 'field_attendance_date',
    'field_attendance_kids_list' => 'field_attendance_kids_list',
    'field_attendance_staff_list' => 'field_attendance_staff_list',
    'field_attendance_volunteer_list' => 'field_attendance_volunteer_list',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_attendance_program_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_attendance_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_attendance_kids_list' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_attendance_staff_list' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_attendance_volunteer_list' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="novo-no-data-found">No data found.</div>';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_attendance_program_name_target_id']['id'] = 'field_attendance_program_name_target_id';
  $handler->display->display_options['relationships']['field_attendance_program_name_target_id']['table'] = 'field_data_field_attendance_program_name';
  $handler->display->display_options['relationships']['field_attendance_program_name_target_id']['field'] = 'field_attendance_program_name_target_id';
  $handler->display->display_options['relationships']['field_attendance_program_name_target_id']['label'] = 'Program';
  $handler->display->display_options['relationships']['field_attendance_program_name_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_location_target_id']['id'] = 'field_program_location_target_id';
  $handler->display->display_options['relationships']['field_program_location_target_id']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['relationships']['field_program_location_target_id']['field'] = 'field_program_location_target_id';
  $handler->display->display_options['relationships']['field_program_location_target_id']['relationship'] = 'field_attendance_program_name_target_id';
  $handler->display->display_options['relationships']['field_program_location_target_id']['label'] = 'Location';
  $handler->display->display_options['relationships']['field_program_location_target_id']['required'] = TRUE;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = '';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['type'] = 'boolean';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_attendance_program_name_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'Class name';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Attendance date */
  $handler->display->display_options['fields']['field_attendance_date']['id'] = 'field_attendance_date';
  $handler->display->display_options['fields']['field_attendance_date']['table'] = 'field_data_field_attendance_date';
  $handler->display->display_options['fields']['field_attendance_date']['field'] = 'field_attendance_date';
  $handler->display->display_options['fields']['field_attendance_date']['label'] = 'Date';
  $handler->display->display_options['fields']['field_attendance_date']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: COUNT(DISTINCT Content: Kids list) */
  $handler->display->display_options['fields']['field_attendance_kids_list']['id'] = 'field_attendance_kids_list';
  $handler->display->display_options['fields']['field_attendance_kids_list']['table'] = 'field_data_field_attendance_kids_list';
  $handler->display->display_options['fields']['field_attendance_kids_list']['field'] = 'field_attendance_kids_list';
  $handler->display->display_options['fields']['field_attendance_kids_list']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['field_attendance_kids_list']['label'] = 'Kids';
  $handler->display->display_options['fields']['field_attendance_kids_list']['separator'] = ', ';
  /* Field: COUNT(DISTINCT Content: Staff list) */
  $handler->display->display_options['fields']['field_attendance_staff_list']['id'] = 'field_attendance_staff_list';
  $handler->display->display_options['fields']['field_attendance_staff_list']['table'] = 'field_data_field_attendance_staff_list';
  $handler->display->display_options['fields']['field_attendance_staff_list']['field'] = 'field_attendance_staff_list';
  $handler->display->display_options['fields']['field_attendance_staff_list']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['field_attendance_staff_list']['label'] = 'Staff';
  $handler->display->display_options['fields']['field_attendance_staff_list']['separator'] = ', ';
  /* Field: COUNT(DISTINCT Content: Volunteer list) */
  $handler->display->display_options['fields']['field_attendance_volunteer_list']['id'] = 'field_attendance_volunteer_list';
  $handler->display->display_options['fields']['field_attendance_volunteer_list']['table'] = 'field_data_field_attendance_volunteer_list';
  $handler->display->display_options['fields']['field_attendance_volunteer_list']['field'] = 'field_attendance_volunteer_list';
  $handler->display->display_options['fields']['field_attendance_volunteer_list']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['field_attendance_volunteer_list']['label'] = 'Volunteers';
  $handler->display->display_options['fields']['field_attendance_volunteer_list']['separator'] = ', ';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Options';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'attendance' => 'attendance',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Year (field_attendance_year) */
  $handler->display->display_options['filters']['field_attendance_year_year']['id'] = 'field_attendance_year_year';
  $handler->display->display_options['filters']['field_attendance_year_year']['table'] = 'field_data_field_attendance_year';
  $handler->display->display_options['filters']['field_attendance_year_year']['field'] = 'field_attendance_year_year';
  $handler->display->display_options['filters']['field_attendance_year_year']['group'] = 1;
  $handler->display->display_options['filters']['field_attendance_year_year']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_attendance_year_year']['expose']['operator_id'] = 'field_attendance_year_year_op';
  $handler->display->display_options['filters']['field_attendance_year_year']['expose']['label'] = 'Filter by Year';
  $handler->display->display_options['filters']['field_attendance_year_year']['expose']['operator'] = 'field_attendance_year_year_op';
  $handler->display->display_options['filters']['field_attendance_year_year']['expose']['identifier'] = 'field_attendance_year_year';
  $handler->display->display_options['filters']['field_attendance_year_year']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Location (field_program_location) (reference filter) */
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['id'] = 'field_program_location_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['field'] = 'field_program_location_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['relationship'] = 'field_attendance_program_name_target_id';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['operator_id'] = 'field_program_location_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['label'] = 'Filter by Location';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['operator'] = 'field_program_location_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['identifier'] = 'field_program_location_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['hide_empty_filter'] = FALSE;
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['reference_display'] = 'attendance_filter_locations:entityreference_1';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['reference_arguments'] = '[field_attendance_year_year]';
  /* Filter criterion: Content: Program name (field_attendance_program_name) (reference filter) */
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['id'] = 'field_attendance_program_name_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['table'] = 'field_data_field_attendance_program_name';
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['field'] = 'field_attendance_program_name_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['expose']['operator_id'] = 'field_attendance_program_name_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['expose']['label'] = 'Filter by Class';
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['expose']['operator'] = 'field_attendance_program_name_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['expose']['identifier'] = 'field_attendance_program_name_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['expose']['hide_empty_filter'] = FALSE;
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['reference_display'] = 'attendance_filter_programs:entityreference_1';
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['reference_arguments'] = '[field_attendance_year_year]/[field_program_location_target_id_entityreference_filter]';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'attendance';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Attendance';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-program-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['attendance'] = $view;

  $view = new view();
  $view->name = 'attendance_filter_locations';
  $view->description = '';
  $view->tag = 'REF';
  $view->base_table = 'node';
  $view->human_name = 'Attendance Filter Locations (REF)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: In Program */
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['id'] = 'reverse_field_program_location_node';
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['field'] = 'reverse_field_program_location_node';
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['ui_name'] = 'In Program';
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['label'] = 'In Program';
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['required'] = TRUE;
  /* Relationship: In Attendance */
  $handler->display->display_options['relationships']['reverse_field_attendance_program_name_node']['id'] = 'reverse_field_attendance_program_name_node';
  $handler->display->display_options['relationships']['reverse_field_attendance_program_name_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_attendance_program_name_node']['field'] = 'reverse_field_attendance_program_name_node';
  $handler->display->display_options['relationships']['reverse_field_attendance_program_name_node']['relationship'] = 'reverse_field_program_location_node';
  $handler->display->display_options['relationships']['reverse_field_attendance_program_name_node']['ui_name'] = 'In Attendance';
  $handler->display->display_options['relationships']['reverse_field_attendance_program_name_node']['label'] = 'In Attendance';
  $handler->display->display_options['relationships']['reverse_field_attendance_program_name_node']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: School year (field_program_year) */
  $handler->display->display_options['arguments']['field_program_year_year']['id'] = 'field_program_year_year';
  $handler->display->display_options['arguments']['field_program_year_year']['table'] = 'field_data_field_program_year';
  $handler->display->display_options['arguments']['field_program_year_year']['field'] = 'field_program_year_year';
  $handler->display->display_options['arguments']['field_program_year_year']['relationship'] = 'reverse_field_program_location_node';
  $handler->display->display_options['arguments']['field_program_year_year']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_program_year_year']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_program_year_year']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_program_year_year']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'locations' => 'locations',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'reverse_field_program_location_node';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'program' => 'program',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_2']['id'] = 'type_2';
  $handler->display->display_options['filters']['type_2']['table'] = 'node';
  $handler->display->display_options['filters']['type_2']['field'] = 'type';
  $handler->display->display_options['filters']['type_2']['relationship'] = 'reverse_field_attendance_program_name_node';
  $handler->display->display_options['filters']['type_2']['value'] = array(
    'attendance' => 'attendance',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $export['attendance_filter_locations'] = $view;

  $view = new view();
  $view->name = 'attendance_filter_programs';
  $view->description = '';
  $view->tag = 'REF';
  $view->base_table = 'node';
  $view->human_name = 'Attendance Filter Programs (REF)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: In attendance */
  $handler->display->display_options['relationships']['reverse_field_attendance_program_name_node']['id'] = 'reverse_field_attendance_program_name_node';
  $handler->display->display_options['relationships']['reverse_field_attendance_program_name_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_attendance_program_name_node']['field'] = 'reverse_field_attendance_program_name_node';
  $handler->display->display_options['relationships']['reverse_field_attendance_program_name_node']['ui_name'] = 'In attendance';
  $handler->display->display_options['relationships']['reverse_field_attendance_program_name_node']['label'] = 'In attendance';
  $handler->display->display_options['relationships']['reverse_field_attendance_program_name_node']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: School year (field_program_year) */
  $handler->display->display_options['arguments']['field_program_year_year']['id'] = 'field_program_year_year';
  $handler->display->display_options['arguments']['field_program_year_year']['table'] = 'field_data_field_program_year';
  $handler->display->display_options['arguments']['field_program_year_year']['field'] = 'field_program_year_year';
  $handler->display->display_options['arguments']['field_program_year_year']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_program_year_year']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_program_year_year']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_program_year_year']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Location (field_program_location) */
  $handler->display->display_options['arguments']['field_program_location_target_id']['id'] = 'field_program_location_target_id';
  $handler->display->display_options['arguments']['field_program_location_target_id']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['arguments']['field_program_location_target_id']['field'] = 'field_program_location_target_id';
  $handler->display->display_options['arguments']['field_program_location_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_program_location_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_program_location_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_program_location_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program' => 'program',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'reverse_field_attendance_program_name_node';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'attendance' => 'attendance',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['attendance_filter_programs'] = $view;

  $view = new view();
  $view->name = 'attendance_kids_list';
  $view->description = '';
  $view->tag = 'REF';
  $view->base_table = 'node';
  $view->human_name = 'Attendance Kids List (REF)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['separator'] = '-';
  /* Relationship: In Program */
  $handler->display->display_options['relationships']['reverse_field_p_kid_name_field_collection_item']['id'] = 'reverse_field_p_kid_name_field_collection_item';
  $handler->display->display_options['relationships']['reverse_field_p_kid_name_field_collection_item']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_p_kid_name_field_collection_item']['field'] = 'reverse_field_p_kid_name_field_collection_item';
  $handler->display->display_options['relationships']['reverse_field_p_kid_name_field_collection_item']['ui_name'] = 'In Program';
  $handler->display->display_options['relationships']['reverse_field_p_kid_name_field_collection_item']['label'] = 'In Program';
  $handler->display->display_options['relationships']['reverse_field_p_kid_name_field_collection_item']['required'] = TRUE;
  /* Relationship: Field collection item: Entity with the Kids list (field_program_kids_list) */
  $handler->display->display_options['relationships']['field_program_kids_list_node']['id'] = 'field_program_kids_list_node';
  $handler->display->display_options['relationships']['field_program_kids_list_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_program_kids_list_node']['field'] = 'field_program_kids_list_node';
  $handler->display->display_options['relationships']['field_program_kids_list_node']['relationship'] = 'reverse_field_p_kid_name_field_collection_item';
  $handler->display->display_options['relationships']['field_program_kids_list_node']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_p_kid_name_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_program_kids_list_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'kids' => 'kids',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'title_1' => 'title_1',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['attendance_kids_list'] = $view;

  $view = new view();
  $view->name = 'attendance_locations_list';
  $view->description = '';
  $view->tag = 'REF';
  $view->base_table = 'node';
  $view->human_name = 'Attendance Locations list (REF)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: In Program */
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['id'] = 'reverse_field_program_location_node';
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['field'] = 'reverse_field_program_location_node';
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['ui_name'] = 'In Program';
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['label'] = 'In Program';
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: School year (field_program_year) */
  $handler->display->display_options['arguments']['field_program_year_year']['id'] = 'field_program_year_year';
  $handler->display->display_options['arguments']['field_program_year_year']['table'] = 'field_data_field_program_year';
  $handler->display->display_options['arguments']['field_program_year_year']['field'] = 'field_program_year_year';
  $handler->display->display_options['arguments']['field_program_year_year']['relationship'] = 'reverse_field_program_location_node';
  $handler->display->display_options['arguments']['field_program_year_year']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_program_year_year']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_program_year_year']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_program_year_year']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'locations' => 'locations',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'reverse_field_program_location_node';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'program' => 'program',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['attendance_locations_list'] = $view;

  $view = new view();
  $view->name = 'attendance_programs';
  $view->description = '';
  $view->tag = 'REF';
  $view->base_table = 'node';
  $view->human_name = 'Attendance Programs list(REF)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: School year (field_program_year) */
  $handler->display->display_options['arguments']['field_program_year_year']['id'] = 'field_program_year_year';
  $handler->display->display_options['arguments']['field_program_year_year']['table'] = 'field_data_field_program_year';
  $handler->display->display_options['arguments']['field_program_year_year']['field'] = 'field_program_year_year';
  $handler->display->display_options['arguments']['field_program_year_year']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_program_year_year']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_program_year_year']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_program_year_year']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Location (field_program_location) */
  $handler->display->display_options['arguments']['field_program_location_target_id']['id'] = 'field_program_location_target_id';
  $handler->display->display_options['arguments']['field_program_location_target_id']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['arguments']['field_program_location_target_id']['field'] = 'field_program_location_target_id';
  $handler->display->display_options['arguments']['field_program_location_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_program_location_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_program_location_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_program_location_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program' => 'program',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['attendance_programs'] = $view;

  $view = new view();
  $view->name = 'attendance_records_of_volunteer';
  $view->description = '';
  $view->tag = 'DYN';
  $view->base_table = 'node';
  $view->human_name = 'Attendance records of Volunteer';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Attendance Records of Volunteer';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'plain_text',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'title' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_attendance_date_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
        'datepicker_options' => '',
      ),
    ),
    'field_attendance_date_value_1' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
        'datepicker_options' => '',
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'field_attendance_program_name' => 'field_attendance_program_name',
    'field_attendance_date' => 'field_attendance_date',
    'edit_node' => 'edit_node',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_attendance_program_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_attendance_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['empty'] = TRUE;
  $handler->display->display_options['footer']['result']['content'] = 'Total @total visit';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="novo-no-data-found">No data found.</div>';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_attendance_volunteer_list_target_id']['id'] = 'field_attendance_volunteer_list_target_id';
  $handler->display->display_options['relationships']['field_attendance_volunteer_list_target_id']['table'] = 'field_data_field_attendance_volunteer_list';
  $handler->display->display_options['relationships']['field_attendance_volunteer_list_target_id']['field'] = 'field_attendance_volunteer_list_target_id';
  $handler->display->display_options['relationships']['field_attendance_volunteer_list_target_id']['label'] = 'Volunteers';
  $handler->display->display_options['relationships']['field_attendance_volunteer_list_target_id']['required'] = TRUE;
  /* Field: Content: Program name */
  $handler->display->display_options['fields']['field_attendance_program_name']['id'] = 'field_attendance_program_name';
  $handler->display->display_options['fields']['field_attendance_program_name']['table'] = 'field_data_field_attendance_program_name';
  $handler->display->display_options['fields']['field_attendance_program_name']['field'] = 'field_attendance_program_name';
  $handler->display->display_options['fields']['field_attendance_program_name']['label'] = 'Class name';
  $handler->display->display_options['fields']['field_attendance_program_name']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Attendance date */
  $handler->display->display_options['fields']['field_attendance_date']['id'] = 'field_attendance_date';
  $handler->display->display_options['fields']['field_attendance_date']['table'] = 'field_data_field_attendance_date';
  $handler->display->display_options['fields']['field_attendance_date']['field'] = 'field_attendance_date';
  $handler->display->display_options['fields']['field_attendance_date']['label'] = 'Attendancy Date';
  $handler->display->display_options['fields']['field_attendance_date']['settings'] = array(
    'format_type' => 'long',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_attendance_volunteer_list_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'Volunteer Name';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Attendance date (field_attendance_date) */
  $handler->display->display_options['sorts']['field_attendance_date_value']['id'] = 'field_attendance_date_value';
  $handler->display->display_options['sorts']['field_attendance_date_value']['table'] = 'field_data_field_attendance_date';
  $handler->display->display_options['sorts']['field_attendance_date_value']['field'] = 'field_attendance_date_value';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'attendance' => 'attendance',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_attendance_volunteer_list_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Attendance date (field_attendance_date) */
  $handler->display->display_options['filters']['field_attendance_date_value']['id'] = 'field_attendance_date_value';
  $handler->display->display_options['filters']['field_attendance_date_value']['table'] = 'field_data_field_attendance_date';
  $handler->display->display_options['filters']['field_attendance_date_value']['field'] = 'field_attendance_date_value';
  $handler->display->display_options['filters']['field_attendance_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_attendance_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_attendance_date_value']['expose']['operator_id'] = 'field_attendance_date_value_op';
  $handler->display->display_options['filters']['field_attendance_date_value']['expose']['label'] = 'Filter by start date';
  $handler->display->display_options['filters']['field_attendance_date_value']['expose']['operator'] = 'field_attendance_date_value_op';
  $handler->display->display_options['filters']['field_attendance_date_value']['expose']['identifier'] = 'field_attendance_date_value';
  $handler->display->display_options['filters']['field_attendance_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_attendance_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_attendance_date_value']['year_range'] = '-50:+3';
  /* Filter criterion: Content: Attendance date (field_attendance_date) */
  $handler->display->display_options['filters']['field_attendance_date_value_1']['id'] = 'field_attendance_date_value_1';
  $handler->display->display_options['filters']['field_attendance_date_value_1']['table'] = 'field_data_field_attendance_date';
  $handler->display->display_options['filters']['field_attendance_date_value_1']['field'] = 'field_attendance_date_value';
  $handler->display->display_options['filters']['field_attendance_date_value_1']['operator'] = '<=';
  $handler->display->display_options['filters']['field_attendance_date_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_attendance_date_value_1']['expose']['operator_id'] = 'field_attendance_date_value_1_op';
  $handler->display->display_options['filters']['field_attendance_date_value_1']['expose']['label'] = 'Filter by end date';
  $handler->display->display_options['filters']['field_attendance_date_value_1']['expose']['operator'] = 'field_attendance_date_value_1_op';
  $handler->display->display_options['filters']['field_attendance_date_value_1']['expose']['identifier'] = 'field_attendance_date_value_1';
  $handler->display->display_options['filters']['field_attendance_date_value_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_attendance_date_value_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_attendance_date_value_1']['year_range'] = '-50:+3';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Program name */
  $handler->display->display_options['fields']['field_attendance_program_name']['id'] = 'field_attendance_program_name';
  $handler->display->display_options['fields']['field_attendance_program_name']['table'] = 'field_data_field_attendance_program_name';
  $handler->display->display_options['fields']['field_attendance_program_name']['field'] = 'field_attendance_program_name';
  $handler->display->display_options['fields']['field_attendance_program_name']['label'] = 'Class name';
  $handler->display->display_options['fields']['field_attendance_program_name']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Attendance date */
  $handler->display->display_options['fields']['field_attendance_date']['id'] = 'field_attendance_date';
  $handler->display->display_options['fields']['field_attendance_date']['table'] = 'field_data_field_attendance_date';
  $handler->display->display_options['fields']['field_attendance_date']['field'] = 'field_attendance_date';
  $handler->display->display_options['fields']['field_attendance_date']['label'] = 'Attendancy date';
  $handler->display->display_options['fields']['field_attendance_date']['settings'] = array(
    'format_type' => 'long',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Options';
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_attendance_volunteer_list_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'Volunteer name';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'attendance' => 'attendance',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_attendance_volunteer_list_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Filter by Volunteer';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Attendance date (field_attendance_date) */
  $handler->display->display_options['filters']['field_attendance_date_value']['id'] = 'field_attendance_date_value';
  $handler->display->display_options['filters']['field_attendance_date_value']['table'] = 'field_data_field_attendance_date';
  $handler->display->display_options['filters']['field_attendance_date_value']['field'] = 'field_attendance_date_value';
  $handler->display->display_options['filters']['field_attendance_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_attendance_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_attendance_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_attendance_date_value']['expose']['operator_id'] = 'field_attendance_date_value_op';
  $handler->display->display_options['filters']['field_attendance_date_value']['expose']['label'] = 'Filter by start date';
  $handler->display->display_options['filters']['field_attendance_date_value']['expose']['operator'] = 'field_attendance_date_value_op';
  $handler->display->display_options['filters']['field_attendance_date_value']['expose']['identifier'] = 'field_attendance_date_value';
  $handler->display->display_options['filters']['field_attendance_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_attendance_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_attendance_date_value']['year_range'] = '-50:+3';
  /* Filter criterion: Content: Attendance date (field_attendance_date) */
  $handler->display->display_options['filters']['field_attendance_date_value_1']['id'] = 'field_attendance_date_value_1';
  $handler->display->display_options['filters']['field_attendance_date_value_1']['table'] = 'field_data_field_attendance_date';
  $handler->display->display_options['filters']['field_attendance_date_value_1']['field'] = 'field_attendance_date_value';
  $handler->display->display_options['filters']['field_attendance_date_value_1']['operator'] = '<=';
  $handler->display->display_options['filters']['field_attendance_date_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_attendance_date_value_1']['expose']['operator_id'] = 'field_attendance_date_value_1_op';
  $handler->display->display_options['filters']['field_attendance_date_value_1']['expose']['label'] = 'Filter by end date';
  $handler->display->display_options['filters']['field_attendance_date_value_1']['expose']['operator'] = 'field_attendance_date_value_1_op';
  $handler->display->display_options['filters']['field_attendance_date_value_1']['expose']['identifier'] = 'field_attendance_date_value_1';
  $handler->display->display_options['filters']['field_attendance_date_value_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_attendance_date_value_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_attendance_date_value_1']['year_range'] = '-50:+3';
  $handler->display->display_options['path'] = 'attendance-records';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['path'] = 'attendance-records/export-xls';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Data export PDF */
  $handler = $view->new_display('views_data_export_pdf', 'Data export PDF', 'views_data_export_pdf_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_pdf';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['path'] = 'attendance-records/export-pdf';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['attendance_records_of_volunteer'] = $view;

  $view = new view();
  $view->name = 'canvassing_group';
  $view->description = '';
  $view->tag = 'REF';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Canvassing Group (REF)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Color */
  $handler->display->display_options['fields']['field_color']['id'] = 'field_color';
  $handler->display->display_options['fields']['field_color']['table'] = 'field_data_field_color';
  $handler->display->display_options['fields']['field_color']['field'] = 'field_color';
  $handler->display->display_options['fields']['field_color']['label'] = '';
  $handler->display->display_options['fields']['field_color']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_color']['click_sort_column'] = 'rgb';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'canvassing_group' => 'canvassing_group',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['separator'] = ' |';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['canvassing_group'] = $view;

  $view = new view();
  $view->name = 'canvassing_report';
  $view->description = '';
  $view->tag = 'Report';
  $view->base_table = 'node';
  $view->human_name = 'Canvassing Report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Canvassing Report';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'plain_text',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'field_program_location_target_id' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'nid_entityreference_filter' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_p_canvassing_group_target_id_entityreference_filter' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_p_canvassing_group',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'field_address_1' => 'field_address_1',
    'field_apt' => 'field_apt',
    'title_1' => 'title_1',
    'field_parent_guardian' => 'field_parent_guardian',
    'field_program_location' => 'field_program_location',
    'title' => 'title',
    'field_p_canvassing_group' => 'field_p_canvassing_group',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_address_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_apt' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_parent_guardian' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_program_location' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_p_canvassing_group' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="novo-no-data-found">No data found.</div>';
  /* Relationship: Content: Kids list (field_program_kids_list) */
  $handler->display->display_options['relationships']['field_program_kids_list_value']['id'] = 'field_program_kids_list_value';
  $handler->display->display_options['relationships']['field_program_kids_list_value']['table'] = 'field_data_field_program_kids_list';
  $handler->display->display_options['relationships']['field_program_kids_list_value']['field'] = 'field_program_kids_list_value';
  $handler->display->display_options['relationships']['field_program_kids_list_value']['label'] = 'FC kids';
  $handler->display->display_options['relationships']['field_program_kids_list_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_program_kids_list_value']['delta'] = '-1';
  /* Relationship: Kid */
  $handler->display->display_options['relationships']['field_p_kid_name_target_id']['id'] = 'field_p_kid_name_target_id';
  $handler->display->display_options['relationships']['field_p_kid_name_target_id']['table'] = 'field_data_field_p_kid_name';
  $handler->display->display_options['relationships']['field_p_kid_name_target_id']['field'] = 'field_p_kid_name_target_id';
  $handler->display->display_options['relationships']['field_p_kid_name_target_id']['relationship'] = 'field_program_kids_list_value';
  $handler->display->display_options['relationships']['field_p_kid_name_target_id']['ui_name'] = 'Kid';
  $handler->display->display_options['relationships']['field_p_kid_name_target_id']['label'] = 'Kid';
  $handler->display->display_options['relationships']['field_p_kid_name_target_id']['required'] = TRUE;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_address_1']['id'] = 'field_address_1';
  $handler->display->display_options['fields']['field_address_1']['table'] = 'field_data_field_address_1';
  $handler->display->display_options['fields']['field_address_1']['field'] = 'field_address_1';
  $handler->display->display_options['fields']['field_address_1']['relationship'] = 'field_p_kid_name_target_id';
  $handler->display->display_options['fields']['field_address_1']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_address_1']['settings'] = array(
    'trim_length' => '50',
  );
  /* Field: Content: Address Apartment number */
  $handler->display->display_options['fields']['field_apt']['id'] = 'field_apt';
  $handler->display->display_options['fields']['field_apt']['table'] = 'field_data_field_apt';
  $handler->display->display_options['fields']['field_apt']['field'] = 'field_apt';
  $handler->display->display_options['fields']['field_apt']['relationship'] = 'field_p_kid_name_target_id';
  $handler->display->display_options['fields']['field_apt']['label'] = 'Apt #';
  $handler->display->display_options['fields']['field_apt']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_apt']['settings'] = array(
    'trim_length' => '50',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_p_kid_name_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Children name';
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Parent / Guardian List */
  $handler->display->display_options['fields']['field_parent_guardian']['id'] = 'field_parent_guardian';
  $handler->display->display_options['fields']['field_parent_guardian']['table'] = 'field_data_field_parent_guardian';
  $handler->display->display_options['fields']['field_parent_guardian']['field'] = 'field_parent_guardian';
  $handler->display->display_options['fields']['field_parent_guardian']['relationship'] = 'field_p_kid_name_target_id';
  $handler->display->display_options['fields']['field_parent_guardian']['label'] = 'Parent / Guardian';
  $handler->display->display_options['fields']['field_parent_guardian']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_parent_guardian']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_parent_guardian']['delta_offset'] = '0';
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_program_location']['id'] = 'field_program_location';
  $handler->display->display_options['fields']['field_program_location']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['fields']['field_program_location']['field'] = 'field_program_location';
  $handler->display->display_options['fields']['field_program_location']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Program name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field collection item: Canvassing Group */
  $handler->display->display_options['fields']['field_p_canvassing_group']['id'] = 'field_p_canvassing_group';
  $handler->display->display_options['fields']['field_p_canvassing_group']['table'] = 'field_data_field_p_canvassing_group';
  $handler->display->display_options['fields']['field_p_canvassing_group']['field'] = 'field_p_canvassing_group';
  $handler->display->display_options['fields']['field_p_canvassing_group']['relationship'] = 'field_program_kids_list_value';
  $handler->display->display_options['fields']['field_p_canvassing_group']['label'] = '';
  $handler->display->display_options['fields']['field_p_canvassing_group']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_p_canvassing_group']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_p_canvassing_group']['empty'] = 'No group';
  $handler->display->display_options['fields']['field_p_canvassing_group']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_p_canvassing_group']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_p_canvassing_group']['settings'] = array(
    'view_mode' => 'default',
    'links' => 0,
    'use_content_language' => 0,
  );
  /* Field: Draggableviews: Field collection item */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['relationship'] = 'field_program_kids_list_value';
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 1;
  /* Sort criterion: Field collection item: Canvassing Group (field_p_canvassing_group) */
  $handler->display->display_options['sorts']['field_p_canvassing_group_target_id']['id'] = 'field_p_canvassing_group_target_id';
  $handler->display->display_options['sorts']['field_p_canvassing_group_target_id']['table'] = 'field_data_field_p_canvassing_group';
  $handler->display->display_options['sorts']['field_p_canvassing_group_target_id']['field'] = 'field_p_canvassing_group_target_id';
  $handler->display->display_options['sorts']['field_p_canvassing_group_target_id']['relationship'] = 'field_program_kids_list_value';
  $handler->display->display_options['sorts']['field_p_canvassing_group_target_id']['order'] = 'DESC';
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_program_kids_list_value';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'canvassing_report:page';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_arguments'] = 'none';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_arguments_ignore_empty'] = 0;
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program' => 'program',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: School year (field_program_year) */
  $handler->display->display_options['filters']['field_program_year_year']['id'] = 'field_program_year_year';
  $handler->display->display_options['filters']['field_program_year_year']['table'] = 'field_data_field_program_year';
  $handler->display->display_options['filters']['field_program_year_year']['field'] = 'field_program_year_year';
  $handler->display->display_options['filters']['field_program_year_year']['group'] = 1;
  $handler->display->display_options['filters']['field_program_year_year']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_year_year']['expose']['operator_id'] = 'field_program_year_year_op';
  $handler->display->display_options['filters']['field_program_year_year']['expose']['label'] = 'Filter by School year';
  $handler->display->display_options['filters']['field_program_year_year']['expose']['operator'] = 'field_program_year_year_op';
  $handler->display->display_options['filters']['field_program_year_year']['expose']['identifier'] = 'field_program_year_year';
  $handler->display->display_options['filters']['field_program_year_year']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_program_year_year']['expose']['remember_roles'] = array(
    2 => 0,
    5 => '5',
    3 => '3',
    1 => 0,
    6 => 0,
  );
  /* Filter criterion: Content: Location (field_program_location) (reference filter) */
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['id'] = 'field_program_location_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['field'] = 'field_program_location_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['operator_id'] = 'field_program_location_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['label'] = 'Filter by Location';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['operator'] = 'field_program_location_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['identifier'] = 'field_program_location_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => 0,
    5 => '5',
    3 => '3',
    1 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['hide_empty_filter'] = FALSE;
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['reference_display'] = 'program_locations_list:entityreference_1';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['reference_arguments'] = '[field_program_year_year]';
  /* Filter criterion: Content: Nid (reference filter) */
  $handler->display->display_options['filters']['nid_entityreference_filter']['id'] = 'nid_entityreference_filter';
  $handler->display->display_options['filters']['nid_entityreference_filter']['table'] = 'node';
  $handler->display->display_options['filters']['nid_entityreference_filter']['field'] = 'nid_entityreference_filter';
  $handler->display->display_options['filters']['nid_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['nid_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid_entityreference_filter']['expose']['operator_id'] = 'nid_entityreference_filter_op';
  $handler->display->display_options['filters']['nid_entityreference_filter']['expose']['label'] = 'Filter by Program';
  $handler->display->display_options['filters']['nid_entityreference_filter']['expose']['operator'] = 'nid_entityreference_filter_op';
  $handler->display->display_options['filters']['nid_entityreference_filter']['expose']['identifier'] = 'nid_entityreference_filter';
  $handler->display->display_options['filters']['nid_entityreference_filter']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['nid_entityreference_filter']['expose']['remember_roles'] = array(
    2 => 0,
    5 => '5',
    3 => '3',
    1 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['nid_entityreference_filter']['expose']['hide_empty_filter'] = FALSE;
  $handler->display->display_options['filters']['nid_entityreference_filter']['reference_display'] = 'canvassing_report_filter_program:entityreference_1';
  $handler->display->display_options['filters']['nid_entityreference_filter']['reference_arguments'] = '[field_program_year_year]/[field_program_location_target_id]';
  /* Filter criterion: Field collection item: Canvassing Group (field_p_canvassing_group) (reference filter) */
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['id'] = 'field_p_canvassing_group_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['table'] = 'field_data_field_p_canvassing_group';
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['field'] = 'field_p_canvassing_group_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['relationship'] = 'field_program_kids_list_value';
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['expose']['operator_id'] = 'field_p_canvassing_group_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['expose']['label'] = 'Filter by Group';
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['expose']['operator'] = 'field_p_canvassing_group_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['expose']['identifier'] = 'field_p_canvassing_group_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => 0,
    5 => '5',
    3 => '3',
    1 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['reference_display'] = 'canvassing_group:entityreference_1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'canvassing-report';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_p_canvassing_group',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_address_1']['id'] = 'field_address_1';
  $handler->display->display_options['fields']['field_address_1']['table'] = 'field_data_field_address_1';
  $handler->display->display_options['fields']['field_address_1']['field'] = 'field_address_1';
  $handler->display->display_options['fields']['field_address_1']['relationship'] = 'field_p_kid_name_target_id';
  $handler->display->display_options['fields']['field_address_1']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_address_1']['settings'] = array(
    'trim_length' => '50',
  );
  /* Field: Content: Address Apartment number */
  $handler->display->display_options['fields']['field_apt']['id'] = 'field_apt';
  $handler->display->display_options['fields']['field_apt']['table'] = 'field_data_field_apt';
  $handler->display->display_options['fields']['field_apt']['field'] = 'field_apt';
  $handler->display->display_options['fields']['field_apt']['relationship'] = 'field_p_kid_name_target_id';
  $handler->display->display_options['fields']['field_apt']['label'] = 'Apt #';
  $handler->display->display_options['fields']['field_apt']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_apt']['settings'] = array(
    'trim_length' => '50',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_p_kid_name_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Children name';
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Parent / Guardian List */
  $handler->display->display_options['fields']['field_parent_guardian']['id'] = 'field_parent_guardian';
  $handler->display->display_options['fields']['field_parent_guardian']['table'] = 'field_data_field_parent_guardian';
  $handler->display->display_options['fields']['field_parent_guardian']['field'] = 'field_parent_guardian';
  $handler->display->display_options['fields']['field_parent_guardian']['relationship'] = 'field_p_kid_name_target_id';
  $handler->display->display_options['fields']['field_parent_guardian']['label'] = 'Parent / Guardian';
  $handler->display->display_options['fields']['field_parent_guardian']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_parent_guardian']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_parent_guardian']['delta_offset'] = '0';
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_program_location']['id'] = 'field_program_location';
  $handler->display->display_options['fields']['field_program_location']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['fields']['field_program_location']['field'] = 'field_program_location';
  $handler->display->display_options['fields']['field_program_location']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Program name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field collection item: Canvassing Group */
  $handler->display->display_options['fields']['field_p_canvassing_group']['id'] = 'field_p_canvassing_group';
  $handler->display->display_options['fields']['field_p_canvassing_group']['table'] = 'field_data_field_p_canvassing_group';
  $handler->display->display_options['fields']['field_p_canvassing_group']['field'] = 'field_p_canvassing_group';
  $handler->display->display_options['fields']['field_p_canvassing_group']['relationship'] = 'field_program_kids_list_value';
  $handler->display->display_options['fields']['field_p_canvassing_group']['label'] = '';
  $handler->display->display_options['fields']['field_p_canvassing_group']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_p_canvassing_group']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_p_canvassing_group']['empty'] = 'No group';
  $handler->display->display_options['fields']['field_p_canvassing_group']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_p_canvassing_group']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_p_canvassing_group']['settings'] = array(
    'view_mode' => 'default',
    'links' => 0,
    'use_content_language' => 0,
  );
  /* Field: Draggableviews: Field collection item */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['relationship'] = 'field_program_kids_list_value';
  $handler->display->display_options['fields']['draggableviews']['exclude'] = TRUE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 1;
  $handler->display->display_options['path'] = 'canvassing-report/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['segment_size'] = '100';

  /* Display: Data export PDF */
  $handler = $view->new_display('views_data_export_pdf', 'Data export PDF', 'views_data_export_pdf_2');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_pdf';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_p_canvassing_group',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_address_1']['id'] = 'field_address_1';
  $handler->display->display_options['fields']['field_address_1']['table'] = 'field_data_field_address_1';
  $handler->display->display_options['fields']['field_address_1']['field'] = 'field_address_1';
  $handler->display->display_options['fields']['field_address_1']['relationship'] = 'field_p_kid_name_target_id';
  $handler->display->display_options['fields']['field_address_1']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_address_1']['settings'] = array(
    'trim_length' => '50',
  );
  /* Field: Content: Address Apartment number */
  $handler->display->display_options['fields']['field_apt']['id'] = 'field_apt';
  $handler->display->display_options['fields']['field_apt']['table'] = 'field_data_field_apt';
  $handler->display->display_options['fields']['field_apt']['field'] = 'field_apt';
  $handler->display->display_options['fields']['field_apt']['relationship'] = 'field_p_kid_name_target_id';
  $handler->display->display_options['fields']['field_apt']['label'] = 'Apt #';
  $handler->display->display_options['fields']['field_apt']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_apt']['settings'] = array(
    'trim_length' => '50',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_p_kid_name_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Children name';
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Parent / Guardian List */
  $handler->display->display_options['fields']['field_parent_guardian']['id'] = 'field_parent_guardian';
  $handler->display->display_options['fields']['field_parent_guardian']['table'] = 'field_data_field_parent_guardian';
  $handler->display->display_options['fields']['field_parent_guardian']['field'] = 'field_parent_guardian';
  $handler->display->display_options['fields']['field_parent_guardian']['relationship'] = 'field_p_kid_name_target_id';
  $handler->display->display_options['fields']['field_parent_guardian']['label'] = 'Parent / Guardian';
  $handler->display->display_options['fields']['field_parent_guardian']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_parent_guardian']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_parent_guardian']['delta_offset'] = '0';
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_program_location']['id'] = 'field_program_location';
  $handler->display->display_options['fields']['field_program_location']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['fields']['field_program_location']['field'] = 'field_program_location';
  $handler->display->display_options['fields']['field_program_location']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Program name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field collection item: Canvassing Group */
  $handler->display->display_options['fields']['field_p_canvassing_group']['id'] = 'field_p_canvassing_group';
  $handler->display->display_options['fields']['field_p_canvassing_group']['table'] = 'field_data_field_p_canvassing_group';
  $handler->display->display_options['fields']['field_p_canvassing_group']['field'] = 'field_p_canvassing_group';
  $handler->display->display_options['fields']['field_p_canvassing_group']['relationship'] = 'field_program_kids_list_value';
  $handler->display->display_options['fields']['field_p_canvassing_group']['label'] = '';
  $handler->display->display_options['fields']['field_p_canvassing_group']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_p_canvassing_group']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_p_canvassing_group']['empty'] = 'No group';
  $handler->display->display_options['fields']['field_p_canvassing_group']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_p_canvassing_group']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_p_canvassing_group']['settings'] = array(
    'view_mode' => 'default',
    'links' => 0,
    'use_content_language' => 0,
  );
  /* Field: Draggableviews: Field collection item */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['relationship'] = 'field_program_kids_list_value';
  $handler->display->display_options['fields']['draggableviews']['exclude'] = TRUE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 1;
  $handler->display->display_options['path'] = 'canvassing-report/export-pdf';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['canvassing_report'] = $view;

  $view = new view();
  $view->name = 'canvassing_report_filter_program';
  $view->description = '';
  $view->tag = 'REF';
  $view->base_table = 'node';
  $view->human_name = 'Canvassing report filter program';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Contextual filter: Content: School year (field_program_year) */
  $handler->display->display_options['arguments']['field_program_year_year']['id'] = 'field_program_year_year';
  $handler->display->display_options['arguments']['field_program_year_year']['table'] = 'field_data_field_program_year';
  $handler->display->display_options['arguments']['field_program_year_year']['field'] = 'field_program_year_year';
  $handler->display->display_options['arguments']['field_program_year_year']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_program_year_year']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_program_year_year']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_program_year_year']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Location (field_program_location) */
  $handler->display->display_options['arguments']['field_program_location_target_id']['id'] = 'field_program_location_target_id';
  $handler->display->display_options['arguments']['field_program_location_target_id']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['arguments']['field_program_location_target_id']['field'] = 'field_program_location_target_id';
  $handler->display->display_options['arguments']['field_program_location_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_program_location_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_program_location_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_program_location_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program' => 'program',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['canvassing_report_filter_program'] = $view;

  $view = new view();
  $view->name = 'children_active_report';
  $view->description = '';
  $view->tag = 'Report';
  $view->base_table = 'node';
  $view->human_name = 'Children Active Report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Children Active Report';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'plain_text',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_dob' => 'field_dob',
    'field_gender' => 'field_gender',
    'field_address_1' => 'field_address_1',
    'field_address_2' => 'field_address_2',
    'field_apt' => 'field_apt',
    'field_city' => 'field_city',
    'field_state' => 'field_state',
    'field_zip' => 'field_zip',
    'field_ethnicity' => 'field_ethnicity',
    'field_school' => 'field_school',
    'field_teacher' => 'field_teacher',
    'field_health_concerns' => 'field_health_concerns',
    'field_parent_guardian' => 'field_parent_guardian',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dob' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_gender' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_address_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_address_2' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_apt' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_city' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_zip' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ethnicity' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_school' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_teacher' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_health_concerns' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_parent_guardian' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="novo-no-data-found">No data found.</div>';
  /* Relationship: In Attendance */
  $handler->display->display_options['relationships']['reverse_field_attendance_kids_list_node']['id'] = 'reverse_field_attendance_kids_list_node';
  $handler->display->display_options['relationships']['reverse_field_attendance_kids_list_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_attendance_kids_list_node']['field'] = 'reverse_field_attendance_kids_list_node';
  $handler->display->display_options['relationships']['reverse_field_attendance_kids_list_node']['ui_name'] = 'In Attendance';
  $handler->display->display_options['relationships']['reverse_field_attendance_kids_list_node']['label'] = 'In Attendance';
  $handler->display->display_options['relationships']['reverse_field_attendance_kids_list_node']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_attendance_program_name_target_id']['id'] = 'field_attendance_program_name_target_id';
  $handler->display->display_options['relationships']['field_attendance_program_name_target_id']['table'] = 'field_data_field_attendance_program_name';
  $handler->display->display_options['relationships']['field_attendance_program_name_target_id']['field'] = 'field_attendance_program_name_target_id';
  $handler->display->display_options['relationships']['field_attendance_program_name_target_id']['relationship'] = 'reverse_field_attendance_kids_list_node';
  $handler->display->display_options['relationships']['field_attendance_program_name_target_id']['label'] = 'Programm';
  $handler->display->display_options['relationships']['field_attendance_program_name_target_id']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Full name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Date of Birth */
  $handler->display->display_options['fields']['field_dob']['id'] = 'field_dob';
  $handler->display->display_options['fields']['field_dob']['table'] = 'field_data_field_dob';
  $handler->display->display_options['fields']['field_dob']['field'] = 'field_dob';
  $handler->display->display_options['fields']['field_dob']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Gender */
  $handler->display->display_options['fields']['field_gender']['id'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['table'] = 'field_data_field_gender';
  $handler->display->display_options['fields']['field_gender']['field'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_address_1']['id'] = 'field_address_1';
  $handler->display->display_options['fields']['field_address_1']['table'] = 'field_data_field_address_1';
  $handler->display->display_options['fields']['field_address_1']['field'] = 'field_address_1';
  $handler->display->display_options['fields']['field_address_1']['label'] = 'Address 1';
  /* Field: Content: Address 2 */
  $handler->display->display_options['fields']['field_address_2']['id'] = 'field_address_2';
  $handler->display->display_options['fields']['field_address_2']['table'] = 'field_data_field_address_2';
  $handler->display->display_options['fields']['field_address_2']['field'] = 'field_address_2';
  /* Field: Content: Address Apartment number */
  $handler->display->display_options['fields']['field_apt']['id'] = 'field_apt';
  $handler->display->display_options['fields']['field_apt']['table'] = 'field_data_field_apt';
  $handler->display->display_options['fields']['field_apt']['field'] = 'field_apt';
  $handler->display->display_options['fields']['field_apt']['label'] = 'Apt#';
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  /* Field: Content: State */
  $handler->display->display_options['fields']['field_state']['id'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['table'] = 'field_data_field_state';
  $handler->display->display_options['fields']['field_state']['field'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Zip */
  $handler->display->display_options['fields']['field_zip']['id'] = 'field_zip';
  $handler->display->display_options['fields']['field_zip']['table'] = 'field_data_field_zip';
  $handler->display->display_options['fields']['field_zip']['field'] = 'field_zip';
  $handler->display->display_options['fields']['field_zip']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Ethnicity */
  $handler->display->display_options['fields']['field_ethnicity']['id'] = 'field_ethnicity';
  $handler->display->display_options['fields']['field_ethnicity']['table'] = 'field_data_field_ethnicity';
  $handler->display->display_options['fields']['field_ethnicity']['field'] = 'field_ethnicity';
  $handler->display->display_options['fields']['field_ethnicity']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: School name */
  $handler->display->display_options['fields']['field_school']['id'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['table'] = 'field_data_field_school';
  $handler->display->display_options['fields']['field_school']['field'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Teacher name */
  $handler->display->display_options['fields']['field_teacher']['id'] = 'field_teacher';
  $handler->display->display_options['fields']['field_teacher']['table'] = 'field_data_field_teacher';
  $handler->display->display_options['fields']['field_teacher']['field'] = 'field_teacher';
  /* Field: Content: Health Concerns */
  $handler->display->display_options['fields']['field_health_concerns']['id'] = 'field_health_concerns';
  $handler->display->display_options['fields']['field_health_concerns']['table'] = 'field_data_field_health_concerns';
  $handler->display->display_options['fields']['field_health_concerns']['field'] = 'field_health_concerns';
  /* Field: Content: Parent / Guardian List */
  $handler->display->display_options['fields']['field_parent_guardian']['id'] = 'field_parent_guardian';
  $handler->display->display_options['fields']['field_parent_guardian']['table'] = 'field_data_field_parent_guardian';
  $handler->display->display_options['fields']['field_parent_guardian']['field'] = 'field_parent_guardian';
  $handler->display->display_options['fields']['field_parent_guardian']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_parent_guardian']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_parent_guardian']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_parent_guardian']['separator'] = '<br>';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'kids' => 'kids',
  );
  /* Filter criterion: Content: Moved (field_moved) */
  $handler->display->display_options['filters']['field_moved_value']['id'] = 'field_moved_value';
  $handler->display->display_options['filters']['field_moved_value']['table'] = 'field_data_field_moved';
  $handler->display->display_options['filters']['field_moved_value']['field'] = 'field_moved_value';
  $handler->display->display_options['filters']['field_moved_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_moved_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search by full name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => 0,
    5 => '5',
    3 => '3',
    1 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: School year (field_program_year) */
  $handler->display->display_options['filters']['field_program_year_year']['id'] = 'field_program_year_year';
  $handler->display->display_options['filters']['field_program_year_year']['table'] = 'field_data_field_program_year';
  $handler->display->display_options['filters']['field_program_year_year']['field'] = 'field_program_year_year';
  $handler->display->display_options['filters']['field_program_year_year']['relationship'] = 'field_attendance_program_name_target_id';
  $handler->display->display_options['filters']['field_program_year_year']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_year_year']['expose']['operator_id'] = 'field_program_year_year_op';
  $handler->display->display_options['filters']['field_program_year_year']['expose']['label'] = 'Filter by School year';
  $handler->display->display_options['filters']['field_program_year_year']['expose']['operator'] = 'field_program_year_year_op';
  $handler->display->display_options['filters']['field_program_year_year']['expose']['identifier'] = 'field_program_year_year';
  $handler->display->display_options['filters']['field_program_year_year']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_program_year_year']['expose']['remember_roles'] = array(
    2 => 0,
    5 => '5',
    3 => '3',
    1 => 0,
    6 => 0,
  );
  /* Filter criterion: Content: Location (field_program_location) (reference filter) */
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['id'] = 'field_program_location_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['field'] = 'field_program_location_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['relationship'] = 'field_attendance_program_name_target_id';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['operator_id'] = 'field_program_location_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['label'] = 'Filter by Location';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['operator'] = 'field_program_location_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['identifier'] = 'field_program_location_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => 0,
    5 => '5',
    3 => '3',
    1 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['hide_empty_filter'] = FALSE;
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['reference_display'] = 'attendance_filter_locations:entityreference_1';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['reference_arguments'] = '[field_program_year_year]';
  /* Filter criterion: Content: Program name (field_attendance_program_name) (reference filter) */
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['id'] = 'field_attendance_program_name_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['table'] = 'field_data_field_attendance_program_name';
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['field'] = 'field_attendance_program_name_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['relationship'] = 'reverse_field_attendance_kids_list_node';
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['expose']['operator_id'] = 'field_attendance_program_name_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['expose']['label'] = 'Filter by Class name';
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['expose']['operator'] = 'field_attendance_program_name_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['expose']['identifier'] = 'field_attendance_program_name_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => 0,
    5 => '5',
    3 => '3',
    1 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['expose']['hide_empty_filter'] = FALSE;
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['reference_display'] = 'attendance_filter_programs:entityreference_1';
  $handler->display->display_options['filters']['field_attendance_program_name_target_id_entityreference_filter']['reference_arguments'] = '[field_program_year_year]/[field_program_location_target_id_entityreference_filter]';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'children-active-report';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['path'] = 'children-active-report/export-xls';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Data export PDF */
  $handler = $view->new_display('views_data_export_pdf', 'Data export PDF', 'views_data_export_pdf_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_pdf';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['landscape'] = 1;
  $handler->display->display_options['style_options']['user_style_sheet'] = 'sites/all/modules/custom/novo_reports/css/novo_reports_children_active_report_pdf.css';
  $handler->display->display_options['path'] = 'children-active-report/export-pdf';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['children_active_report'] = $view;

  $view = new view();
  $view->name = 'class';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Class';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Class';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'plain_text',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'field_class_year_year' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_class_location',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'status' => 'status',
    'nid' => 'nid',
    'field_class_school_year' => 'field_class_school_year',
    'field_program_day' => 'field_program_day',
    'field_class_location' => 'field_class_location',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_class_school_year' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_program_day' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_class_location' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="novo-no-data-found">No data found.</div>';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Class name';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: School year */
  $handler->display->display_options['fields']['field_class_year']['id'] = 'field_class_year';
  $handler->display->display_options['fields']['field_class_year']['table'] = 'field_data_field_class_year';
  $handler->display->display_options['fields']['field_class_year']['field'] = 'field_class_year';
  $handler->display->display_options['fields']['field_class_year']['type'] = 'year_academic';
  /* Field: Content: Program day */
  $handler->display->display_options['fields']['field_program_day']['id'] = 'field_program_day';
  $handler->display->display_options['fields']['field_program_day']['table'] = 'field_data_field_program_day';
  $handler->display->display_options['fields']['field_program_day']['field'] = 'field_program_day';
  $handler->display->display_options['fields']['field_program_day']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_program_day']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_program_day']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_program_day']['multi_type'] = 'ul';
  $handler->display->display_options['fields']['field_program_day']['separator'] = '';
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_class_location']['id'] = 'field_class_location';
  $handler->display->display_options['fields']['field_class_location']['table'] = 'field_data_field_class_location';
  $handler->display->display_options['fields']['field_class_location']['field'] = 'field_class_location';
  $handler->display->display_options['fields']['field_class_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_class_location']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Options';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'class' => 'class',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: School year (field_class_year) */
  $handler->display->display_options['filters']['field_class_year_year']['id'] = 'field_class_year_year';
  $handler->display->display_options['filters']['field_class_year_year']['table'] = 'field_data_field_class_year';
  $handler->display->display_options['filters']['field_class_year_year']['field'] = 'field_class_year_year';
  $handler->display->display_options['filters']['field_class_year_year']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_class_year_year']['expose']['operator_id'] = 'field_class_year_year_op';
  $handler->display->display_options['filters']['field_class_year_year']['expose']['label'] = 'Filter by School year';
  $handler->display->display_options['filters']['field_class_year_year']['expose']['operator'] = 'field_class_year_year_op';
  $handler->display->display_options['filters']['field_class_year_year']['expose']['identifier'] = 'field_class_year_year';
  $handler->display->display_options['filters']['field_class_year_year']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Location (field_class_location) (reference filter) */
  $handler->display->display_options['filters']['field_class_location_target_id_entityreference_filter']['id'] = 'field_class_location_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_class_location_target_id_entityreference_filter']['table'] = 'field_data_field_class_location';
  $handler->display->display_options['filters']['field_class_location_target_id_entityreference_filter']['field'] = 'field_class_location_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_class_location_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_class_location_target_id_entityreference_filter']['expose']['operator_id'] = 'field_class_location_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_class_location_target_id_entityreference_filter']['expose']['label'] = 'Filter by Location';
  $handler->display->display_options['filters']['field_class_location_target_id_entityreference_filter']['expose']['operator'] = 'field_class_location_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_class_location_target_id_entityreference_filter']['expose']['identifier'] = 'field_class_location_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_class_location_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_class_location_target_id_entityreference_filter']['expose']['hide_empty_filter'] = FALSE;
  $handler->display->display_options['filters']['field_class_location_target_id_entityreference_filter']['reference_display'] = 'class_filter_locations:entityreference_1';
  $handler->display->display_options['filters']['field_class_location_target_id_entityreference_filter']['reference_arguments'] = '[field_class_year_year]';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'class';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Class';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-program-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['class'] = $view;

  $view = new view();
  $view->name = 'class_filter_locations';
  $view->description = '';
  $view->tag = 'REF';
  $view->base_table = 'node';
  $view->human_name = 'Class Filter Locations (REF)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: In Class */
  $handler->display->display_options['relationships']['reverse_field_class_location_node']['id'] = 'reverse_field_class_location_node';
  $handler->display->display_options['relationships']['reverse_field_class_location_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_class_location_node']['field'] = 'reverse_field_class_location_node';
  $handler->display->display_options['relationships']['reverse_field_class_location_node']['ui_name'] = 'In Class';
  $handler->display->display_options['relationships']['reverse_field_class_location_node']['label'] = 'In Class';
  $handler->display->display_options['relationships']['reverse_field_class_location_node']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: School year (field_class_year) */
  $handler->display->display_options['arguments']['field_class_year_year']['id'] = 'field_class_year_year';
  $handler->display->display_options['arguments']['field_class_year_year']['table'] = 'field_data_field_class_year';
  $handler->display->display_options['arguments']['field_class_year_year']['field'] = 'field_class_year_year';
  $handler->display->display_options['arguments']['field_class_year_year']['relationship'] = 'reverse_field_class_location_node';
  $handler->display->display_options['arguments']['field_class_year_year']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_class_year_year']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_class_year_year']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_class_year_year']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'locations' => 'locations',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'reverse_field_class_location_node';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'class' => 'class',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['class_filter_locations'] = $view;

  $view = new view();
  $view->name = 'kids';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Kids';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Kids';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'plain_text',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'title' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_moved' => 'field_moved',
    'title' => 'title',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_moved' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="novo-no-data-found">No data found.</div>';
  /* Field: Content: Moved */
  $handler->display->display_options['fields']['field_moved']['id'] = 'field_moved';
  $handler->display->display_options['fields']['field_moved']['table'] = 'field_data_field_moved';
  $handler->display->display_options['fields']['field_moved']['field'] = 'field_moved';
  $handler->display->display_options['fields']['field_moved']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_moved']['type'] = 'list_key';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span class="novo-title-moved-[field_moved]">[title]</span>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Options';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'kids' => 'kids',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'kids';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Kids';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $export['kids'] = $view;

  $view = new view();
  $view->name = 'kids_list';
  $view->description = '';
  $view->tag = 'REF';
  $view->base_table = 'node';
  $view->human_name = 'Kids list (REF)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'kids' => 'kids',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'field_dob' => 0,
    'field_grade' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['separator'] = '';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['kids_list'] = $view;

  $view = new view();
  $view->name = 'list_kids_mentored';
  $view->description = '';
  $view->tag = 'DYN';
  $view->base_table = 'node';
  $view->human_name = 'List Kids mentored';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'List Kids mentored';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'plain_text',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'title' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_mentoring_date_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 1,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
        'datepicker_options' => '',
      ),
    ),
    'field_mentoring_date_value_1' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 1,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
        'datepicker_options' => '',
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_mentoring_date' => 'field_mentoring_date',
    'field_mentoring' => 'field_mentoring',
    'edit_node' => 'edit_node',
    'title_1' => 'title_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mentoring_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mentoring' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['empty'] = TRUE;
  $handler->display->display_options['footer']['result']['content'] = 'Total @total mentorings';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="novo-no-data-found">No data found.</div>';
  /* Relationship: In Mentors */
  $handler->display->display_options['relationships']['reverse_field_mentor_kid_name_node']['id'] = 'reverse_field_mentor_kid_name_node';
  $handler->display->display_options['relationships']['reverse_field_mentor_kid_name_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_mentor_kid_name_node']['field'] = 'reverse_field_mentor_kid_name_node';
  $handler->display->display_options['relationships']['reverse_field_mentor_kid_name_node']['ui_name'] = 'In Mentors';
  $handler->display->display_options['relationships']['reverse_field_mentor_kid_name_node']['label'] = 'In Mentors';
  $handler->display->display_options['relationships']['reverse_field_mentor_kid_name_node']['required'] = TRUE;
  /* Relationship: Volunteer */
  $handler->display->display_options['relationships']['field_volunteer_mentor_name_target_id']['id'] = 'field_volunteer_mentor_name_target_id';
  $handler->display->display_options['relationships']['field_volunteer_mentor_name_target_id']['table'] = 'field_data_field_volunteer_mentor_name';
  $handler->display->display_options['relationships']['field_volunteer_mentor_name_target_id']['field'] = 'field_volunteer_mentor_name_target_id';
  $handler->display->display_options['relationships']['field_volunteer_mentor_name_target_id']['relationship'] = 'reverse_field_mentor_kid_name_node';
  $handler->display->display_options['relationships']['field_volunteer_mentor_name_target_id']['ui_name'] = 'Volunteer';
  $handler->display->display_options['relationships']['field_volunteer_mentor_name_target_id']['label'] = 'Volunteer';
  $handler->display->display_options['relationships']['field_volunteer_mentor_name_target_id']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Kid name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Mentoring Date */
  $handler->display->display_options['fields']['field_mentoring_date']['id'] = 'field_mentoring_date';
  $handler->display->display_options['fields']['field_mentoring_date']['table'] = 'field_data_field_mentoring_date';
  $handler->display->display_options['fields']['field_mentoring_date']['field'] = 'field_mentoring_date';
  $handler->display->display_options['fields']['field_mentoring_date']['relationship'] = 'reverse_field_mentor_kid_name_node';
  $handler->display->display_options['fields']['field_mentoring_date']['label'] = 'Date';
  $handler->display->display_options['fields']['field_mentoring_date']['settings'] = array(
    'format_type' => 'long',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Mentoring */
  $handler->display->display_options['fields']['field_mentoring']['id'] = 'field_mentoring';
  $handler->display->display_options['fields']['field_mentoring']['table'] = 'field_data_field_mentoring';
  $handler->display->display_options['fields']['field_mentoring']['field'] = 'field_mentoring';
  $handler->display->display_options['fields']['field_mentoring']['relationship'] = 'reverse_field_mentor_kid_name_node';
  $handler->display->display_options['fields']['field_mentoring']['label'] = 'Status';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_volunteer_mentor_name_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Volunteer Mentor Name';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'kids' => 'kids',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Mentor Type (field_mentor_type) */
  $handler->display->display_options['filters']['field_mentor_type_value']['id'] = 'field_mentor_type_value';
  $handler->display->display_options['filters']['field_mentor_type_value']['table'] = 'field_data_field_mentor_type';
  $handler->display->display_options['filters']['field_mentor_type_value']['field'] = 'field_mentor_type_value';
  $handler->display->display_options['filters']['field_mentor_type_value']['relationship'] = 'reverse_field_mentor_kid_name_node';
  $handler->display->display_options['filters']['field_mentor_type_value']['value'] = array(
    'Volunteer' => 'Volunteer',
  );
  $handler->display->display_options['filters']['field_mentor_type_value']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_volunteer_mentor_name_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Filter by Volunteer (as Mentor)';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title_1';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Mentoring Date (field_mentoring_date) */
  $handler->display->display_options['filters']['field_mentoring_date_value']['id'] = 'field_mentoring_date_value';
  $handler->display->display_options['filters']['field_mentoring_date_value']['table'] = 'field_data_field_mentoring_date';
  $handler->display->display_options['filters']['field_mentoring_date_value']['field'] = 'field_mentoring_date_value';
  $handler->display->display_options['filters']['field_mentoring_date_value']['relationship'] = 'reverse_field_mentor_kid_name_node';
  $handler->display->display_options['filters']['field_mentoring_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_mentoring_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_mentoring_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_mentoring_date_value']['expose']['operator_id'] = 'field_mentoring_date_value_op';
  $handler->display->display_options['filters']['field_mentoring_date_value']['expose']['label'] = 'Filter by start date';
  $handler->display->display_options['filters']['field_mentoring_date_value']['expose']['operator'] = 'field_mentoring_date_value_op';
  $handler->display->display_options['filters']['field_mentoring_date_value']['expose']['identifier'] = 'field_mentoring_date_value';
  $handler->display->display_options['filters']['field_mentoring_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_mentoring_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_mentoring_date_value']['year_range'] = '-50:+3';
  /* Filter criterion: Content: Mentoring Date (field_mentoring_date) */
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['id'] = 'field_mentoring_date_value_1';
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['table'] = 'field_data_field_mentoring_date';
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['field'] = 'field_mentoring_date_value';
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['relationship'] = 'reverse_field_mentor_kid_name_node';
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['operator'] = '<=';
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['expose']['operator_id'] = 'field_mentoring_date_value_1_op';
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['expose']['label'] = 'Filter by end date';
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['expose']['operator'] = 'field_mentoring_date_value_1_op';
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['expose']['identifier'] = 'field_mentoring_date_value_1';
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['year_range'] = '-50:+3';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Kid name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Mentoring Date */
  $handler->display->display_options['fields']['field_mentoring_date']['id'] = 'field_mentoring_date';
  $handler->display->display_options['fields']['field_mentoring_date']['table'] = 'field_data_field_mentoring_date';
  $handler->display->display_options['fields']['field_mentoring_date']['field'] = 'field_mentoring_date';
  $handler->display->display_options['fields']['field_mentoring_date']['relationship'] = 'reverse_field_mentor_kid_name_node';
  $handler->display->display_options['fields']['field_mentoring_date']['label'] = 'Date';
  $handler->display->display_options['fields']['field_mentoring_date']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Mentoring */
  $handler->display->display_options['fields']['field_mentoring']['id'] = 'field_mentoring';
  $handler->display->display_options['fields']['field_mentoring']['table'] = 'field_data_field_mentoring';
  $handler->display->display_options['fields']['field_mentoring']['field'] = 'field_mentoring';
  $handler->display->display_options['fields']['field_mentoring']['relationship'] = 'reverse_field_mentor_kid_name_node';
  $handler->display->display_options['fields']['field_mentoring']['label'] = 'Status';
  $handler->display->display_options['fields']['field_mentoring']['type'] = 'select_or_other_formatter';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'reverse_field_mentor_kid_name_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Options';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_volunteer_mentor_name_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Volunteer Mentor Name';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'kids' => 'kids',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Mentor Type (field_mentor_type) */
  $handler->display->display_options['filters']['field_mentor_type_value']['id'] = 'field_mentor_type_value';
  $handler->display->display_options['filters']['field_mentor_type_value']['table'] = 'field_data_field_mentor_type';
  $handler->display->display_options['filters']['field_mentor_type_value']['field'] = 'field_mentor_type_value';
  $handler->display->display_options['filters']['field_mentor_type_value']['relationship'] = 'reverse_field_mentor_kid_name_node';
  $handler->display->display_options['filters']['field_mentor_type_value']['value'] = array(
    'Volunteer' => 'Volunteer',
  );
  $handler->display->display_options['filters']['field_mentor_type_value']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_volunteer_mentor_name_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Filter by Volunteer (as Mentor)';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title_1';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Mentoring Date (field_mentoring_date) */
  $handler->display->display_options['filters']['field_mentoring_date_value']['id'] = 'field_mentoring_date_value';
  $handler->display->display_options['filters']['field_mentoring_date_value']['table'] = 'field_data_field_mentoring_date';
  $handler->display->display_options['filters']['field_mentoring_date_value']['field'] = 'field_mentoring_date_value';
  $handler->display->display_options['filters']['field_mentoring_date_value']['relationship'] = 'reverse_field_mentor_kid_name_node';
  $handler->display->display_options['filters']['field_mentoring_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_mentoring_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_mentoring_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_mentoring_date_value']['expose']['operator_id'] = 'field_mentoring_date_value_op';
  $handler->display->display_options['filters']['field_mentoring_date_value']['expose']['label'] = 'Filter by start date';
  $handler->display->display_options['filters']['field_mentoring_date_value']['expose']['operator'] = 'field_mentoring_date_value_op';
  $handler->display->display_options['filters']['field_mentoring_date_value']['expose']['identifier'] = 'field_mentoring_date_value';
  $handler->display->display_options['filters']['field_mentoring_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_mentoring_date_value']['group_info']['label'] = 'Mentoring Date (field_mentoring_date)';
  $handler->display->display_options['filters']['field_mentoring_date_value']['group_info']['identifier'] = 'field_mentoring_date_value';
  $handler->display->display_options['filters']['field_mentoring_date_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_mentoring_date_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_mentoring_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_mentoring_date_value']['year_range'] = '-50:+2';
  /* Filter criterion: Content: Mentoring Date (field_mentoring_date) */
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['id'] = 'field_mentoring_date_value_1';
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['table'] = 'field_data_field_mentoring_date';
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['field'] = 'field_mentoring_date_value';
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['relationship'] = 'reverse_field_mentor_kid_name_node';
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['operator'] = '<=';
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['expose']['operator_id'] = 'field_mentoring_date_value_1_op';
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['expose']['label'] = 'Filter by end date';
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['expose']['operator'] = 'field_mentoring_date_value_1_op';
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['expose']['identifier'] = 'field_mentoring_date_value_1';
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_mentoring_date_value_1']['year_range'] = '-50:+3';
  $handler->display->display_options['path'] = 'list-kids-mentored';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['path'] = 'list-kids-mentored/export-xls';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Data export PDF */
  $handler = $view->new_display('views_data_export_pdf', 'Data export PDF', 'views_data_export_pdf_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_pdf';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['path'] = 'list-kids-mentored/export-pdf';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['list_kids_mentored'] = $view;

  $view = new view();
  $view->name = 'locations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Locations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Locations';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'plain_text',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'title' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_state' => 'field_state',
    'field_city' => 'field_city',
    'field_address_1' => 'field_address_1',
    'field_primary_phone_1' => 'field_primary_phone_1',
    'field_active_inactive' => 'field_active_inactive',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_city' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_address_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_primary_phone_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_active_inactive' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="novo-no-data-found">No data found.</div>';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = '';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['type'] = 'boolean';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span class="novo-title-published-[status]">[title]</span>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Options';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'locations' => 'locations',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'locations';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Locations';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-program-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['locations'] = $view;

  $view = new view();
  $view->name = 'mentor_filter_locations';
  $view->description = '';
  $view->tag = 'REF';
  $view->base_table = 'node';
  $view->human_name = 'Mentor Filter Locations (REF)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: In Program */
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['id'] = 'reverse_field_program_location_node';
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['field'] = 'reverse_field_program_location_node';
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['ui_name'] = 'In Program';
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['label'] = 'In Program';
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['required'] = TRUE;
  /* Relationship: In mentor */
  $handler->display->display_options['relationships']['reverse_field_mentor_program_name_node']['id'] = 'reverse_field_mentor_program_name_node';
  $handler->display->display_options['relationships']['reverse_field_mentor_program_name_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_mentor_program_name_node']['field'] = 'reverse_field_mentor_program_name_node';
  $handler->display->display_options['relationships']['reverse_field_mentor_program_name_node']['relationship'] = 'reverse_field_program_location_node';
  $handler->display->display_options['relationships']['reverse_field_mentor_program_name_node']['ui_name'] = 'In mentor';
  $handler->display->display_options['relationships']['reverse_field_mentor_program_name_node']['label'] = 'In mentor';
  $handler->display->display_options['relationships']['reverse_field_mentor_program_name_node']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'locations' => 'locations',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'reverse_field_program_location_node';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'program' => 'program',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_2']['id'] = 'type_2';
  $handler->display->display_options['filters']['type_2']['table'] = 'node';
  $handler->display->display_options['filters']['type_2']['field'] = 'type';
  $handler->display->display_options['filters']['type_2']['relationship'] = 'reverse_field_mentor_program_name_node';
  $handler->display->display_options['filters']['type_2']['value'] = array(
    'mentors' => 'mentors',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['mentor_filter_locations'] = $view;

  $view = new view();
  $view->name = 'mentor_filter_programs';
  $view->description = '';
  $view->tag = 'REF';
  $view->base_table = 'node';
  $view->human_name = 'Mentor Filter Programs (REF)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: In Mentors */
  $handler->display->display_options['relationships']['reverse_field_mentor_program_name_node']['id'] = 'reverse_field_mentor_program_name_node';
  $handler->display->display_options['relationships']['reverse_field_mentor_program_name_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_mentor_program_name_node']['field'] = 'reverse_field_mentor_program_name_node';
  $handler->display->display_options['relationships']['reverse_field_mentor_program_name_node']['ui_name'] = 'In Mentors';
  $handler->display->display_options['relationships']['reverse_field_mentor_program_name_node']['label'] = 'In Mentors';
  $handler->display->display_options['relationships']['reverse_field_mentor_program_name_node']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_program_school_year']['id'] = 'field_program_school_year';
  $handler->display->display_options['fields']['field_program_school_year']['table'] = 'field_data_field_program_school_year';
  $handler->display->display_options['fields']['field_program_school_year']['field'] = 'field_program_school_year';
  $handler->display->display_options['fields']['field_program_school_year']['label'] = '';
  $handler->display->display_options['fields']['field_program_school_year']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Location (field_program_location) */
  $handler->display->display_options['arguments']['field_program_location_target_id']['id'] = 'field_program_location_target_id';
  $handler->display->display_options['arguments']['field_program_location_target_id']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['arguments']['field_program_location_target_id']['field'] = 'field_program_location_target_id';
  $handler->display->display_options['arguments']['field_program_location_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_program_location_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_program_location_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_program_location_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program' => 'program',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'reverse_field_mentor_program_name_node';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'mentors' => 'mentors',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['mentor_filter_programs'] = $view;

  $view = new view();
  $view->name = 'mentor_kids_list_ref';
  $view->description = '';
  $view->tag = 'REF';
  $view->base_table = 'node';
  $view->human_name = 'Mentor Kids List (REF)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['separator'] = '-';
  /* Relationship: In Mentor */
  $handler->display->display_options['relationships']['reverse_field_p_kid_name_field_collection_item']['id'] = 'reverse_field_p_kid_name_field_collection_item';
  $handler->display->display_options['relationships']['reverse_field_p_kid_name_field_collection_item']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_p_kid_name_field_collection_item']['field'] = 'reverse_field_p_kid_name_field_collection_item';
  $handler->display->display_options['relationships']['reverse_field_p_kid_name_field_collection_item']['ui_name'] = 'In Mentor';
  $handler->display->display_options['relationships']['reverse_field_p_kid_name_field_collection_item']['label'] = 'In Mentor';
  $handler->display->display_options['relationships']['reverse_field_p_kid_name_field_collection_item']['required'] = TRUE;
  /* Relationship: Field collection item: Entity with the Kids list (field_program_kids_list) */
  $handler->display->display_options['relationships']['field_program_kids_list_node']['id'] = 'field_program_kids_list_node';
  $handler->display->display_options['relationships']['field_program_kids_list_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_program_kids_list_node']['field'] = 'field_program_kids_list_node';
  $handler->display->display_options['relationships']['field_program_kids_list_node']['relationship'] = 'reverse_field_p_kid_name_field_collection_item';
  $handler->display->display_options['relationships']['field_program_kids_list_node']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_p_kid_name_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_program_kids_list_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'kids' => 'kids',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'title_1' => 'title_1',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['mentor_kids_list_ref'] = $view;

  $view = new view();
  $view->name = 'mentor_programs_ref';
  $view->description = '';
  $view->tag = 'REF';
  $view->base_table = 'node';
  $view->human_name = 'Mentor Programs (REF)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Location (field_program_location) */
  $handler->display->display_options['arguments']['field_program_location_target_id']['id'] = 'field_program_location_target_id';
  $handler->display->display_options['arguments']['field_program_location_target_id']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['arguments']['field_program_location_target_id']['field'] = 'field_program_location_target_id';
  $handler->display->display_options['arguments']['field_program_location_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_program_location_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_program_location_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_program_location_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_program_location_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program' => 'program',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['mentor_programs_ref'] = $view;

  $view = new view();
  $view->name = 'mentors';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Mentors';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Mentors';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'plain_text',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'field_program_location_target_id_entityreference_filter' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_mentor_program_name_target_id_entityreference_filter' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_mentor_kid_name' => 'field_mentor_kid_name',
    'field_mentoring_date' => 'field_mentoring_date',
    'field_staff_mentor_name' => 'field_staff_mentor_name',
    'field_volunteer_mentor_name' => 'field_volunteer_mentor_name',
    'field_mentor_type' => 'field_mentor_type',
    'views_conditional' => 'views_conditional',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mentor_kid_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mentoring_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_staff_mentor_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_volunteer_mentor_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mentor_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_conditional' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="novo-no-data-found">No data found.</div>';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_mentor_program_name_target_id']['id'] = 'field_mentor_program_name_target_id';
  $handler->display->display_options['relationships']['field_mentor_program_name_target_id']['table'] = 'field_data_field_mentor_program_name';
  $handler->display->display_options['relationships']['field_mentor_program_name_target_id']['field'] = 'field_mentor_program_name_target_id';
  $handler->display->display_options['relationships']['field_mentor_program_name_target_id']['label'] = 'Program';
  $handler->display->display_options['relationships']['field_mentor_program_name_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_location_target_id']['id'] = 'field_program_location_target_id';
  $handler->display->display_options['relationships']['field_program_location_target_id']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['relationships']['field_program_location_target_id']['field'] = 'field_program_location_target_id';
  $handler->display->display_options['relationships']['field_program_location_target_id']['relationship'] = 'field_mentor_program_name_target_id';
  $handler->display->display_options['relationships']['field_program_location_target_id']['label'] = 'Location';
  $handler->display->display_options['relationships']['field_program_location_target_id']['required'] = TRUE;
  /* Field: Content: Kid Name */
  $handler->display->display_options['fields']['field_mentor_kid_name']['id'] = 'field_mentor_kid_name';
  $handler->display->display_options['fields']['field_mentor_kid_name']['table'] = 'field_data_field_mentor_kid_name';
  $handler->display->display_options['fields']['field_mentor_kid_name']['field'] = 'field_mentor_kid_name';
  $handler->display->display_options['fields']['field_mentor_kid_name']['label'] = 'Kid name';
  $handler->display->display_options['fields']['field_mentor_kid_name']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Mentoring Date */
  $handler->display->display_options['fields']['field_mentoring_date']['id'] = 'field_mentoring_date';
  $handler->display->display_options['fields']['field_mentoring_date']['table'] = 'field_data_field_mentoring_date';
  $handler->display->display_options['fields']['field_mentoring_date']['field'] = 'field_mentoring_date';
  $handler->display->display_options['fields']['field_mentoring_date']['label'] = 'Date';
  $handler->display->display_options['fields']['field_mentoring_date']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Staff Mentor Name */
  $handler->display->display_options['fields']['field_staff_mentor_name']['id'] = 'field_staff_mentor_name';
  $handler->display->display_options['fields']['field_staff_mentor_name']['table'] = 'field_data_field_staff_mentor_name';
  $handler->display->display_options['fields']['field_staff_mentor_name']['field'] = 'field_staff_mentor_name';
  $handler->display->display_options['fields']['field_staff_mentor_name']['label'] = '';
  $handler->display->display_options['fields']['field_staff_mentor_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_staff_mentor_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_staff_mentor_name']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Volunteer Mentor Name */
  $handler->display->display_options['fields']['field_volunteer_mentor_name']['id'] = 'field_volunteer_mentor_name';
  $handler->display->display_options['fields']['field_volunteer_mentor_name']['table'] = 'field_data_field_volunteer_mentor_name';
  $handler->display->display_options['fields']['field_volunteer_mentor_name']['field'] = 'field_volunteer_mentor_name';
  $handler->display->display_options['fields']['field_volunteer_mentor_name']['label'] = '';
  $handler->display->display_options['fields']['field_volunteer_mentor_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_volunteer_mentor_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_volunteer_mentor_name']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Mentor Type */
  $handler->display->display_options['fields']['field_mentor_type']['id'] = 'field_mentor_type';
  $handler->display->display_options['fields']['field_mentor_type']['table'] = 'field_data_field_mentor_type';
  $handler->display->display_options['fields']['field_mentor_type']['field'] = 'field_mentor_type';
  $handler->display->display_options['fields']['field_mentor_type']['label'] = '';
  $handler->display->display_options['fields']['field_mentor_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mentor_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mentor_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mentor_type']['type'] = 'list_key';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Options';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'mentors' => 'mentors',
  );
  /* Filter criterion: Content: Location (field_program_location) (reference filter) */
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['id'] = 'field_program_location_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['field'] = 'field_program_location_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['relationship'] = 'field_mentor_program_name_target_id';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['operator_id'] = 'field_program_location_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['label'] = 'Filter by Location';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['operator'] = 'field_program_location_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['identifier'] = 'field_program_location_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['reference_display'] = 'mentor_filter_locations:entityreference_1';
  /* Filter criterion: Content: Program Name (field_mentor_program_name) (reference filter) */
  $handler->display->display_options['filters']['field_mentor_program_name_target_id_entityreference_filter']['id'] = 'field_mentor_program_name_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_mentor_program_name_target_id_entityreference_filter']['table'] = 'field_data_field_mentor_program_name';
  $handler->display->display_options['filters']['field_mentor_program_name_target_id_entityreference_filter']['field'] = 'field_mentor_program_name_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_mentor_program_name_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_mentor_program_name_target_id_entityreference_filter']['expose']['operator_id'] = 'field_mentor_program_name_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_mentor_program_name_target_id_entityreference_filter']['expose']['label'] = 'Filter by Program';
  $handler->display->display_options['filters']['field_mentor_program_name_target_id_entityreference_filter']['expose']['operator'] = 'field_mentor_program_name_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_mentor_program_name_target_id_entityreference_filter']['expose']['identifier'] = 'field_mentor_program_name_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_mentor_program_name_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_mentor_program_name_target_id_entityreference_filter']['expose']['hide_empty_filter'] = FALSE;
  $handler->display->display_options['filters']['field_mentor_program_name_target_id_entityreference_filter']['reference_display'] = 'mentor_filter_programs:entityreference_1';
  $handler->display->display_options['filters']['field_mentor_program_name_target_id_entityreference_filter']['reference_arguments'] = '[field_program_location_target_id_entityreference_filter]';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'mentors';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Mentoring';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-program-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['mentors'] = $view;

  $view = new view();
  $view->name = 'partners';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Partners';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Partners';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'plain_text',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'title' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="novo-no-data-found">No data found.</div>';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = '';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['type'] = 'boolean';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span class="novo-title-published-[status]">[title]</span>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Options';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'partner' => 'partner',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'partners';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Partners';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $export['partners'] = $view;

  $view = new view();
  $view->name = 'program_filter_locations';
  $view->description = '';
  $view->tag = 'REF';
  $view->base_table = 'node';
  $view->human_name = 'Program Filter Locations (REF)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: In Program */
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['id'] = 'reverse_field_program_location_node';
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['field'] = 'reverse_field_program_location_node';
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['ui_name'] = 'In Program';
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['label'] = 'In Program';
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: School year (field_program_year) */
  $handler->display->display_options['arguments']['field_program_year_year']['id'] = 'field_program_year_year';
  $handler->display->display_options['arguments']['field_program_year_year']['table'] = 'field_data_field_program_year';
  $handler->display->display_options['arguments']['field_program_year_year']['field'] = 'field_program_year_year';
  $handler->display->display_options['arguments']['field_program_year_year']['relationship'] = 'reverse_field_program_location_node';
  $handler->display->display_options['arguments']['field_program_year_year']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_program_year_year']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_program_year_year']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_program_year_year']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'locations' => 'locations',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'reverse_field_program_location_node';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'program' => 'program',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['program_filter_locations'] = $view;

  $view = new view();
  $view->name = 'program_locations_list';
  $view->description = '';
  $view->tag = 'REF';
  $view->base_table = 'node';
  $view->human_name = 'Program Locations list (REF)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: In Class */
  $handler->display->display_options['relationships']['reverse_field_class_location_node']['id'] = 'reverse_field_class_location_node';
  $handler->display->display_options['relationships']['reverse_field_class_location_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_class_location_node']['field'] = 'reverse_field_class_location_node';
  $handler->display->display_options['relationships']['reverse_field_class_location_node']['ui_name'] = 'In Class';
  $handler->display->display_options['relationships']['reverse_field_class_location_node']['label'] = 'In Class';
  $handler->display->display_options['relationships']['reverse_field_class_location_node']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: School year (field_class_year) */
  $handler->display->display_options['arguments']['field_class_year_year']['id'] = 'field_class_year_year';
  $handler->display->display_options['arguments']['field_class_year_year']['table'] = 'field_data_field_class_year';
  $handler->display->display_options['arguments']['field_class_year_year']['field'] = 'field_class_year_year';
  $handler->display->display_options['arguments']['field_class_year_year']['relationship'] = 'reverse_field_class_location_node';
  $handler->display->display_options['arguments']['field_class_year_year']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_class_year_year']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_class_year_year']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_class_year_year']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'locations' => 'locations',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'reverse_field_class_location_node';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'class' => 'class',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['program_locations_list'] = $view;

  $view = new view();
  $view->name = 'programm_class_list';
  $view->description = '';
  $view->tag = 'REF';
  $view->base_table = 'node';
  $view->human_name = 'Programm class list (REF)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: In Program */
  $handler->display->display_options['relationships']['reverse_field_program_class_name_node']['id'] = 'reverse_field_program_class_name_node';
  $handler->display->display_options['relationships']['reverse_field_program_class_name_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_program_class_name_node']['field'] = 'reverse_field_program_class_name_node';
  $handler->display->display_options['relationships']['reverse_field_program_class_name_node']['ui_name'] = 'In Program';
  $handler->display->display_options['relationships']['reverse_field_program_class_name_node']['label'] = 'In Program';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: School year (field_class_year) */
  $handler->display->display_options['arguments']['field_class_year_year']['id'] = 'field_class_year_year';
  $handler->display->display_options['arguments']['field_class_year_year']['table'] = 'field_data_field_class_year';
  $handler->display->display_options['arguments']['field_class_year_year']['field'] = 'field_class_year_year';
  $handler->display->display_options['arguments']['field_class_year_year']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_class_year_year']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_class_year_year']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_class_year_year']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Location (field_class_location) */
  $handler->display->display_options['arguments']['field_class_location_target_id']['id'] = 'field_class_location_target_id';
  $handler->display->display_options['arguments']['field_class_location_target_id']['table'] = 'field_data_field_class_location';
  $handler->display->display_options['arguments']['field_class_location_target_id']['field'] = 'field_class_location_target_id';
  $handler->display->display_options['arguments']['field_class_location_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_class_location_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_class_location_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_class_location_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'class' => 'class',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['programm_class_list'] = $view;

  $view = new view();
  $view->name = 'programm_participated';
  $view->description = '';
  $view->tag = 'DYN';
  $view->base_table = 'node';
  $view->human_name = 'List Programm Participated';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'List Programm Participated';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'field_program_location' => 'field_program_location',
    'field_program_year' => 'field_program_year',
    'title' => 'title',
    'title_1' => 'title_1',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_program_location' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_program_year' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = 'Total @total paticipation';
  /* Relationship: In attendance */
  $handler->display->display_options['relationships']['reverse_field_attendance_program_name_node']['id'] = 'reverse_field_attendance_program_name_node';
  $handler->display->display_options['relationships']['reverse_field_attendance_program_name_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_attendance_program_name_node']['field'] = 'reverse_field_attendance_program_name_node';
  $handler->display->display_options['relationships']['reverse_field_attendance_program_name_node']['ui_name'] = 'In attendance';
  $handler->display->display_options['relationships']['reverse_field_attendance_program_name_node']['label'] = 'In attendance';
  $handler->display->display_options['relationships']['reverse_field_attendance_program_name_node']['required'] = TRUE;
  /* Relationship: Volunteer */
  $handler->display->display_options['relationships']['field_attendance_volunteer_list_target_id']['id'] = 'field_attendance_volunteer_list_target_id';
  $handler->display->display_options['relationships']['field_attendance_volunteer_list_target_id']['table'] = 'field_data_field_attendance_volunteer_list';
  $handler->display->display_options['relationships']['field_attendance_volunteer_list_target_id']['field'] = 'field_attendance_volunteer_list_target_id';
  $handler->display->display_options['relationships']['field_attendance_volunteer_list_target_id']['relationship'] = 'reverse_field_attendance_program_name_node';
  $handler->display->display_options['relationships']['field_attendance_volunteer_list_target_id']['ui_name'] = 'Volunteer';
  $handler->display->display_options['relationships']['field_attendance_volunteer_list_target_id']['label'] = 'Volunteer';
  $handler->display->display_options['relationships']['field_attendance_volunteer_list_target_id']['required'] = TRUE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_program_location']['id'] = 'field_program_location';
  $handler->display->display_options['fields']['field_program_location']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['fields']['field_program_location']['field'] = 'field_program_location';
  $handler->display->display_options['fields']['field_program_location']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: School year */
  $handler->display->display_options['fields']['field_program_year']['id'] = 'field_program_year';
  $handler->display->display_options['fields']['field_program_year']['table'] = 'field_data_field_program_year';
  $handler->display->display_options['fields']['field_program_year']['field'] = 'field_program_year';
  $handler->display->display_options['fields']['field_program_year']['type'] = 'year_academic';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Class name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_attendance_volunteer_list_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Volunteer Name';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Options';
  /* Sort criterion: Content: Location (field_program_location) */
  $handler->display->display_options['sorts']['field_program_location_target_id']['id'] = 'field_program_location_target_id';
  $handler->display->display_options['sorts']['field_program_location_target_id']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['sorts']['field_program_location_target_id']['field'] = 'field_program_location_target_id';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program' => 'program',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_attendance_volunteer_list_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title_1';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'list-programm-participated';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_program_location']['id'] = 'field_program_location';
  $handler->display->display_options['fields']['field_program_location']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['fields']['field_program_location']['field'] = 'field_program_location';
  $handler->display->display_options['fields']['field_program_location']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: School year */
  $handler->display->display_options['fields']['field_program_year']['id'] = 'field_program_year';
  $handler->display->display_options['fields']['field_program_year']['table'] = 'field_data_field_program_year';
  $handler->display->display_options['fields']['field_program_year']['field'] = 'field_program_year';
  $handler->display->display_options['fields']['field_program_year']['type'] = 'year_academic';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Class name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_attendance_volunteer_list_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Volunteer Name';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  $handler->display->display_options['path'] = 'list-programm-participated/export-xls';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Data export PDF */
  $handler = $view->new_display('views_data_export_pdf', 'Data export PDF', 'views_data_export_pdf_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_pdf';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_program_location']['id'] = 'field_program_location';
  $handler->display->display_options['fields']['field_program_location']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['fields']['field_program_location']['field'] = 'field_program_location';
  $handler->display->display_options['fields']['field_program_location']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: School year */
  $handler->display->display_options['fields']['field_program_year']['id'] = 'field_program_year';
  $handler->display->display_options['fields']['field_program_year']['table'] = 'field_data_field_program_year';
  $handler->display->display_options['fields']['field_program_year']['field'] = 'field_program_year';
  $handler->display->display_options['fields']['field_program_year']['type'] = 'year_academic';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Class name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_attendance_volunteer_list_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Volunteer Name';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  $handler->display->display_options['path'] = 'list-programm-participated/export-pdf';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['programm_participated'] = $view;

  $view = new view();
  $view->name = 'programs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Programs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Enrollments';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'plain_text',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'field_program_school_year_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
        'datepicker_options' => '',
      ),
    ),
    'field_program_location_target_id_entityreference_filter' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'status' => 'status',
    'title' => 'title',
    'field_program_school_year' => 'field_program_school_year',
    'field_program_location' => 'field_program_location',
    'field_program_class_name' => 'field_program_class_name',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_program_school_year' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_program_location' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_program_class_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="novo-no-data-found">No data found.</div>';
  /* Field: Content: School year */
  $handler->display->display_options['fields']['field_program_year']['id'] = 'field_program_year';
  $handler->display->display_options['fields']['field_program_year']['table'] = 'field_data_field_program_year';
  $handler->display->display_options['fields']['field_program_year']['field'] = 'field_program_year';
  $handler->display->display_options['fields']['field_program_year']['type'] = 'year_academic';
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_program_location']['id'] = 'field_program_location';
  $handler->display->display_options['fields']['field_program_location']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['fields']['field_program_location']['field'] = 'field_program_location';
  $handler->display->display_options['fields']['field_program_location']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Class name */
  $handler->display->display_options['fields']['field_program_class_name']['id'] = 'field_program_class_name';
  $handler->display->display_options['fields']['field_program_class_name']['table'] = 'field_data_field_program_class_name';
  $handler->display->display_options['fields']['field_program_class_name']['field'] = 'field_program_class_name';
  $handler->display->display_options['fields']['field_program_class_name']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Options';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program' => 'program',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: School year (field_program_year) */
  $handler->display->display_options['filters']['field_program_year_year']['id'] = 'field_program_year_year';
  $handler->display->display_options['filters']['field_program_year_year']['table'] = 'field_data_field_program_year';
  $handler->display->display_options['filters']['field_program_year_year']['field'] = 'field_program_year_year';
  $handler->display->display_options['filters']['field_program_year_year']['group'] = 1;
  $handler->display->display_options['filters']['field_program_year_year']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_year_year']['expose']['operator_id'] = 'field_program_year_year_op';
  $handler->display->display_options['filters']['field_program_year_year']['expose']['label'] = 'Filter by School year';
  $handler->display->display_options['filters']['field_program_year_year']['expose']['operator'] = 'field_program_year_year_op';
  $handler->display->display_options['filters']['field_program_year_year']['expose']['identifier'] = 'field_program_year_year';
  $handler->display->display_options['filters']['field_program_year_year']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Location (field_program_location) (reference filter) */
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['id'] = 'field_program_location_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['field'] = 'field_program_location_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['operator_id'] = 'field_program_location_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['label'] = 'Filter by Location';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['operator'] = 'field_program_location_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['identifier'] = 'field_program_location_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['hide_empty_filter'] = FALSE;
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['reference_display'] = 'program_filter_locations:entityreference_1';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['reference_arguments'] = '[field_program_year_year]';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'programs';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Enrollment';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-program-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['programs'] = $view;

  $view = new view();
  $view->name = 'ref_request_tasks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'novo_ref_tasks';
  $view->human_name = 'Ref request tasks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Ref request tasks';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'field_u_first_name' => 'field_u_first_name',
    'field_u_last_name' => 'field_u_first_name',
    'name' => 'name',
    'status' => 'status',
    'created' => 'created',
    'updated' => 'updated',
    'actions' => 'actions',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_u_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'field_u_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'updated' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'actions' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="novo-no-data-found">No data found.</div>';
  /* Relationship: Novo referral request tasks: User ID */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'novo_ref_tasks';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_u_first_name']['id'] = 'field_u_first_name';
  $handler->display->display_options['fields']['field_u_first_name']['table'] = 'field_data_field_u_first_name';
  $handler->display->display_options['fields']['field_u_first_name']['field'] = 'field_u_first_name';
  $handler->display->display_options['fields']['field_u_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_u_first_name']['label'] = 'User';
  $handler->display->display_options['fields']['field_u_first_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_u_first_name']['alter']['path'] = 'user/[uid]/edit';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_u_last_name']['id'] = 'field_u_last_name';
  $handler->display->display_options['fields']['field_u_last_name']['table'] = 'field_data_field_u_last_name';
  $handler->display->display_options['fields']['field_u_last_name']['field'] = 'field_u_last_name';
  $handler->display->display_options['fields']['field_u_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_u_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_u_last_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_u_last_name']['alter']['path'] = 'user/[uid]/edit';
  $handler->display->display_options['fields']['field_u_last_name']['element_label_colon'] = FALSE;
  /* Field: Novo referral request tasks: Task name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'novo_ref_tasks';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Name';
  /* Field: Novo referral request tasks: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'novo_ref_tasks';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  /* Field: Novo referral request tasks: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'novo_ref_tasks';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'today time ago';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'short';
  /* Field: Novo referral request tasks: Actions */
  $handler->display->display_options['fields']['actions']['id'] = 'actions';
  $handler->display->display_options['fields']['actions']['table'] = 'novo_ref_tasks';
  $handler->display->display_options['fields']['actions']['field'] = 'actions';
  /* Sort criterion: Novo referral request tasks: ID */
  $handler->display->display_options['sorts']['id']['id'] = 'id';
  $handler->display->display_options['sorts']['id']['table'] = 'novo_ref_tasks';
  $handler->display->display_options['sorts']['id']['field'] = 'id';
  $handler->display->display_options['sorts']['id']['order'] = 'DESC';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'ref-request-tasks';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Ref. request tasks';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $export['ref_request_tasks'] = $view;

  $view = new view();
  $view->name = 'roster_report';
  $view->description = '';
  $view->tag = 'Report';
  $view->base_table = 'node';
  $view->human_name = 'Roster Report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Roster Report';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'plain_text',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'field_program_school_year_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
        'datepicker_options' => '',
      ),
    ),
    'field_program_location_target_id_entityreference_filter' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'nid_entityreference_filter' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_p_canvassing_group_target_id_entityreference_filter' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_p_small_group_target_id_entityreference_filter' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_program_location',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'title_1' => 'title_1',
    'field_address_1' => 'field_address_1',
    'field_apt' => 'field_apt',
    'field_dob' => 'field_dob',
    'field_grade' => 'field_grade',
    'field_parent_guardian' => 'field_parent_guardian',
    'field_p_dismissal' => 'field_p_dismissal',
    'field_p_small_group' => 'field_p_small_group',
    'field_program_location' => 'field_program_location',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_address_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_apt' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dob' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_grade' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_parent_guardian' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_p_dismissal' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_p_small_group' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_program_location' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="novo-no-data-found">No data found.</div>';
  /* Relationship: Content: Kids list (field_program_kids_list) */
  $handler->display->display_options['relationships']['field_program_kids_list_value']['id'] = 'field_program_kids_list_value';
  $handler->display->display_options['relationships']['field_program_kids_list_value']['table'] = 'field_data_field_program_kids_list';
  $handler->display->display_options['relationships']['field_program_kids_list_value']['field'] = 'field_program_kids_list_value';
  $handler->display->display_options['relationships']['field_program_kids_list_value']['label'] = 'FC kids';
  $handler->display->display_options['relationships']['field_program_kids_list_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_program_kids_list_value']['delta'] = '-1';
  /* Relationship: Kid */
  $handler->display->display_options['relationships']['field_p_kid_name_target_id']['id'] = 'field_p_kid_name_target_id';
  $handler->display->display_options['relationships']['field_p_kid_name_target_id']['table'] = 'field_data_field_p_kid_name';
  $handler->display->display_options['relationships']['field_p_kid_name_target_id']['field'] = 'field_p_kid_name_target_id';
  $handler->display->display_options['relationships']['field_p_kid_name_target_id']['relationship'] = 'field_program_kids_list_value';
  $handler->display->display_options['relationships']['field_p_kid_name_target_id']['ui_name'] = 'Kid';
  $handler->display->display_options['relationships']['field_p_kid_name_target_id']['label'] = 'Kid';
  $handler->display->display_options['relationships']['field_p_kid_name_target_id']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_p_kid_name_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Children name';
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_address_1']['id'] = 'field_address_1';
  $handler->display->display_options['fields']['field_address_1']['table'] = 'field_data_field_address_1';
  $handler->display->display_options['fields']['field_address_1']['field'] = 'field_address_1';
  $handler->display->display_options['fields']['field_address_1']['relationship'] = 'field_p_kid_name_target_id';
  $handler->display->display_options['fields']['field_address_1']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_address_1']['settings'] = array(
    'trim_length' => '50',
  );
  /* Field: Content: Address Apartment number */
  $handler->display->display_options['fields']['field_apt']['id'] = 'field_apt';
  $handler->display->display_options['fields']['field_apt']['table'] = 'field_data_field_apt';
  $handler->display->display_options['fields']['field_apt']['field'] = 'field_apt';
  $handler->display->display_options['fields']['field_apt']['relationship'] = 'field_p_kid_name_target_id';
  $handler->display->display_options['fields']['field_apt']['label'] = 'Apt #';
  $handler->display->display_options['fields']['field_apt']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_apt']['settings'] = array(
    'trim_length' => '50',
  );
  /* Field: Content: Date of Birth */
  $handler->display->display_options['fields']['field_dob']['id'] = 'field_dob';
  $handler->display->display_options['fields']['field_dob']['table'] = 'field_data_field_dob';
  $handler->display->display_options['fields']['field_dob']['field'] = 'field_dob';
  $handler->display->display_options['fields']['field_dob']['relationship'] = 'field_p_kid_name_target_id';
  $handler->display->display_options['fields']['field_dob']['label'] = 'Age';
  $handler->display->display_options['fields']['field_dob']['type'] = 'only_age';
  $handler->display->display_options['fields']['field_dob']['settings'] = array(
    'format_type' => 'long',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Grade */
  $handler->display->display_options['fields']['field_grade']['id'] = 'field_grade';
  $handler->display->display_options['fields']['field_grade']['table'] = 'field_data_field_grade';
  $handler->display->display_options['fields']['field_grade']['field'] = 'field_grade';
  $handler->display->display_options['fields']['field_grade']['relationship'] = 'field_p_kid_name_target_id';
  $handler->display->display_options['fields']['field_grade']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Parent / Guardian List */
  $handler->display->display_options['fields']['field_parent_guardian']['id'] = 'field_parent_guardian';
  $handler->display->display_options['fields']['field_parent_guardian']['table'] = 'field_data_field_parent_guardian';
  $handler->display->display_options['fields']['field_parent_guardian']['field'] = 'field_parent_guardian';
  $handler->display->display_options['fields']['field_parent_guardian']['relationship'] = 'field_p_kid_name_target_id';
  $handler->display->display_options['fields']['field_parent_guardian']['label'] = 'Parent / Guardian';
  $handler->display->display_options['fields']['field_parent_guardian']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_parent_guardian']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_parent_guardian']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_parent_guardian']['separator'] = '<br>';
  /* Field: Field collection item: Dismissal */
  $handler->display->display_options['fields']['field_p_dismissal']['id'] = 'field_p_dismissal';
  $handler->display->display_options['fields']['field_p_dismissal']['table'] = 'field_data_field_p_dismissal';
  $handler->display->display_options['fields']['field_p_dismissal']['field'] = 'field_p_dismissal';
  $handler->display->display_options['fields']['field_p_dismissal']['relationship'] = 'field_program_kids_list_value';
  $handler->display->display_options['fields']['field_p_dismissal']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field collection item: Small Group */
  $handler->display->display_options['fields']['field_p_small_group']['id'] = 'field_p_small_group';
  $handler->display->display_options['fields']['field_p_small_group']['table'] = 'field_data_field_p_small_group';
  $handler->display->display_options['fields']['field_p_small_group']['field'] = 'field_p_small_group';
  $handler->display->display_options['fields']['field_p_small_group']['relationship'] = 'field_program_kids_list_value';
  $handler->display->display_options['fields']['field_p_small_group']['label'] = 'Group';
  $handler->display->display_options['fields']['field_p_small_group']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_p_small_group']['settings'] = array(
    'view_mode' => 'default',
    'links' => 0,
    'use_content_language' => 0,
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_program_location']['id'] = 'field_program_location';
  $handler->display->display_options['fields']['field_program_location']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['fields']['field_program_location']['field'] = 'field_program_location';
  $handler->display->display_options['fields']['field_program_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_program_location']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program' => 'program',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: School year (field_program_year) */
  $handler->display->display_options['filters']['field_program_year_year']['id'] = 'field_program_year_year';
  $handler->display->display_options['filters']['field_program_year_year']['table'] = 'field_data_field_program_year';
  $handler->display->display_options['filters']['field_program_year_year']['field'] = 'field_program_year_year';
  $handler->display->display_options['filters']['field_program_year_year']['group'] = 1;
  $handler->display->display_options['filters']['field_program_year_year']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_year_year']['expose']['operator_id'] = 'field_program_year_year_op';
  $handler->display->display_options['filters']['field_program_year_year']['expose']['label'] = 'Filter by School year';
  $handler->display->display_options['filters']['field_program_year_year']['expose']['operator'] = 'field_program_year_year_op';
  $handler->display->display_options['filters']['field_program_year_year']['expose']['identifier'] = 'field_program_year_year';
  $handler->display->display_options['filters']['field_program_year_year']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_program_year_year']['expose']['remember_roles'] = array(
    2 => 0,
    5 => '5',
    3 => '3',
    1 => 0,
    6 => 0,
  );
  /* Filter criterion: Content: Location (field_program_location) (reference filter) */
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['id'] = 'field_program_location_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['field'] = 'field_program_location_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['operator_id'] = 'field_program_location_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['label'] = 'Filter by Program Location';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['operator'] = 'field_program_location_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['identifier'] = 'field_program_location_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => 0,
    5 => '5',
    3 => '3',
    1 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['expose']['hide_empty_filter'] = FALSE;
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['reference_display'] = 'roster_report_program_locations_list:entityreference_1';
  $handler->display->display_options['filters']['field_program_location_target_id_entityreference_filter']['reference_arguments'] = '[field_program_year_year]';
  /* Filter criterion: Content: Nid (reference filter) */
  $handler->display->display_options['filters']['nid_entityreference_filter']['id'] = 'nid_entityreference_filter';
  $handler->display->display_options['filters']['nid_entityreference_filter']['table'] = 'node';
  $handler->display->display_options['filters']['nid_entityreference_filter']['field'] = 'nid_entityreference_filter';
  $handler->display->display_options['filters']['nid_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['nid_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid_entityreference_filter']['expose']['operator_id'] = 'nid_entityreference_filter_op';
  $handler->display->display_options['filters']['nid_entityreference_filter']['expose']['label'] = 'Filter by Program name';
  $handler->display->display_options['filters']['nid_entityreference_filter']['expose']['operator'] = 'nid_entityreference_filter_op';
  $handler->display->display_options['filters']['nid_entityreference_filter']['expose']['identifier'] = 'nid_entityreference_filter';
  $handler->display->display_options['filters']['nid_entityreference_filter']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['nid_entityreference_filter']['expose']['remember_roles'] = array(
    2 => 0,
    5 => '5',
    3 => '3',
    1 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['nid_entityreference_filter']['expose']['hide_empty_filter'] = FALSE;
  $handler->display->display_options['filters']['nid_entityreference_filter']['reference_display'] = 'canvassing_report_filter_program:entityreference_1';
  $handler->display->display_options['filters']['nid_entityreference_filter']['reference_arguments'] = '[field_program_year_year]/[field_program_location_target_id_entityreference_filter]';
  /* Filter criterion: Field collection item: Canvassing Group (field_p_canvassing_group) (reference filter) */
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['id'] = 'field_p_canvassing_group_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['table'] = 'field_data_field_p_canvassing_group';
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['field'] = 'field_p_canvassing_group_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['relationship'] = 'field_program_kids_list_value';
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['expose']['operator_id'] = 'field_p_canvassing_group_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['expose']['label'] = 'Filter by Canvasing Group';
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['expose']['operator'] = 'field_p_canvassing_group_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['expose']['identifier'] = 'field_p_canvassing_group_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => 0,
    5 => '5',
    3 => '3',
    1 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['expose']['hide_empty_filter'] = FALSE;
  $handler->display->display_options['filters']['field_p_canvassing_group_target_id_entityreference_filter']['reference_display'] = 'canvassing_group:entityreference_1';
  /* Filter criterion: Field collection item: Small Group (field_p_small_group) (reference filter) */
  $handler->display->display_options['filters']['field_p_small_group_target_id_entityreference_filter']['id'] = 'field_p_small_group_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_p_small_group_target_id_entityreference_filter']['table'] = 'field_data_field_p_small_group';
  $handler->display->display_options['filters']['field_p_small_group_target_id_entityreference_filter']['field'] = 'field_p_small_group_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_p_small_group_target_id_entityreference_filter']['relationship'] = 'field_program_kids_list_value';
  $handler->display->display_options['filters']['field_p_small_group_target_id_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['field_p_small_group_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_p_small_group_target_id_entityreference_filter']['expose']['operator_id'] = 'field_p_small_group_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_p_small_group_target_id_entityreference_filter']['expose']['label'] = 'Filter by Small Group';
  $handler->display->display_options['filters']['field_p_small_group_target_id_entityreference_filter']['expose']['operator'] = 'field_p_small_group_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_p_small_group_target_id_entityreference_filter']['expose']['identifier'] = 'field_p_small_group_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_p_small_group_target_id_entityreference_filter']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_p_small_group_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => 0,
    5 => '5',
    3 => '3',
    1 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_p_small_group_target_id_entityreference_filter']['expose']['hide_empty_filter'] = FALSE;
  $handler->display->display_options['filters']['field_p_small_group_target_id_entityreference_filter']['reference_display'] = 'small_groups:entityreference_1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'roster-report';
  $handler->display->display_options['menu']['title'] = 'Canvassing Report';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_program_location',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['path'] = 'roster-report/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['segment_size'] = '100';

  /* Display: Data export PDF */
  $handler = $view->new_display('views_data_export_pdf', 'Data export PDF', 'views_data_export_pdf_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_pdf';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_program_location',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['path'] = 'roster-report/export-pdf';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['segment_size'] = '1';
  $export['roster_report'] = $view;

  $view = new view();
  $view->name = 'roster_report_program_locations_list';
  $view->description = '';
  $view->tag = 'REF';
  $view->base_table = 'node';
  $view->human_name = 'Roster Report Program Locations list (REF)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: In Program */
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['id'] = 'reverse_field_program_location_node';
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['field'] = 'reverse_field_program_location_node';
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['ui_name'] = 'In Program';
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['label'] = 'In Program';
  $handler->display->display_options['relationships']['reverse_field_program_location_node']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: School year (field_program_year) */
  $handler->display->display_options['arguments']['field_program_year_year']['id'] = 'field_program_year_year';
  $handler->display->display_options['arguments']['field_program_year_year']['table'] = 'field_data_field_program_year';
  $handler->display->display_options['arguments']['field_program_year_year']['field'] = 'field_program_year_year';
  $handler->display->display_options['arguments']['field_program_year_year']['relationship'] = 'reverse_field_program_location_node';
  $handler->display->display_options['arguments']['field_program_year_year']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_program_year_year']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_program_year_year']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_program_year_year']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'locations' => 'locations',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'reverse_field_program_location_node';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'program' => 'program',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['roster_report_program_locations_list'] = $view;

  $view = new view();
  $view->name = 'site_field_options_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Site field options list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_class_location' => 'field_class_location',
    'field_program_day' => 'field_program_day',
    'title' => 'title',
  );
  $handler->display->display_options['row_options']['separator'] = ', ';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_class_location']['id'] = 'field_class_location';
  $handler->display->display_options['fields']['field_class_location']['table'] = 'field_data_field_class_location';
  $handler->display->display_options['fields']['field_class_location']['field'] = 'field_class_location';
  $handler->display->display_options['fields']['field_class_location']['label'] = '';
  $handler->display->display_options['fields']['field_class_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_class_location']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_class_location']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Program day */
  $handler->display->display_options['fields']['field_program_day']['id'] = 'field_program_day';
  $handler->display->display_options['fields']['field_program_day']['table'] = 'field_data_field_program_day';
  $handler->display->display_options['fields']['field_program_day']['field'] = 'field_program_day';
  $handler->display->display_options['fields']['field_program_day']['label'] = '';
  $handler->display->display_options['fields']['field_program_day']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_day']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_program_day']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_program_day']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_program_day']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_program_day']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '([title])';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Location (field_class_location) */
  $handler->display->display_options['sorts']['field_class_location_target_id']['id'] = 'field_class_location_target_id';
  $handler->display->display_options['sorts']['field_class_location_target_id']['table'] = 'field_data_field_class_location';
  $handler->display->display_options['sorts']['field_class_location_target_id']['field'] = 'field_class_location_target_id';
  /* Sort criterion: Content: Program day (field_program_day) */
  $handler->display->display_options['sorts']['field_program_day_value']['id'] = 'field_program_day_value';
  $handler->display->display_options['sorts']['field_program_day_value']['table'] = 'field_data_field_program_day';
  $handler->display->display_options['sorts']['field_program_day_value']['field'] = 'field_program_day_value';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'class' => 'class',
  );
  $export['site_field_options_list'] = $view;

  $view = new view();
  $view->name = 'small_groups';
  $view->description = '';
  $view->tag = 'REF';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Small groups (REF)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Color */
  $handler->display->display_options['fields']['field_color']['id'] = 'field_color';
  $handler->display->display_options['fields']['field_color']['table'] = 'field_data_field_color';
  $handler->display->display_options['fields']['field_color']['field'] = 'field_color';
  $handler->display->display_options['fields']['field_color']['label'] = '';
  $handler->display->display_options['fields']['field_color']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_color']['click_sort_column'] = 'rgb';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'small_group' => 'small_group',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['separator'] = ' |';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['small_groups'] = $view;

  $view = new view();
  $view->name = 'staff';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Staff';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Staff';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'plain_text',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'title' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_last_name' => 'field_last_name',
    'field_primary_phone_1' => 'field_primary_phone_1',
    'field_email' => 'field_email',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_primary_phone_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_email' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="novo-no-data-found">No data found.</div>';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = '';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['type'] = 'boolean';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span class="novo-title-published-[status]">[title]</span>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['type'] = 'email_plain';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Options';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'staff' => 'staff',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'staff';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Staff';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $export['staff'] = $view;

  $view = new view();
  $view->name = 'staff_ref';
  $view->description = '';
  $view->tag = 'REF';
  $view->base_table = 'node';
  $view->human_name = 'Staff (REF)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'staff' => 'staff',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['staff_ref'] = $view;

  $view = new view();
  $view->name = 'training_list';
  $view->description = '';
  $view->tag = 'REF';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Training list (REF)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'training' => 'training',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['training_list'] = $view;

  $view = new view();
  $view->name = 'users';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Users';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'plain_text',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'field_u_first_name_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_u_last_name_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'mail' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'rid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_u_first_name' => 'field_u_first_name',
    'field_u_last_name' => 'field_u_last_name',
    'mail' => 'mail',
    'rid' => 'rid',
    'status' => 'status',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_u_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_u_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="novo-no-data-found">No data found.</div>';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_u_first_name']['id'] = 'field_u_first_name';
  $handler->display->display_options['fields']['field_u_first_name']['table'] = 'field_data_field_u_first_name';
  $handler->display->display_options['fields']['field_u_first_name']['field'] = 'field_u_first_name';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_u_last_name']['id'] = 'field_u_last_name';
  $handler->display->display_options['fields']['field_u_last_name']['table'] = 'field_data_field_u_last_name';
  $handler->display->display_options['fields']['field_u_last_name']['field'] = 'field_u_last_name';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['label'] = 'Role';
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: User: User's Novo application status */
  $handler->display->display_options['fields']['novo_application_status']['id'] = 'novo_application_status';
  $handler->display->display_options['fields']['novo_application_status']['table'] = 'users';
  $handler->display->display_options['fields']['novo_application_status']['field'] = 'novo_application_status';
  $handler->display->display_options['fields']['novo_application_status']['label'] = 'Application';
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Options';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: First Name (field_u_first_name) */
  $handler->display->display_options['filters']['field_u_first_name_value']['id'] = 'field_u_first_name_value';
  $handler->display->display_options['filters']['field_u_first_name_value']['table'] = 'field_data_field_u_first_name';
  $handler->display->display_options['filters']['field_u_first_name_value']['field'] = 'field_u_first_name_value';
  $handler->display->display_options['filters']['field_u_first_name_value']['operator'] = 'word';
  $handler->display->display_options['filters']['field_u_first_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_u_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_u_first_name_value']['expose']['operator_id'] = 'field_u_first_name_value_op';
  $handler->display->display_options['filters']['field_u_first_name_value']['expose']['label'] = 'First Name';
  $handler->display->display_options['filters']['field_u_first_name_value']['expose']['operator'] = 'field_u_first_name_value_op';
  $handler->display->display_options['filters']['field_u_first_name_value']['expose']['identifier'] = 'field_u_first_name_value';
  $handler->display->display_options['filters']['field_u_first_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: User: Last Name (field_u_last_name) */
  $handler->display->display_options['filters']['field_u_last_name_value']['id'] = 'field_u_last_name_value';
  $handler->display->display_options['filters']['field_u_last_name_value']['table'] = 'field_data_field_u_last_name';
  $handler->display->display_options['filters']['field_u_last_name_value']['field'] = 'field_u_last_name_value';
  $handler->display->display_options['filters']['field_u_last_name_value']['operator'] = 'word';
  $handler->display->display_options['filters']['field_u_last_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_u_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_u_last_name_value']['expose']['operator_id'] = 'field_u_last_name_value_op';
  $handler->display->display_options['filters']['field_u_last_name_value']['expose']['label'] = 'Last Name';
  $handler->display->display_options['filters']['field_u_last_name_value']['expose']['operator'] = 'field_u_last_name_value_op';
  $handler->display->display_options['filters']['field_u_last_name_value']['expose']['identifier'] = 'field_u_last_name_value';
  $handler->display->display_options['filters']['field_u_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['operator'] = 'word';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['operator_id'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['label'] = 'Roles';
  $handler->display->display_options['filters']['rid']['expose']['operator'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['identifier'] = 'rid';
  $handler->display->display_options['filters']['rid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    6 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'users';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Users';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $export['users'] = $view;

  $view = new view();
  $view->name = 'volunteer_activity_report';
  $view->description = '';
  $view->tag = 'Report';
  $view->base_table = 'node';
  $view->human_name = 'Volunteer Activity Report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Volunteer Activity Report';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'plain_text',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'novo_application_active_status' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'novo_application_active_status' => 'novo_application_active_status',
    'novo_application_last_date_serving' => 'novo_application_last_date_serving',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'novo_application_active_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'novo_application_last_date_serving' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="novo-no-data-found">No data found.</div>';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Full name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Novo application active status */
  $handler->display->display_options['fields']['novo_application_active_status']['id'] = 'novo_application_active_status';
  $handler->display->display_options['fields']['novo_application_active_status']['table'] = 'node';
  $handler->display->display_options['fields']['novo_application_active_status']['field'] = 'novo_application_active_status';
  $handler->display->display_options['fields']['novo_application_active_status']['label'] = 'Activity';
  $handler->display->display_options['fields']['novo_application_active_status']['element_label_colon'] = FALSE;
  /* Field: Content: Novo application Last date serving */
  $handler->display->display_options['fields']['novo_application_last_date_serving']['id'] = 'novo_application_last_date_serving';
  $handler->display->display_options['fields']['novo_application_last_date_serving']['table'] = 'node';
  $handler->display->display_options['fields']['novo_application_last_date_serving']['field'] = 'novo_application_last_date_serving';
  $handler->display->display_options['fields']['novo_application_last_date_serving']['label'] = 'Last date serving';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'application' => 'application',
  );
  /* Filter criterion: Content: Novo application active status */
  $handler->display->display_options['filters']['novo_application_active_status']['id'] = 'novo_application_active_status';
  $handler->display->display_options['filters']['novo_application_active_status']['table'] = 'node';
  $handler->display->display_options['filters']['novo_application_active_status']['field'] = 'novo_application_active_status';
  $handler->display->display_options['filters']['novo_application_active_status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['novo_application_active_status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['novo_application_active_status']['expose']['label'] = 'Filter by month activity';
  $handler->display->display_options['filters']['novo_application_active_status']['expose']['operator'] = 'novo_application_active_status_op';
  $handler->display->display_options['filters']['novo_application_active_status']['expose']['identifier'] = 'novo_application_active_status';
  $handler->display->display_options['filters']['novo_application_active_status']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['novo_application_active_status']['expose']['remember_roles'] = array(
    2 => 0,
    5 => '5',
    3 => '3',
    1 => 0,
    6 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'volunteer-activity-report';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['path'] = 'volunteer-activity-report/export-xls';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Data export PDF */
  $handler = $view->new_display('views_data_export_pdf', 'Data export PDF', 'views_data_export_pdf_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_pdf';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['path'] = 'volunteer-activity-report/export-pdf';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['volunteer_activity_report'] = $view;

  $view = new view();
  $view->name = 'volunteer_birthdays_report';
  $view->description = '';
  $view->tag = 'Report';
  $view->base_table = 'node';
  $view->human_name = 'Volunteer Birthdays Report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Volunteer Birthdays Report';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_dob' => 'field_dob',
    'field_dob_1' => 'field_dob_1',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dob' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dob_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="novo-no-data-found">No data found.</div>';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Full name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Date of Birth */
  $handler->display->display_options['fields']['field_dob']['id'] = 'field_dob';
  $handler->display->display_options['fields']['field_dob']['table'] = 'field_data_field_dob';
  $handler->display->display_options['fields']['field_dob']['field'] = 'field_dob';
  $handler->display->display_options['fields']['field_dob']['type'] = 'advanced_dob';
  $handler->display->display_options['fields']['field_dob']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Date of Birth */
  $handler->display->display_options['fields']['field_dob_1']['id'] = 'field_dob_1';
  $handler->display->display_options['fields']['field_dob_1']['table'] = 'field_data_field_dob';
  $handler->display->display_options['fields']['field_dob_1']['field'] = 'field_dob';
  $handler->display->display_options['fields']['field_dob_1']['label'] = 'Age';
  $handler->display->display_options['fields']['field_dob_1']['type'] = 'only_age';
  $handler->display->display_options['fields']['field_dob_1']['settings'] = array(
    'format_type' => 'long',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'application' => 'application',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search by name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => 0,
    5 => '5',
    3 => '3',
    1 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'volunteer-birthdays-report';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['path'] = 'volunteer-birthdays-report/export-xls';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Data export PDF */
  $handler = $view->new_display('views_data_export_pdf', 'Data export PDF', 'views_data_export_pdf_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_pdf';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['path'] = 'volunteer-birthdays-report/export-pdf';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['volunteer_birthdays_report'] = $view;

  $view = new view();
  $view->name = 'volunteer_interests_roles';
  $view->description = '';
  $view->tag = 'REF';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'VOLUNTEER INTERESTS / ROLES (REF)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Time */
  $handler->display->display_options['fields']['field_vol_roles_time']['id'] = 'field_vol_roles_time';
  $handler->display->display_options['fields']['field_vol_roles_time']['table'] = 'field_data_field_vol_roles_time';
  $handler->display->display_options['fields']['field_vol_roles_time']['field'] = 'field_vol_roles_time';
  $handler->display->display_options['fields']['field_vol_roles_time']['label'] = '';
  $handler->display->display_options['fields']['field_vol_roles_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_vol_roles_time']['type'] = 'icon_times';
  $handler->display->display_options['fields']['field_vol_roles_time']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'volunteer_interests_roles' => 'volunteer_interests_roles',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
    'description' => 0,
    'field_vol_roles_time' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['volunteer_interests_roles'] = $view;

  $view = new view();
  $view->name = 'volunteers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Volunteers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Volunteers';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'plain_text',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'title' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'status_1' => 'status_1',
    'title' => 'title',
    'field_parent_guardian_last_name' => 'field_parent_guardian_last_name',
    'field_app_status' => 'field_app_status',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'status_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_parent_guardian_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_app_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="novo-no-data-found">No data found.</div>';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status_1']['id'] = 'status_1';
  $handler->display->display_options['fields']['status_1']['table'] = 'node';
  $handler->display->display_options['fields']['status_1']['field'] = 'status';
  $handler->display->display_options['fields']['status_1']['label'] = '';
  $handler->display->display_options['fields']['status_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status_1']['type'] = 'boolean';
  $handler->display->display_options['fields']['status_1']['not'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span class="novo-title-published-[status_1]">[title]</span>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Novo application status */
  $handler->display->display_options['fields']['novo_application_status']['id'] = 'novo_application_status';
  $handler->display->display_options['fields']['novo_application_status']['table'] = 'node';
  $handler->display->display_options['fields']['novo_application_status']['field'] = 'novo_application_status';
  $handler->display->display_options['fields']['novo_application_status']['label'] = 'Status';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Options';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'application' => 'application',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'volunteers';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Volunteers';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $export['volunteers'] = $view;

  $view = new view();
  $view->name = 'volunteers_ref';
  $view->description = '';
  $view->tag = 'REF';
  $view->base_table = 'node';
  $view->human_name = 'volunteers (REF)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'application' => 'application',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['volunteers_ref'] = $view;

  $view = new view();
  $view->name = 'what_want_site';
  $view->description = '';
  $view->tag = 'REF';
  $view->base_table = 'node';
  $view->human_name = 'What want site (REF)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_program_location']['id'] = 'field_program_location';
  $handler->display->display_options['fields']['field_program_location']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['fields']['field_program_location']['field'] = 'field_program_location';
  $handler->display->display_options['fields']['field_program_location']['label'] = '';
  $handler->display->display_options['fields']['field_program_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_location']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Program day */
  $handler->display->display_options['fields']['field_program_day']['id'] = 'field_program_day';
  $handler->display->display_options['fields']['field_program_day']['table'] = 'field_data_field_program_day';
  $handler->display->display_options['fields']['field_program_day']['field'] = 'field_program_day';
  $handler->display->display_options['fields']['field_program_day']['label'] = '';
  $handler->display->display_options['fields']['field_program_day']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_day']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_program_day']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_program_day']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program' => 'program',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_program_location' => 'field_program_location',
    'title' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['what_want_site'] = $view;

  return $export;
}
