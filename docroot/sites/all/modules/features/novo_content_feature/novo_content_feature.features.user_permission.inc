<?php
/**
 * @file
 * novo_content_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function novo_content_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_app_status'.
  $permissions['create field_app_status'] = array(
    'name' => 'create field_app_status',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_app_user'.
  $permissions['create field_app_user'] = array(
    'name' => 'create field_app_user',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_color_preference'.
  $permissions['create field_color_preference'] = array(
    'name' => 'create field_color_preference',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_completed'.
  $permissions['create field_completed'] = array(
    'name' => 'create field_completed',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_edu_level'.
  $permissions['create field_edu_level'] = array(
    'name' => 'create field_edu_level',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_email'.
  $permissions['create field_email'] = array(
    'name' => 'create field_email',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_empl_length'.
  $permissions['create field_empl_length'] = array(
    'name' => 'create field_empl_length',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_empl_title'.
  $permissions['create field_empl_title'] = array(
    'name' => 'create field_empl_title',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_employer'.
  $permissions['create field_employer'] = array(
    'name' => 'create field_employer',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_expired_date'.
  $permissions['create field_expired_date'] = array(
    'name' => 'create field_expired_date',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_faq_a'.
  $permissions['create field_faq_a'] = array(
    'name' => 'create field_faq_a',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_gender'.
  $permissions['create field_gender'] = array(
    'name' => 'create field_gender',
    'roles' => array(
      'Reviewer' => 'Reviewer',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_how_did_you_hear_about_nov'.
  $permissions['create field_how_did_you_hear_about_nov'] = array(
    'name' => 'create field_how_did_you_hear_about_nov',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_ministry_cert'.
  $permissions['create field_ministry_cert'] = array(
    'name' => 'create field_ministry_cert',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_ministry_experience'.
  $permissions['create field_ministry_experience'] = array(
    'name' => 'create field_ministry_experience',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_notes'.
  $permissions['create field_notes'] = array(
    'name' => 'create field_notes',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_reference_request_1'.
  $permissions['create field_reference_request_1'] = array(
    'name' => 'create field_reference_request_1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_reference_request_2'.
  $permissions['create field_reference_request_2'] = array(
    'name' => 'create field_reference_request_2',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_reference_request_church'.
  $permissions['create field_reference_request_church'] = array(
    'name' => 'create field_reference_request_church',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_reference_request_parents'.
  $permissions['create field_reference_request_parents'] = array(
    'name' => 'create field_reference_request_parents',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_reference_request_standby'.
  $permissions['create field_reference_request_standby'] = array(
    'name' => 'create field_reference_request_standby',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_ssn'.
  $permissions['create field_ssn'] = array(
    'name' => 'create field_ssn',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_texting'.
  $permissions['create field_texting'] = array(
    'name' => 'create field_texting',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_volunteer_interests_roles'.
  $permissions['create field_volunteer_interests_roles'] = array(
    'name' => 'create field_volunteer_interests_roles',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_what_site_you_want'.
  $permissions['create field_what_site_you_want'] = array(
    'name' => 'create field_what_site_you_want',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_app_status'.
  $permissions['edit field_app_status'] = array(
    'name' => 'edit field_app_status',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_app_user'.
  $permissions['edit field_app_user'] = array(
    'name' => 'edit field_app_user',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_color_preference'.
  $permissions['edit field_color_preference'] = array(
    'name' => 'edit field_color_preference',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_completed'.
  $permissions['edit field_completed'] = array(
    'name' => 'edit field_completed',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_edu_level'.
  $permissions['edit field_edu_level'] = array(
    'name' => 'edit field_edu_level',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_email'.
  $permissions['edit field_email'] = array(
    'name' => 'edit field_email',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_empl_length'.
  $permissions['edit field_empl_length'] = array(
    'name' => 'edit field_empl_length',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_empl_title'.
  $permissions['edit field_empl_title'] = array(
    'name' => 'edit field_empl_title',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_employer'.
  $permissions['edit field_employer'] = array(
    'name' => 'edit field_employer',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_expired_date'.
  $permissions['edit field_expired_date'] = array(
    'name' => 'edit field_expired_date',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_faq_a'.
  $permissions['edit field_faq_a'] = array(
    'name' => 'edit field_faq_a',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_gender'.
  $permissions['edit field_gender'] = array(
    'name' => 'edit field_gender',
    'roles' => array(
      'Reviewer' => 'Reviewer',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_how_did_you_hear_about_nov'.
  $permissions['edit field_how_did_you_hear_about_nov'] = array(
    'name' => 'edit field_how_did_you_hear_about_nov',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_ministry_cert'.
  $permissions['edit field_ministry_cert'] = array(
    'name' => 'edit field_ministry_cert',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_ministry_experience'.
  $permissions['edit field_ministry_experience'] = array(
    'name' => 'edit field_ministry_experience',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_notes'.
  $permissions['edit field_notes'] = array(
    'name' => 'edit field_notes',
    'roles' => array(
      'Reviewer' => 'Reviewer',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_reference_request_1'.
  $permissions['edit field_reference_request_1'] = array(
    'name' => 'edit field_reference_request_1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_reference_request_2'.
  $permissions['edit field_reference_request_2'] = array(
    'name' => 'edit field_reference_request_2',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_reference_request_church'.
  $permissions['edit field_reference_request_church'] = array(
    'name' => 'edit field_reference_request_church',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_reference_request_parents'.
  $permissions['edit field_reference_request_parents'] = array(
    'name' => 'edit field_reference_request_parents',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_reference_request_standby'.
  $permissions['edit field_reference_request_standby'] = array(
    'name' => 'edit field_reference_request_standby',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_ssn'.
  $permissions['edit field_ssn'] = array(
    'name' => 'edit field_ssn',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_texting'.
  $permissions['edit field_texting'] = array(
    'name' => 'edit field_texting',
    'roles' => array(
      'Reviewer' => 'Reviewer',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_volunteer_interests_roles'.
  $permissions['edit field_volunteer_interests_roles'] = array(
    'name' => 'edit field_volunteer_interests_roles',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_what_site_you_want'.
  $permissions['edit field_what_site_you_want'] = array(
    'name' => 'edit field_what_site_you_want',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_app_status'.
  $permissions['edit own field_app_status'] = array(
    'name' => 'edit own field_app_status',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_app_user'.
  $permissions['edit own field_app_user'] = array(
    'name' => 'edit own field_app_user',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_color_preference'.
  $permissions['edit own field_color_preference'] = array(
    'name' => 'edit own field_color_preference',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_completed'.
  $permissions['edit own field_completed'] = array(
    'name' => 'edit own field_completed',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_edu_level'.
  $permissions['edit own field_edu_level'] = array(
    'name' => 'edit own field_edu_level',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_email'.
  $permissions['edit own field_email'] = array(
    'name' => 'edit own field_email',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_empl_length'.
  $permissions['edit own field_empl_length'] = array(
    'name' => 'edit own field_empl_length',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_empl_title'.
  $permissions['edit own field_empl_title'] = array(
    'name' => 'edit own field_empl_title',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_employer'.
  $permissions['edit own field_employer'] = array(
    'name' => 'edit own field_employer',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_expired_date'.
  $permissions['edit own field_expired_date'] = array(
    'name' => 'edit own field_expired_date',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_faq_a'.
  $permissions['edit own field_faq_a'] = array(
    'name' => 'edit own field_faq_a',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_gender'.
  $permissions['edit own field_gender'] = array(
    'name' => 'edit own field_gender',
    'roles' => array(
      'Reviewer' => 'Reviewer',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_how_did_you_hear_about_nov'.
  $permissions['edit own field_how_did_you_hear_about_nov'] = array(
    'name' => 'edit own field_how_did_you_hear_about_nov',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_ministry_cert'.
  $permissions['edit own field_ministry_cert'] = array(
    'name' => 'edit own field_ministry_cert',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_ministry_experience'.
  $permissions['edit own field_ministry_experience'] = array(
    'name' => 'edit own field_ministry_experience',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_notes'.
  $permissions['edit own field_notes'] = array(
    'name' => 'edit own field_notes',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_reference_request_1'.
  $permissions['edit own field_reference_request_1'] = array(
    'name' => 'edit own field_reference_request_1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_reference_request_2'.
  $permissions['edit own field_reference_request_2'] = array(
    'name' => 'edit own field_reference_request_2',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_reference_request_church'.
  $permissions['edit own field_reference_request_church'] = array(
    'name' => 'edit own field_reference_request_church',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_reference_request_parents'.
  $permissions['edit own field_reference_request_parents'] = array(
    'name' => 'edit own field_reference_request_parents',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_reference_request_standby'.
  $permissions['edit own field_reference_request_standby'] = array(
    'name' => 'edit own field_reference_request_standby',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_ssn'.
  $permissions['edit own field_ssn'] = array(
    'name' => 'edit own field_ssn',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_texting'.
  $permissions['edit own field_texting'] = array(
    'name' => 'edit own field_texting',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_volunteer_interests_roles'.
  $permissions['edit own field_volunteer_interests_roles'] = array(
    'name' => 'edit own field_volunteer_interests_roles',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_what_site_you_want'.
  $permissions['edit own field_what_site_you_want'] = array(
    'name' => 'edit own field_what_site_you_want',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_app_status'.
  $permissions['view field_app_status'] = array(
    'name' => 'view field_app_status',
    'roles' => array(
      'Reviewer' => 'Reviewer',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_app_user'.
  $permissions['view field_app_user'] = array(
    'name' => 'view field_app_user',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_color_preference'.
  $permissions['view field_color_preference'] = array(
    'name' => 'view field_color_preference',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_completed'.
  $permissions['view field_completed'] = array(
    'name' => 'view field_completed',
    'roles' => array(
      'Reviewer' => 'Reviewer',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_edu_level'.
  $permissions['view field_edu_level'] = array(
    'name' => 'view field_edu_level',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_email'.
  $permissions['view field_email'] = array(
    'name' => 'view field_email',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_empl_length'.
  $permissions['view field_empl_length'] = array(
    'name' => 'view field_empl_length',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_empl_title'.
  $permissions['view field_empl_title'] = array(
    'name' => 'view field_empl_title',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_employer'.
  $permissions['view field_employer'] = array(
    'name' => 'view field_employer',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_expired_date'.
  $permissions['view field_expired_date'] = array(
    'name' => 'view field_expired_date',
    'roles' => array(
      'Reviewer' => 'Reviewer',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_faq_a'.
  $permissions['view field_faq_a'] = array(
    'name' => 'view field_faq_a',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_gender'.
  $permissions['view field_gender'] = array(
    'name' => 'view field_gender',
    'roles' => array(
      'Reviewer' => 'Reviewer',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_how_did_you_hear_about_nov'.
  $permissions['view field_how_did_you_hear_about_nov'] = array(
    'name' => 'view field_how_did_you_hear_about_nov',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_ministry_cert'.
  $permissions['view field_ministry_cert'] = array(
    'name' => 'view field_ministry_cert',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_ministry_experience'.
  $permissions['view field_ministry_experience'] = array(
    'name' => 'view field_ministry_experience',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_notes'.
  $permissions['view field_notes'] = array(
    'name' => 'view field_notes',
    'roles' => array(
      'Reviewer' => 'Reviewer',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_reference_request_1'.
  $permissions['view field_reference_request_1'] = array(
    'name' => 'view field_reference_request_1',
    'roles' => array(
      'Reviewer' => 'Reviewer',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_reference_request_2'.
  $permissions['view field_reference_request_2'] = array(
    'name' => 'view field_reference_request_2',
    'roles' => array(
      'Reviewer' => 'Reviewer',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_reference_request_church'.
  $permissions['view field_reference_request_church'] = array(
    'name' => 'view field_reference_request_church',
    'roles' => array(
      'Reviewer' => 'Reviewer',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_reference_request_parents'.
  $permissions['view field_reference_request_parents'] = array(
    'name' => 'view field_reference_request_parents',
    'roles' => array(
      'Reviewer' => 'Reviewer',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_reference_request_standby'.
  $permissions['view field_reference_request_standby'] = array(
    'name' => 'view field_reference_request_standby',
    'roles' => array(
      'Reviewer' => 'Reviewer',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_ssn'.
  $permissions['view field_ssn'] = array(
    'name' => 'view field_ssn',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_texting'.
  $permissions['view field_texting'] = array(
    'name' => 'view field_texting',
    'roles' => array(
      'Reviewer' => 'Reviewer',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_volunteer_interests_roles'.
  $permissions['view field_volunteer_interests_roles'] = array(
    'name' => 'view field_volunteer_interests_roles',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_what_site_you_want'.
  $permissions['view field_what_site_you_want'] = array(
    'name' => 'view field_what_site_you_want',
    'roles' => array(
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_app_status'.
  $permissions['view own field_app_status'] = array(
    'name' => 'view own field_app_status',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_app_user'.
  $permissions['view own field_app_user'] = array(
    'name' => 'view own field_app_user',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_color_preference'.
  $permissions['view own field_color_preference'] = array(
    'name' => 'view own field_color_preference',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_completed'.
  $permissions['view own field_completed'] = array(
    'name' => 'view own field_completed',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_edu_level'.
  $permissions['view own field_edu_level'] = array(
    'name' => 'view own field_edu_level',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_email'.
  $permissions['view own field_email'] = array(
    'name' => 'view own field_email',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_empl_length'.
  $permissions['view own field_empl_length'] = array(
    'name' => 'view own field_empl_length',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_empl_title'.
  $permissions['view own field_empl_title'] = array(
    'name' => 'view own field_empl_title',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_employer'.
  $permissions['view own field_employer'] = array(
    'name' => 'view own field_employer',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_expired_date'.
  $permissions['view own field_expired_date'] = array(
    'name' => 'view own field_expired_date',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_faq_a'.
  $permissions['view own field_faq_a'] = array(
    'name' => 'view own field_faq_a',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_gender'.
  $permissions['view own field_gender'] = array(
    'name' => 'view own field_gender',
    'roles' => array(
      'Reviewer' => 'Reviewer',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_how_did_you_hear_about_nov'.
  $permissions['view own field_how_did_you_hear_about_nov'] = array(
    'name' => 'view own field_how_did_you_hear_about_nov',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_ministry_cert'.
  $permissions['view own field_ministry_cert'] = array(
    'name' => 'view own field_ministry_cert',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_ministry_experience'.
  $permissions['view own field_ministry_experience'] = array(
    'name' => 'view own field_ministry_experience',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_notes'.
  $permissions['view own field_notes'] = array(
    'name' => 'view own field_notes',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_reference_request_1'.
  $permissions['view own field_reference_request_1'] = array(
    'name' => 'view own field_reference_request_1',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_reference_request_2'.
  $permissions['view own field_reference_request_2'] = array(
    'name' => 'view own field_reference_request_2',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_reference_request_church'.
  $permissions['view own field_reference_request_church'] = array(
    'name' => 'view own field_reference_request_church',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_reference_request_parents'.
  $permissions['view own field_reference_request_parents'] = array(
    'name' => 'view own field_reference_request_parents',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_reference_request_standby'.
  $permissions['view own field_reference_request_standby'] = array(
    'name' => 'view own field_reference_request_standby',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_ssn'.
  $permissions['view own field_ssn'] = array(
    'name' => 'view own field_ssn',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_texting'.
  $permissions['view own field_texting'] = array(
    'name' => 'view own field_texting',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_volunteer_interests_roles'.
  $permissions['view own field_volunteer_interests_roles'] = array(
    'name' => 'view own field_volunteer_interests_roles',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_what_site_you_want'.
  $permissions['view own field_what_site_you_want'] = array(
    'name' => 'view own field_what_site_you_want',
    'roles' => array(
      'Applicant US citizen' => 'Applicant US citizen',
      'Siteadmin' => 'Siteadmin',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
