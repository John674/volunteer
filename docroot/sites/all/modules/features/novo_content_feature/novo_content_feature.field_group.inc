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
      0 => 'field_goes_by',
      1 => 'field_middle',
      2 => 'field_last_name',
      3 => 'field_maiden_name_or_alias_names',
      4 => 'field_address_1',
      5 => 'field_address_2',
      6 => 'title',
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
    'weight' => '9',
    'children' => array(
      0 => 'field_city',
      1 => 'field_state',
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
    'weight' => '10',
    'children' => array(
      0 => 'field_zip',
    ),
    'format_type' => 'multistep',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'description' => '',
        'nav_label' => '',
        'classes' => 'group-apl-step3 field-group-multistep',
      ),
    ),
  );
  $field_groups['group_apl_step3|node|application|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Step 1');
  t('Step 2');
  t('Step 3');

  return $field_groups;
}
