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
      4 => 'field_ref_2_phone_1',
      5 => 'field_ref_2_phone_2',
      6 => 'field_ref_2_how_long',
      7 => 'field_ref_2_how_long_period',
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
      4 => 'field_ref_3_phone_1',
      5 => 'field_ref_3_phone_2',
      6 => 'field_ref_3_how_long',
      7 => 'field_ref_3_how_long_period',
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
      15 => 'field_masked_phone_1',
      16 => 'field_masked_phone_2',
      17 => 'field_prefix',
      18 => 'title',
      19 => 'group_app_emergency_contact',
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
      1 => 'group_app_1_employment',
      2 => 'group_app_1_education',
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
      4 => 'field_ref_1_phone_1',
      5 => 'field_ref_1_phone_2',
      6 => 'field_ref_1_how_long',
      7 => 'field_ref_1_how_long_period',
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
      0 => 'group_app_3_references_1',
      1 => 'group_app3_reference_3',
      2 => 'group_app3_reference_2',
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
      0 => 'group_app_4_questions',
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
  $field_group->identifier = 'group_app_emergency_contact|node|application|form';
  $field_group->group_name = 'group_app_emergency_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_app_1_contact';
  $field_group->data = array(
    'label' => 'Emergency Contact',
    'weight' => '66',
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

  // Translatables
  // Included for use with string extractors like potx.
  t('CONTACT / PERSONAL INFORMATION');
  t('EDUCATION');
  t('EMPLOYMENT / OCCUPATION');
  t('Emergency Contact');
  t('List');
  t('MINISTRY / VOLUNTEER EXPERIENCE');
  t('PERTINENT QUESTIONS');
  t('REFERENCES');
  t('Reference 1:');
  t('Reference 2:');
  t('Standby Reference');
  t('Step 1');
  t('Step 2');
  t('Step 3');
  t('Step 4');
  t('VOLUNTEER INTERESTS / ROLES');

  return $field_groups;
}
