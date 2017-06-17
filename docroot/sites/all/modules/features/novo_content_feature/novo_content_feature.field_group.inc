<?php
/**
 * @file
 * novo_content_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function novo_content_feature_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_apl_step1|node|application|form';
  $field_group->group_name = 'group_apl_step1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Step 1',
    'weight' => '0',
    'children' => array(
      0 => 'group_app_1_list',
    ),
    'format_type' => 'multistep',
    'format_settings' => array(
      'label' => 'Step 1',
      'instance_settings' => array(
        'description' => '',
        'nav_label' => '',
      ),
    ),
  );
  $field_groups['group_apl_step1|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_apl_step2|node|application|form';
  $field_group->group_name = 'group_apl_step2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Step 2',
    'weight' => '1',
    'children' => array(
      0 => 'group_app_2_list',
    ),
    'format_type' => 'multistep',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'description' => '',
        'nav_label' => '',
        'classes' => 'group-apl-step2 field-group-multistep',
      ),
    ),
  );
  $field_groups['group_apl_step2|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_apl_step3|node|application|form';
  $field_group->group_name = 'group_apl_step3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Step 3',
    'weight' => '2',
    'children' => array(
      0 => 'group_app_3_list',
    ),
    'format_type' => 'multistep',
    'format_settings' => array(
      'label' => 'Step 3',
      'instance_settings' => array(
        'description' => '',
        'nav_label' => '',
      ),
    ),
  );
  $field_groups['group_apl_step3|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_apl_step4|node|application|form';
  $field_group->group_name = 'group_apl_step4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Step 4',
    'weight' => '3',
    'children' => array(
      0 => 'group_app_4_list',
    ),
    'format_type' => 'multistep',
    'format_settings' => array(
      'label' => 'Step 4',
      'instance_settings' => array(
        'description' => '',
        'nav_label' => '',
      ),
    ),
  );
  $field_groups['group_apl_step4|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_apl_step5|node|application|form';
  $field_group->group_name = 'group_apl_step5';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Step 5',
    'weight' => '4',
    'children' => array(
      0 => 'group_app_5_list',
    ),
    'format_type' => 'multistep',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'description' => '',
        'nav_label' => '',
        'classes' => 'group-apl-step5 field-group-multistep',
      ),
    ),
  );
  $field_groups['group_apl_step5|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_apl_step6|node|application|form';
  $field_group->group_name = 'group_apl_step6';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Step 6',
    'weight' => '5',
    'children' => array(
      0 => 'group_app_6_list',
    ),
    'format_type' => 'multistep',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'description' => '',
        'nav_label' => '',
        'classes' => 'group-apl-step6 field-group-multistep',
      ),
    ),
  );
  $field_groups['group_apl_step6|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_apl_step7|node|application|form';
  $field_group->group_name = 'group_apl_step7';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Step 7',
    'weight' => '6',
    'children' => array(
      0 => 'group_app_7_list',
    ),
    'format_type' => 'multistep',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'description' => '',
        'nav_label' => '',
        'classes' => 'group-apl-step7 field-group-multistep',
      ),
    ),
  );
  $field_groups['group_apl_step7|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_apl_step8|node|application|form';
  $field_group->group_name = 'group_apl_step8';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Step 8',
    'weight' => '7',
    'children' => array(
      0 => 'group_app_8_list',
    ),
    'format_type' => 'multistep',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'description' => '',
        'nav_label' => '',
        'classes' => 'group-apl-step8 field-group-multistep',
      ),
    ),
  );
  $field_groups['group_apl_step8|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app3_reference_2|node|application|form';
  $field_group->group_name = 'group_app3_reference_2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_app_3_references';
  $field_group->data = array(
    'label' => 'Reference 2:',
    'weight' => '72',
    'children' => array(
      0 => 'field_ref_2_prefix',
      1 => 'field_ref_2_first_name',
      2 => 'field_ref_2_last_name',
      3 => 'field_ref_2_email',
      4 => 'field_ref_2_how_long',
      5 => 'field_ref_2_how_long_period',
      6 => 'field_ref_2_phone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-app3-reference-2 field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_app3_reference_2|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app3_reference_3|node|application|form';
  $field_group->group_name = 'group_app3_reference_3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_app_3_references';
  $field_group->data = array(
    'label' => 'Standby Reference',
    'weight' => '73',
    'children' => array(
      0 => 'field_ref_3_prefix',
      1 => 'field_ref_3_first_name',
      2 => 'field_ref_3_last_name',
      3 => 'field_ref_3_email',
      4 => 'field_ref_3_how_long',
      5 => 'field_ref_3_how_long_period',
      6 => 'field_ref_3_phone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-app3-reference-3 field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_app3_reference_3|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_1_contact|node|application|form';
  $field_group->group_name = 'group_app_1_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_app_1_list';
  $field_group->data = array(
    'label' => 'CONTACT / PERSONAL INFORMATION',
    'weight' => '45',
    'children' => array(
      0 => 'field_goes_by',
      1 => 'field_middle',
      2 => 'field_last_name',
      3 => 'field_maiden_name_or_alias_names',
      4 => 'field_address_1',
      5 => 'field_address_2',
      6 => 'field_city',
      7 => 'field_state',
      8 => 'field_zip',
      9 => 'field_dob',
      10 => 'field_email',
      11 => 'field_t_shirt_size',
      12 => 'field_color_preference',
      13 => 'field_how_did_you_hear_about_nov',
      14 => 'field_what_site_want',
      15 => 'field_prefix',
      16 => 'field_phone',
      17 => 'title',
      18 => 'group_app_emergency_contact',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'CONTACT / PERSONAL INFORMATION',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-app-1-contact field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_app_1_contact|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_1_education|node|application|form';
  $field_group->group_name = 'group_app_1_education';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_app_1_list';
  $field_group->data = array(
    'label' => 'EDUCATION',
    'weight' => '47',
    'children' => array(
      0 => 'field_edu_level',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-app-1-education field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_app_1_education|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_1_employment|node|application|form';
  $field_group->group_name = 'group_app_1_employment';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_app_1_list';
  $field_group->data = array(
    'label' => 'EMPLOYMENT / OCCUPATION',
    'weight' => '46',
    'children' => array(
      0 => 'field_employer',
      1 => 'field_empl_title',
      2 => 'field_empl_length',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'EMPLOYMENT / OCCUPATION',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-app-1-employment field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_app_1_employment|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_1_list|node|application|form';
  $field_group->group_name = 'group_app_1_list';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_apl_step1';
  $field_group->data = array(
    'label' => 'List',
    'weight' => '44',
    'children' => array(
      0 => 'group_app_1_contact',
      1 => 'group_app_1_education',
      2 => 'group_app_1_employment',
      3 => 'group_app_1_ministry',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'label' => 'List',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-app-1-list field-group-accordion',
        'effect' => 'none',
      ),
    ),
  );
  $field_groups['group_app_1_list|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_1_ministry|node|application|form';
  $field_group->group_name = 'group_app_1_ministry';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_app_1_list';
  $field_group->data = array(
    'label' => 'MINISTRY / VOLUNTEER EXPERIENCE',
    'weight' => '48',
    'children' => array(
      0 => 'field_ministry_experience',
      1 => 'field_ministry_cert',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-app-1-ministry field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_app_1_ministry|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_2_list|node|application|form';
  $field_group->group_name = 'group_app_2_list';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_apl_step2';
  $field_group->data = array(
    'label' => 'List',
    'weight' => '50',
    'children' => array(
      0 => 'group_app_2_roles',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'label' => 'List',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-app-2-list field-group-accordion',
        'effect' => 'none',
      ),
    ),
  );
  $field_groups['group_app_2_list|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_2_roles|node|application|form';
  $field_group->group_name = 'group_app_2_roles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_app_2_list';
  $field_group->data = array(
    'label' => 'VOLUNTEER INTERESTS / ROLES',
    'weight' => '50',
    'children' => array(
      0 => 'field_volunteer_interests_roles',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'VOLUNTEER INTERESTS / ROLES',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-app-2-roles field-group-accordion-item',
        'description' => 'Please mark ALL roles you may be interested in, and we will discuss with you the option that best suits your calling.
<span><i class="fa fa-clock-o"></i> = 1 Hour Commitment</span>',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_app_2_roles|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_3_list|node|application|form';
  $field_group->group_name = 'group_app_3_list';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_apl_step3';
  $field_group->data = array(
    'label' => 'List',
    'weight' => '71',
    'children' => array(
      0 => 'group_app_3_references',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'label' => 'List',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-app-3-list field-group-accordion',
        'effect' => 'none',
      ),
    ),
  );
  $field_groups['group_app_3_list|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_3_references_1|node|application|form';
  $field_group->group_name = 'group_app_3_references_1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_app_3_references';
  $field_group->data = array(
    'label' => 'Reference 1:',
    'weight' => '71',
    'children' => array(
      0 => 'field_ref_1_prefix',
      1 => 'field_ref_1_first_name',
      2 => 'field_ref_1_last_name',
      3 => 'field_ref_1_email',
      4 => 'field_ref_1_how_long',
      5 => 'field_ref_1_how_long_period',
      6 => 'field_ref_1_phone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-app-3-references-1 field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_app_3_references_1|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_3_references|node|application|form';
  $field_group->group_name = 'group_app_3_references';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_app_3_list';
  $field_group->data = array(
    'label' => 'REFERENCES',
    'weight' => '71',
    'children' => array(
      0 => 'group_app3_reference_2',
      1 => 'group_app3_reference_3',
      2 => 'group_app_3_references_1',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'REFERENCES',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-app-3-references field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_app_3_references|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_4_beliefs|node|application|form';
  $field_group->group_name = 'group_app_4_beliefs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_app_4_list';
  $field_group->data = array(
    'label' => 'PERSONAL BELIEFS',
    'weight' => '119',
    'children' => array(
      0 => 'field_beliefs_q1',
      1 => 'field_beliefs_q2',
      2 => 'field_beliefs_q3',
      3 => 'field_beliefs_q4',
      4 => 'field_beliefs_q5',
      5 => 'field_beliefs_q6',
      6 => 'field_beliefs_q7',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'PERSONAL BELIEFS',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Please check the statements that apply to you.',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_app_4_beliefs|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_4_church|node|application|form';
  $field_group->group_name = 'group_app_4_church';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_app_4_list';
  $field_group->data = array(
    'label' => 'CHURCH ATTENDANCE AND BACKGROUND',
    'weight' => '118',
    'children' => array(
      0 => 'field_church_home',
      1 => 'field_church_how_long_attended',
      2 => 'field_church_prev',
      3 => 'field_church_reference',
      4 => 'field_church_email',
      5 => 'field_church_phone_1',
      6 => 'field_church_phone_2',
      7 => 'field_church_phone',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_app_4_church|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_4_list|node|application|form';
  $field_group->group_name = 'group_app_4_list';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_apl_step4';
  $field_group->data = array(
    'label' => 'List',
    'weight' => '95',
    'children' => array(
      0 => 'group_app_4_beliefs',
      1 => 'group_app_4_church',
      2 => 'group_app_4_questions',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-app-4-list field-group-accordion',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_app_4_list|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_4_questions|node|application|form';
  $field_group->group_name = 'group_app_4_questions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_app_4_list';
  $field_group->data = array(
    'label' => 'PERTINENT QUESTIONS',
    'weight' => '117',
    'children' => array(
      0 => 'field_pertinent_q1',
      1 => 'field_pertinent_q2',
      2 => 'field_pertinent_q3',
      3 => 'field_pertinent_q4',
      4 => 'field_pertinent_q5',
      5 => 'field_pertinent_q6',
      6 => 'field_pertinent_q7',
      7 => 'field_pertinent_q8',
      8 => 'field_pertinent_q9',
      9 => 'field_pertinent_q10',
      10 => 'field_pertinent_q11',
      11 => 'field_pertinent_q12',
      12 => 'field_pertinent_q13',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'PERTINENT QUESTIONS',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-app-4-questions field-group-accordion-item',
        'description' => 'In order to best protect and serve the children with whom you may be working, please answer all questions truthfully. We pledge to protect your privacy in these sensitive issues and promise to handle all matters appropriately and with the utmost integrity and discretion.',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_app_4_questions|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_5_beliefs|node|application|form';
  $field_group->group_name = 'group_app_5_beliefs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_app_5_list';
  $field_group->data = array(
    'label' => 'PERSONAL BELIEFS',
    'weight' => '145',
    'children' => array(
      0 => 'field_beliefs2_q1',
      1 => 'field_beliefs2_q2',
      2 => 'field_beliefs2_q3',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'PERSONAL BELIEFS',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-app-5-beliefs field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_app_5_beliefs|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_5_list|node|application|form';
  $field_group->group_name = 'group_app_5_list';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_apl_step5';
  $field_group->data = array(
    'label' => 'List',
    'weight' => '144',
    'children' => array(
      0 => 'group_app_5_beliefs',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-app-5-list field-group-accordion',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_app_5_list|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_6_list|node|application|form';
  $field_group->group_name = 'group_app_6_list';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_apl_step6';
  $field_group->data = array(
    'label' => 'List',
    'weight' => '147',
    'children' => array(
      0 => 'group_app_6_things',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-app-6-list field-group-accordion',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_app_6_list|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_6_things|node|application|form';
  $field_group->group_name = 'group_app_6_things';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_app_6_list';
  $field_group->data = array(
    'label' => 'THINGS TO KNOW ABOUT NOVO',
    'weight' => '147',
    'children' => array(
      0 => 'field_things_q1',
      1 => 'field_things_q2',
      2 => 'field_things_q3',
      3 => 'field_things_q4',
      4 => 'field_things_q5',
      5 => 'field_things_q6',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'THINGS TO KNOW ABOUT NOVO',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-app-6-things field-group-accordion-item',
        'description' => '<p><b>Uniformity in Programming</b></p>
<p>At Novo, we have specific requirements in place for our Novo Bible Club programs and volunteers that allow us to provide a high-level of on-going support to partners and volunteers who fnd this type of support and opportunity best meets their needs when reaching out to inner-city boys and girls.</p>
<p>The standards and requirements we have in place allow us to maintain a level of uniformity in programming which provides opportunity for successful:</p>
<ul>
    <li>Outcomes measurement (overseen by Dr. Denise Caudill, Outcome Zone)</li>
    <li>Adherence to best practices (determined by OKAN and Center for Youth Program Quality)</li>
    <li>Program evaluation assessments (through the David P. Weikhart Center for Youth Program Quality)</li>
    <li>Signifcant and comprehensive funding (through foundations, corporations, individuals, and churches)</li>
    <li>Collaboration among partners and volunteers (diverse denominational and cultural backgrounds)</li>
    <li>And, ultimately, the fulfllment of our mission!</li>
</ul>

<p>&nbsp;</p>
<p><b>Our Moral and Legal Responsibility</b></p>
<p>At Novo, we are keenly aware of our moral and legal responsibility in providing programming – we connect screened and trained volunteers who have committed to adhering to our child protection and other pertinent policies. Our Novo program model follows a small group / large group format, all volunteers use Novo curriculum, and it is facilitated by a Novo staff member.</p>

<p>&nbsp;</p>
<p><b>Deference to Other Volunteers and Partners</b></p>
<p>Deference to other volunteers and partners for the overall impact and work of the organization is a hallmark of our operations. We are amazed to see individuals, churches, and other organizations coming together to reach out to the inner city. Our volunteers and partners agree on foundational truths and teaching and agree to use this opportunity to set aside differences and bring the “church” to the “community”. We maintain standards and continuity in programming to protect and preserve individual integrity and beliefs, while providing a much needed corporate opportunity. Our program requirements are not to inhibit ownership, a level of autonomy, or effective ministry. Instead they reinforce the concept that Novo programming can and should simply be a segue, a starting point for consistent outreach in which a much larger approach and ministry can be established in a specifc community.</p>

<p>&nbsp;</p>
<p><b>Agreement with Core Purpose and Goals</b></p>
<p>It is important to us that those who serve in a Novo program understand and agree with our core purpose — introducing inner-city children to Jesus, and mentoring them towards and in a relationship with Him — as well as a few additional areas which we highly value</p>

<p>I agree with the following and am willing to support these goals and purposes in Novo programming:</p>',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_app_6_things|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_7_final|node|application|form';
  $field_group->group_name = 'group_app_7_final';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_app_7_list';
  $field_group->data = array(
    'label' => 'FINAL AUTHORIZATION',
    'weight' => '155',
    'children' => array(
      0 => 'field_app_7_final_agree_1',
      1 => 'field_app_7_final_agree_2',
      2 => 'field_app_7_final_agree_3',
      3 => 'field_app_7_final_agree_4',
      4 => 'field_app_7_final_agree_5',
      5 => 'field_app_7_final_agree_6',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'FINAL AUTHORIZATION',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-app-7-final field-group-accordion-item',
        'description' => '<b>By signing below, I indicate that:</b>',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_app_7_final|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_7_list|node|application|form';
  $field_group->group_name = 'group_app_7_list';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_apl_step7';
  $field_group->data = array(
    'label' => 'List',
    'weight' => '147',
    'children' => array(
      0 => 'group_app_7_final',
      1 => 'group_app_7_program_policies',
      2 => 'group_app_7_statement',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-app-7-list field-group-accordion',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_app_7_list|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_7_program_policies|node|application|form';
  $field_group->group_name = 'group_app_7_program_policies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_app_7_list';
  $field_group->data = array(
    'label' => 'PERTINENT PROGRAM POLICIES',
    'weight' => '154',
    'children' => array(
      0 => 'field_program_policies_agree',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'PERTINENT PROGRAM POLICIES',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-app-7-program-policies field-group-accordion-item',
        'description' => '<h3>Child-Related Policies</h3>

<p><b>Child Abuse and Neglect Policy</b><br>
<ul>
<li>You have a moral and legal responsibility to report suspicion of abuse or neglect.</li>
    <li>As a Novo volunteer, you are required by our policies to notify us.</li>
    <li>As a resident of the state of Oklahoma, you are required by law to notify DHS.</li>
</ul>
</p>

<p><b>Child Information Policy</b><br>
    <ul>
        <li>Be careful with confdential information.</li>
        <li>Always let parents or guardians know who you are and what your role is so as to prevent any concerns and instead to build trust.</li>
</ul>
</p>


<p><b>Photo and Video Policy</b><br>
    <ul>
        <li>Do not publish an image and include:
            <ul>
                <li>First and last name of a child and his or her image.</li>
                <li>First and last name of a child and his or her location (with or without image).</li>
                <li>First name only, image and location.</li>
                <li>Child’s name tag in readable format (frst and last name).</li>
            </ul>
        </li>
        <li>Check and ensure photo permission before you photograph any children!</li>
</ul>
</p>


<p><b>Permission Slip Policy</b><br>
    <ul>
        <li>Every child must have a completed, signed, and permission slip in order to attend programming!</li>
</ul>
</p>


<h3>Child-Related Policies</h3>
<p><b>Permission Slip Policy</b><br>

    <ul>
        <li>Every child must have a completed, signed, and permission slip in order to attend programming!</li>
</ul>
</p>

<p><b>Check-In / Check-Out Policy</b><br>
    <ul>
        <li>Parent or guardian permission is an absolute must before releasing a child early from the program!</li>
</ul>
</p>


<p><b>Child Pick-Up Policy</b><br>
    <ul>
        <li>Children may only be released to those designated on the permission slip.</li>
</ul>
</p>

<p><b>Child Drop-Off Policy</b><br>
    <ul>
        <li>Never leave a child unattended at home or anywhere else!</li>
</ul>
</p>
        

<h3>Discipline Policies</h3>

<p><b>Physical Restraint Policy</b><br>
    <ul>
        <li>Get your program leadership if a child is in danger of hurting himself or others.</li>
        <li>Never physically restrain a child without appropriate training!</li>
</ul>
</p>

<p><b>Anti-Bullying Policy</b><br>
    <ul>
        <li>Bullying is unacceptable and must be addressed in order to protect our children!</li>
</ul>
</p>


<h3>Health and Safety Policies</h3>
<p><b>Contagious Illness or Condition Policy</b><br>
    <ul>
        <li>Children who may have contagious illness or condition should not attend a Novo program.</li>
        <li>If ill or contagious children arrive at the program or become sick while there, treat them with love and understanding and make arrangements for them discreetly.</li>
</ul>
   </p>

<p><b>Inclement Weather Policy</b><br>
    <ul>
    <li>Do not allow children to walk home when there is visible lightning or audible thunder, hail, and / or other weather conditions which might jeopardize their safety.</li>
    <li>Familiarize yourself with your site’s emergency procedures in case of severe weather.</li>
</ul>
</p>


<p><b>Weapons Policy</b><br>
    <ul>
        <li>Toy weapons should be turned over to the Novo program leadership.</li>
        <li>Real weapons should be confscated from children and emergency procedures followed.</li>
        <li>Volunteers should leave any personal weapons in a locked vehicle or at home.</li>
</ul>
</p>


<p><b>Violence Policy</b><br>
    <ul>
        <li>The senior-most Novo staff member will assume operational command in case of an emergency.</li>
    <li>Familiarize yourself with your site’s emergency procedures in case of violence</li>
</ul>
</p>
            

<h3>Volunteer Protection Policies</h3>

<p><b>Volunteer Protection Policy</b><br>
    <ul>
        <li>Make sure there are always two non-related individuals present whenever you are with children or anywhere children might be present.</li>
        <li>Never ever be alone with a child.</li>
</ul>
</p>

<p><b>Bathroom Policy</b><br>
    <ul>
        <li>Never go into a bathroom with a child or children — notify your program leadership.</li>
</ul>
</p>

<p><b>Volunteer Screening Policy</b><br>
    <ul>
        <li>All volunteers must complete a volunteer application and the screening process must be complete before serving.</li>
</ul>
</p>

<p><b>Physical Contact Policy</b><br>
    <ul>
        <li>Always avoid any inappropriate contact or communication.</li>
        <li>Report any accidental contact or communication to your Novo program leadership immediately for direction and guidance.</li>
</ul>
</p>


<p><b>Personal Activities Policy</b><br>
    <ul>
        <li>We encourage you to plan and participate in personal activities with your children!</li>
        <li>Notifcation of your plans helps us help you with ideas or any questions or concerns from parents or guardians!</li>
</ul>
</p>

<p><b>I hereby certify that:</b></p>',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_app_7_program_policies|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_7_statement|node|application|form';
  $field_group->group_name = 'group_app_7_statement';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_app_7_list';
  $field_group->data = array(
    'label' => 'OUR STATEMENT OF FAITH',
    'weight' => '153',
    'children' => array(
      0 => 'field_app7_statement_agree',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'OUR STATEMENT OF FAITH',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-app-7-statement field-group-accordion-item',
        'description' => '<p><b>About Scripture:</b><br>
The Bible is 100% true and is God’s Word. The Holy Spirit guided men to write down words from God – the Bible is the supreme authority for our faith and practices. (2 Timothy 3:16; Deuteronomy 4:2; 2 Peter 1:21)
</p>

<p><b>About God:</b><br>
God is one God Who exists eternally as three distinct Persons Who are of the same substance: God the Father, God the Son, and God the Holy Spirit. God loves every single person. God is holy, just, absolutely perfect, and lives in Heaven. (Colossians 1:16; Matthew 5:48; Deuteronomy 4:35)
</p>

<p><b>About Humanity:</b><br>
Adam was created in the image of God. By voluntary choice, he sinned; and now all of humanity is sinful by nature and practice. Sin is anything thought, said, or done that breaks God’s Law. Every single person has sinned. The punishment for sin is death – eternal punishment in Hell and separation from God forever. (Genesis 1-3; Colossians 1:16, I John 3:4, Romans 3:23, Romans 6:23, 2 Thessalonians 1:8-9; Hebrews 9:27)
</p>

<p><b>About Jesus Christ:</b><br>
God the Father sent Jesus, God the Son, to die on the cross as a Substitute for the sins of humanity. His sacrifcial death was payment and justifcation for God’s forgiveness of sin. After His death on the cross, He was buried in a tomb. He rose again the third day, having conquered death and sin. (I Peter 2:22; John 10:30; II Corinthians 5:21, I Corinthians 15:3-4)
</p>

<p><b>About the Gospel:</b><br>
The Gospel means “Good News.” Because of Jesus’s shed blood and substitutionary death, we can be forgiven of our sin, born again of the Spirit of God, and have a personal relationship with God. The Gospel is life-changing; a relationship with Jesus Christ is irrefutably powerful and utterly unique. (John 5:24; Romans 3:28; Eph. 1:3; John 17:23)
</p>

<p><b>About Salvation:</b><br>
There is no work, good deed, habit, or action that can earn God’s love or forgiveness or provide propitiation for sin. Only through faith and trust alone in Jesus Christ’s saving work on the cross can we repent of our sins and be made right with God, receiving forgiveness of sin, being given a new, redeemed nature, and entering in a personal relationship with Him. Baptism is an outward expression of inward change. It signifes a believer’s union with Christ in His death, burial, and resurrection. Baptism is the frst step of obedience after a believer receives Jesus as Savior. (Acts 16:31; Ephesians 2:8-9; Galatians 2:20; Acts 3:19; Acts 2:38; Romans 6:4; I Corinthians 12:13)
</p>

<p><b>About Satan:</b><br>
Satan is a personal being that opposes God and works unceasingly (tirelessly, constantly) to keep people from knowing and serving Him. (Revelation 12:9; Ephesians 6:11-12; 1 Peter 5:8)
</p>

<p><b>About the Church:</b><br>
The Church is the Body and Bride of Christ. It is made up of all those who have believed the Gospel and accepted Jesus Christ as their Savior. (Ephesians 1:22-23; 2:19-22; Romans 12:4-5; Ephesians 4:3-6; Galatians 5:13-15)
</p>

<p><b>About the Holy Spirit:</b><br>
All who have been saved receive the Holy Spirit to empower, direct, correct, and lead them as they follow Jesus Christ. (Hebrews 9:15; John 5:24; Romans 3:28; John 17:23; Galatians 4:6-7; 5:16; Acts 1:8)
</p>

<p><b>About the Christian Life:</b><br>
All believers are called to follow Jesus Christ. Their purpose is to glorify God in the way they live and make Him known to the lost world. They are called to fulfll the Great Commission. (Philippians 2:1-5; Matthew 28:19-20, Galatians 6:10; 1 John 2:15-16; 1 Corinthians 10:31; Ephesians 2:10, Mark 16:15; 2 Corinthians 5:18-19)
</p>

<p><b>I hereby certify that:</b></p>',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_app_7_statement|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_8_additional|node|application|form';
  $field_group->group_name = 'group_app_8_additional';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_app_8_list';
  $field_group->data = array(
    'label' => 'ADDITIONAL INFORMATION',
    'weight' => '161',
    'children' => array(
      0 => 'field_expired_date',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'ADDITIONAL INFORMATION',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-app-8-additional field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_app_8_additional|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_8_list|node|application|form';
  $field_group->group_name = 'group_app_8_list';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_apl_step8';
  $field_group->data = array(
    'label' => 'List',
    'weight' => '147',
    'children' => array(
      0 => 'group_app_8_additional',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-app-8-list field-group-accordion',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_app_8_list|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_emergency_contact|node|application|form';
  $field_group->group_name = 'group_app_emergency_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_app_1_contact';
  $field_group->data = array(
    'label' => 'Emergency Contact',
    'weight' => '67',
    'children' => array(
      0 => 'field_emergency_name',
      1 => 'field_relationship',
      2 => 'field_masked_emergency_phone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-app-emergency-contact field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_app_emergency_contact|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_group|field_collection_item|field_program_kids_list|form';
  $field_group->group_name = 'group_p_group';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_program_kids_list';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '4',
    'children' => array(
      0 => 'field_p_small_group',
      1 => 'field_p_canvassing_group',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'field-p-group-wrapper',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_p_group|field_collection_item|field_program_kids_list|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('ADDITIONAL INFORMATION');
  t('CHURCH ATTENDANCE AND BACKGROUND');
  t('CONTACT / PERSONAL INFORMATION');
  t('EDUCATION');
  t('EMPLOYMENT / OCCUPATION');
  t('Emergency Contact');
  t('FINAL AUTHORIZATION');
  t('List');
  t('MINISTRY / VOLUNTEER EXPERIENCE');
  t('OUR STATEMENT OF FAITH');
  t('PERSONAL BELIEFS');
  t('PERTINENT PROGRAM POLICIES');
  t('PERTINENT QUESTIONS');
  t('REFERENCES');
  t('Reference 1:');
  t('Reference 2:');
  t('Standby Reference');
  t('Step 1');
  t('Step 2');
  t('Step 3');
  t('Step 4');
  t('Step 5');
  t('Step 6');
  t('Step 7');
  t('Step 8');
  t('THINGS TO KNOW ABOUT NOVO');
  t('VOLUNTEER INTERESTS / ROLES');

  return $field_groups;
}
