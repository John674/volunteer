<?php

/**
 * @file
 * Volunteer class to handle the novo migration.
 */

/**
 * Class VolunteerNovoMigration.
 */
class VolunteerNovoMigration extends BaseNovoMigration {

  /**
   * VolunteerNovoMigration constructor.
   */
  public function __construct($args) {
    parent::__construct($args);

    $items = $this->getList();
    // kpr($items);
    $this->source = new MigrateSourceApplication($items);
    $this->destination = new MigrateDestinationNode("application");

    // Key schema.
    $source_key_schema = array(
      'id' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      )
    );
    $this->map = new MigrateSQLMap($this->machineName, $source_key_schema, MigrateDestinationNode::getKeySchema());

    $this->mapping();

    $this->addUnmigratedDestinations(array(
      'revision',
      'log',
      'language',
      'tnid',
      'translate',
      'revision_uid',
      'is_new',
      'field_state:create_term',
      'field_state:ignore_case',
      'field_dob:timezone',
      'field_dob:rrule',
      'field_dob:to',
      'field_t_shirt_size:create_term',
      'field_t_shirt_size:ignore_case',
      'field_color_preference:create_term',
      'field_color_preference:ignore_case',
      'field_what_site_want:create_term',
      'field_what_site_want:ignore_case',
      'field_prefix:create_term',
      'field_prefix:ignore_case',
      'field_ref_1_prefix:create_term',
      'field_ref_1_prefix:ignore_case',
      'field_ref_2_prefix:create_term',
      'field_ref_2_prefix:ignore_case',
      'field_ref_3_prefix:create_term',
      'field_ref_3_prefix:ignore_case',
      'field_texting',
      'field_notes',
      'field_phone',
      'field_phone:revision_id',
      'field_ref_1_phone',
      'field_ref_1_phone:revision_id',
      'field_ref_2_phone',
      'field_ref_2_phone:revision_id',
      'field_ref_3_phone',
      'field_ref_3_phone:revision_id',
      'field_church_phone',
      'field_church_phone:revision_id',
      'field_expired_date:timezone',
      'field_expired_date:rrule',
      'field_expired_date:to',
      'field_app_status:create_term',
      'field_app_status:ignore_case'
    ));

    $this->addUnmigratedSources(array(
      'assistant_liaison',
      'buddy',
      'canvasser',
      'registration_leader_or_helper',
      'large_group_leader',
      'prayer_team',
      'program_substitute',
      'small_group_helper',
      'small_group_leader',
      'snack_leader',
      'reference_1_phone_1',
      'reference_1_phone_2',
      'reference_2_phone_1',
      'reference_2_phone_2',
      'standby_phone_1',
      'standby_phone_2',
      'personal_information_phone_1',
      'personal_information_phone_2',
      'church_background_phone_1',
      'church_background_phone_2'
    ));
  }

  /**
   * Implements prepareRow.
   */
  public function prepareRow($row) {
    $row->prepare_interests_roles = $this->prepareInterestsRoles($row);
    return parent::prepareRow($row);
  }

  /**
   * Implements complete.
   */
  public function complete($entity, $row) {
    $node = node_load($entity->nid);
    // Attach phones.
    $this->attachPhone($node, $row, "personal_information_", "field_phone");
    $this->attachPhone($node, $row, "reference_1_", "field_ref_1_phone");
    $this->attachPhone($node, $row, "reference_2_", "field_ref_2_phone");
    $this->attachPhone($node, $row, "standby_", "field_ref_3_phone");
    $this->attachPhone($node, $row, "church_background_", "field_church_phone");
    $this->attachPhone($node, $row, "parent_", "field_parent_phone");

    // Multistep.
    if (function_exists("_multistep_update_status")) {
      _multistep_update_status($node, "node", "submitted", "all");
    }
  }

  /**
   * Attach field_collection phone filed.
   */
  private function attachPhone($node, $row, $field, $ref_field) {
    $phone_arr = array();
    $additional_fields = array("phone_1", "phone_2");

    foreach ($additional_fields as $add_field) {
      $phone_field = $field . $add_field;
      if (isset($row->{$phone_field}) && !empty($row->{$phone_field})) {
        $number = $this->formatPhoneNumber($row->{$phone_field});
        if (!empty($number)) {
          $phone_arr[] = $number;
        }
        else {
          watchdog("novo_migrate", 'Can\' convert phone :phone for nid :nid for field :field', array(
            ":phone" => $row->{$phone_field},
            ":nid" => $node->nid,
            ":field" => $ref_field
          ));
        }
      }
    }

    if (!empty($phone_arr)) {
      $phone_type_tid = $this->getTermTid("Mobile", "phone_type");
      foreach ($phone_arr as $phone) {
        $values = array(
          'field_name' => $ref_field,
          'field_phone_number' => array(LANGUAGE_NONE => array(array('value' => $phone))),
          'field_phone_type' => array(LANGUAGE_NONE => array(array('tid' => $phone_type_tid))),
        );
        $item = entity_create('field_collection_item', $values);
        $item->setHostEntity('node', $node);
        $item->save();
      }
    }
  }

  /**
   * Convert phone number. @TODO: need test and change. To Vasya - finish it.
   */
  protected function formatPhoneNumber($s) {
    if (strlen(preg_replace("/\D*/", "", $s)) < 10) {
      return FALSE;
    }
    // @codingStandardsIgnoreStart
    $rx = "/
    (1)?\D*     # optional country code
    (\d{3})?\D* # optional area code
    (\d{3})\D*  # first three
    (\d{4})     # last four
    (?:\D+|$)   # extension delimiter or EOL
    (\d*)       # optional extension
/x";
    preg_match($rx, $s, $matches);
    if (!isset($matches[0]) || !isset($matches[2])) {
      return FALSE;
    }

    $country = $matches[1];
    $area = ($matches[2]) ? $matches[2] : "000";
    $three = $matches[3];
    $four = $matches[4];
    $ext = $matches[5];

    $out = "$three-$four";
    if (!empty($area)) {
      $out = "$area-$out";
    }
//    if (!empty($country)) {
//      $out = "+$country-$out";
//    }
//    if (!empty($ext)) {
//      $out .= "x$ext";
//    }

    // check that no digits were truncated
    // if (preg_replace('/\D/', '', $s) != preg_replace('/\D/', '', $out)) return false;
    // @codingStandardsIgnoreEnd
    return $out;
  }

  /**
   * Prepare Interests Roles taxonomy reference.
   */
  protected function prepareInterestsRoles($row) {
    $prepare_interests_roles = array();

    if (isset($row->assistant_liaison) && $row->assistant_liaison) {
      $prepare_interests_roles[] = $this->getTermTid("Assistant Liaison", "volunteer_interests_roles");
    }

    if (isset($row->buddy) && $row->buddy) {
      $prepare_interests_roles[] = $this->getTermTid("Buddy", "volunteer_interests_roles");
    }

    if (isset($row->canvasser) && $row->canvasser) {
      $prepare_interests_roles[] = $this->getTermTid("Canvasser", "volunteer_interests_roles");
    }

    if (isset($row->registration_leader_or_helper) && $row->registration_leader_or_helper) {
      $prepare_interests_roles[] = $this->getTermTid("Greeter / Registration Leader or Helper", "volunteer_interests_roles");
    }

    if (isset($row->large_group_leader) && $row->large_group_leader) {
      $prepare_interests_roles[] = $this->getTermTid("Large Group Leader", "volunteer_interests_roles");
    }

    if (isset($row->prayer_team) && $row->prayer_team) {
      $prepare_interests_roles[] = $this->getTermTid("Prayer Team", "volunteer_interests_roles");
    }

    if (isset($row->program_substitute) && $row->program_substitute) {
      $prepare_interests_roles[] = $this->getTermTid("Program Substitute", "volunteer_interests_roles");
    }

    if (isset($row->small_group_helper) && $row->small_group_helper) {
      $prepare_interests_roles[] = $this->getTermTid("Small Group Helper", "volunteer_interests_roles");
    }

    if (isset($row->small_group_leader) && $row->small_group_leader) {
      $prepare_interests_roles[] = $this->getTermTid("Small Group Leader", "volunteer_interests_roles");
    }

    if (isset($row->snack_leader) && $row->snack_leader) {
      $prepare_interests_roles[] = $this->getTermTid("Snack Leader / Helper", "volunteer_interests_roles");
    }

    return $prepare_interests_roles;
  }

  /**
   * Prepare list of data.
   */
  protected function getList() {
    $query = Database::getConnection('default', $this->databaseKey)
      ->select('users', 'u')
      ->fields('u', array('id'))
      ->isNull('u.deleted_at');
    $query->addField("u", "id", "user_id");
    $query->leftJoin("role_user", "r_u", "r_u.user_id = u.id");
    $query->leftJoin("roles", "r", "r.id = r_u.role_id");
    // Only volunteers.
    $query->condition("r.name", "applicant");

    // Add source fields.
    $query->innerJoin("user_applications", "ua", "ua.user_id = u.id");
    $query->addField("ua", "created_at", "created_at");
    $query->addField("ua", "updated_at", "updated_at");
    $query->addField("ua", "approved", "application_approved");
    $query->addField("ua", "status", "application_status");
    $query->isNull('ua.deleted_at');

    $query->innerJoin("user_steps", "us", "us.user_application_id = ua.id");
    $query->innerJoin("answers", "a", "a.user_step_id = us.id");
    $query->addField("us", "status", "step_status");
    $query->addField("a", "data", "answer");

    $query->innerJoin("questions", "q", "q.id = a.question_id");
    $query->addField("q", "name", "q_name");
    $query->addField("q", "type", "q_type");

    $query->innerJoin("sections", "sec", "sec.id = q.section_id");
    $query->addField("sec", "name", "section_name");

    $query->leftJoin("answer_variants", "av", "av.question_id = q.id");
    $query->addField("av", "template_data", "answer_variant");
    $query->addField("av", "id", "answer_variant_id");

    //$query->condition("u.id", 423);

    $result = $query->execute()->fetchAll();

    $users = array();
    foreach ($result as $key => $value) {
      if (isset($users[$value->id][$value->q_name][$value->section_name])) {
        $users[$value->id][$value->q_name][$value->section_name]['variants'][$value->answer_variant_id] = $value->answer_variant;
        if (($users[$value->id][$value->q_name][$value->section_name]['base_fields']['step_status'] == "completed") && $value->step_status != "completed") {
          $users[$value->id][$value->q_name][$value->section_name]['base_fields']['step_status'] = $value->step_status;
        }
      }
      else {
        $users[$value->id][$value->q_name][$value->section_name] = array(
          'base_fields' => array(
            'created_at' => $value->created_at,
            'updated_at' => $value->updated_at,
            'application_approved' => $value->application_approved,
            'application_status' => $value->application_status,
            'step_status' => $value->step_status,
          ),
          'answer' => $value->answer,
          'query' => $value->q_name,
          'q_type' => $value->q_type,
          'section_name' => $value->section_name,
          'variants' => array(
            $value->answer_variant_id => $value->answer_variant
          )
        );
      }
    }

    foreach ($users as $uid => $fields) {
      $users[$uid]["id"] = $uid;
      foreach ($fields as $key => $field_group) {
        foreach ($field_group as $section_name => $field) {
          $val = $this->getAnswer($field['answer'], $field['q_type'], $field['variants']);
          if (count($field_group) < 2) {
            $users[$uid][$key] = $val['value'];
            // Add base fields.
            if (isset($field['base_fields']) && !empty($field['base_fields'])) {
              foreach ($field['base_fields'] as $b_field => $b_value) {
                if (!isset($users[$uid][$b_field])) {
                  $users[$uid][$b_field] = $b_value;
                }
              }
            }
          }
          else {
            unset($users[$uid][$key]);
            $users[$uid][$section_name . "_" . $key] = $val['value'];
            // Add base fields.
            if (isset($field['base_fields']) && !empty($field['base_fields'])) {
              foreach ($field['base_fields'] as $b_field => $b_value) {
                if (!isset($users[$uid][$b_field])) {
                  $users[$uid][$b_field] = $b_value;
                }
              }
            }
          }
        }
      }
    }

    return array_values($users);
  }

  /**
   * Prepare one answer row.
   */
  protected function getAnswer($answer, $q_type, $variants) {
    $answer_data = array("value" => NULL);
    $answer_obj = $this->getAnswerJson($answer);

    switch ($q_type) {
      case "radio":
      case "period":
        if (isset($answer_obj->radio) && isset($variants[$answer_obj->radio])) {
          $variant_obj = $this->getAnswerJson($variants[$answer_obj->radio]);
          if ($variant_obj && isset($variant_obj->title)) {
            if (isset($answer_obj->length)) {
              $answer_data["value"]['period'] = $variant_obj->title;
              $answer_data["value"]['length'] = $answer_obj->length;
            }
            else {
              $answer_data["value"] = $variant_obj->title;
            }
          }
        }
        break;

      case "textarea":
      case "input":
      case "date":
        $answer_data["value"] = isset($answer_obj->value) ? $answer_obj->value : NULL;
        break;

      case "checkbox":
        $answer_data["value"] = isset($answer_obj->checked) ? ($answer_obj->checked) : FALSE;
        break;

      case "radio_with_explanation":
        if (isset($answer_obj->radio) && isset($variants[$answer_obj->radio])) {
          if (isset($answer_obj->explanation) && !empty($answer_obj->explanation)) {
            $answer_data["value"] = $answer_obj->explanation;
          }
          else {
            $variant_obj = $this->getAnswerJson($variants[$answer_obj->radio]);
            if ($variant_obj && isset($variant_obj->title)) {
              $answer_data["value"] = $variant_obj->title;
            }
          }
        }
        break;

      default:
        $answer_data["value"] = isset($answer_obj) ? $answer_obj : NULL;
    }

    return $answer_data;
  }

  /**
   * Parse JSON string.
   */
  protected function getAnswerJson($json) {
    try {
      return json_decode($json);
    }
    catch (Exception $ex) {
      return NULL;
    }
  }

  /**
   * Main field mapping.
   */
  protected function mapping() {
    // Mapping.
    $this->addFieldMapping('comment')->defaultValue(FALSE);
    $this->addFieldMapping('status', "step_status")->callback(array($this, "isPublished"));

    $this->addFieldMapping('title', 'legal_first_name');
    $this->addFieldMapping('field_prefix', 'prefix')
      ->callback(array($this, "getPrefix"));
    $this->addFieldMapping('field_prefix:source_type')
      ->defaultValue('tid');

    $this->addFieldMapping('uid', 'id')
      ->sourceMigration('Users');

    $this->addFieldMapping('promote')->defaultValue(FALSE);
    $this->addFieldMapping('sticky')->defaultValue(FALSE);

    $this->addFieldMapping('created', 'created_at');
    $this->addFieldMapping('changed', 'updated_at');

    $this->addFieldMapping('field_goes_by', 'go_by');
    $this->addFieldMapping('field_middle', 'middle_initial');
    $this->addFieldMapping('field_last_name', 'last_name');
    $this->addFieldMapping('field_maiden_name_or_alias_names', 'alias');
    $this->addFieldMapping('field_address_1', 'address_1');
    $this->addFieldMapping('field_address_2', 'address_2');
    $this->addFieldMapping('field_city', 'city');
    $this->addFieldMapping('field_state', 'state')->callback(array(
      $this,
      "getState"
    ));
    $this->addFieldMapping('field_state:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_zip', 'zip')
      ->callback(array($this, "formattingZip"));
    $this->addFieldMapping('field_dob', 'date_of_birth')
      ->callback(array($this, "checkDob"));
    $this->addFieldMapping('field_email', 'email');
    $this->addFieldMapping('field_t_shirt_size', 't_shirt_size')
      ->callback(array(
        $this,
        "getTshirtSize"
      ));
    $this->addFieldMapping('field_t_shirt_size:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_color_preference', 'color_preference')
      ->callback(array(
        $this,
        "getColorPref"
      ));
    $this->addFieldMapping('field_color_preference:source_type')
      ->defaultValue('tid');

    $this->addFieldMapping('field_emergency_name', 'emergency_contact_name');
    $this->addFieldMapping('field_masked_emergency_phone', 'emergency_contact_phone')
      ->callback(array($this, "getEmergencyPhone"));
    $this->addFieldMapping('field_how_did_you_hear_about_nov', 'how_did_you_hear_about_novo');
    $this->addFieldMapping('field_relationship', 'emergency_contact_relationship');

    $this->addFieldMapping('field_employer', 'employer');
    $this->addFieldMapping('field_empl_title', 'title');
    $this->addFieldMapping('field_empl_length', 'length_of_current_employment');
    $this->addFieldMapping('field_edu_level', 'education');

    $this->addFieldMapping('field_ministry_experience', 'volunteer_experience');
    $this->addFieldMapping('field_ministry_cert', 'certification');

    // Many fields. Prepare them.
    $this->addFieldMapping('field_volunteer_interests_roles', 'prepare_interests_roles');

    $this->addFieldMapping('field_ref_1_prefix', 'reference_1_title')
      ->callback(array($this, "getPrefix"));
    $this->addFieldMapping('field_ref_1_prefix:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_ref_1_first_name', 'reference_1_first_name');
    $this->addFieldMapping('field_ref_1_last_name', 'reference_1_last_name');
    $this->addFieldMapping('field_ref_1_email', 'reference_1_email');
    $this->addFieldMapping('field_ref_1_how_know', 'reference_1_how_know');
    $this->addFieldMapping('field_ref_1_how_long', 'reference_1_how_long')
      ->callback(array($this, "getHowLong"));
    $this->addFieldMapping('field_ref_1_how_long_period', 'reference_1_how_long')
      ->callback(array($this, "getHowLongPeriod"));

    $this->addFieldMapping('field_ref_2_prefix', 'reference_2_title')
      ->callback(array($this, "getPrefix"));
    $this->addFieldMapping('field_ref_2_prefix:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_ref_2_first_name', 'reference_2_first_name');
    $this->addFieldMapping('field_ref_2_last_name', 'reference_2_last_name');
    $this->addFieldMapping('field_ref_2_email', 'reference_2_email');
    $this->addFieldMapping('field_ref_2_how_know', 'reference_2_how_know');
    $this->addFieldMapping('field_ref_2_how_long', 'reference_2_how_long')
      ->callback(array($this, "getHowLong"));
    $this->addFieldMapping('field_ref_2_how_long_period', 'reference_2_how_long')
      ->callback(array($this, "getHowLongPeriod"));

    $this->addFieldMapping('field_ref_3_prefix', 'standby_title')
      ->callback(array($this, "getPrefix"));
    $this->addFieldMapping('field_ref_3_prefix:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_ref_3_first_name', 'standby_first_name');
    $this->addFieldMapping('field_ref_3_last_name', 'standby_last_name');
    $this->addFieldMapping('field_ref_3_email', 'standby_email');
    $this->addFieldMapping('field_ref_3_how_know', 'standby_how_know');
    $this->addFieldMapping('field_ref_3_how_long', 'standby_how_long')
      ->callback(array($this, "getHowLong"));
    $this->addFieldMapping('field_ref_3_how_long_period', 'standby_how_long')
      ->callback(array($this, "getHowLongPeriod"));

    $this->addFieldMapping('field_pertinent_q1', 'mental_conditions');
    $this->addFieldMapping('field_pertinent_q2', 'medications');
    $this->addFieldMapping('field_pertinent_q3', 'allergies');
    $this->addFieldMapping('field_pertinent_q4', 'convicted');
    $this->addFieldMapping('field_pertinent_q5', 'accused');
    $this->addFieldMapping('field_pertinent_q6', 'drugs');
    $this->addFieldMapping('field_pertinent_q7', 'treatment');
    $this->addFieldMapping('field_pertinent_q8', 'victim');
    $this->addFieldMapping('field_pertinent_q9', 'painful_experience');
    $this->addFieldMapping('field_pertinent_q10', 'asked_to_live_church');
    $this->addFieldMapping('field_pertinent_q11', 'asked_to_step_away');
    $this->addFieldMapping('field_pertinent_q12', 'reason_not_to_work');
    $this->addFieldMapping('field_pertinent_q13', 'problem_in_the_past');

    $this->addFieldMapping('field_church_home', 'home_church');
    $this->addFieldMapping('field_church_how_long_attended', 'how_long_attended');
    $this->addFieldMapping('field_church_prev', 'church_involvement');
    $this->addFieldMapping('field_church_reference', 'church_reference');
    $this->addFieldMapping('field_church_email', 'church_email');

    $this->addFieldMapping('field_beliefs_q1', 'saved_by_god')
      ->callback(array($this, "yesToBool"));
    $this->addFieldMapping('field_beliefs_q2', 'virgin_birth')
      ->callback(array($this, "yesToBool"));
    $this->addFieldMapping('field_beliefs_q3', 'belive_in_trinity')
      ->callback(array($this, "yesToBool"));
    $this->addFieldMapping('field_beliefs_q4', 'jesus_is_god_son')
      ->callback(array($this, "yesToBool"));
    $this->addFieldMapping('field_beliefs_q5', 'jesus_rose_from_dead')
      ->callback(array($this, "yesToBool"));
    $this->addFieldMapping('field_beliefs_q6', 'eternal_life')
      ->callback(array($this, "yesToBool"));
    $this->addFieldMapping('field_beliefs_q7', 'authority_of_the_bible')
      ->callback(array($this, "yesToBool"));

    $this->addFieldMapping('field_beliefs2_q1', 'how_realised_needed_jesus');
    $this->addFieldMapping('field_beliefs2_q2', 'why_jesus_savior');
    $this->addFieldMapping('field_beliefs2_q3', 'difference_of_decision');

    $this->addFieldMapping('field_things_q1', 'inner_city_children_mentored')
      ->callback(array($this, "yesToBool"));
    $this->addFieldMapping('field_things_q2', 'point_children')
      ->callback(array($this, "yesToBool"));
    $this->addFieldMapping('field_things_q3', 'novo_curriculum')
      ->callback(array($this, "yesToBool"));
    $this->addFieldMapping('field_things_q4', 'not_only_life_changing')
      ->callback(array($this, "yesToBool"));
    $this->addFieldMapping('field_things_q5', 'opportunities')
      ->callback(array($this, "yesToBool"));
    $this->addFieldMapping('field_things_q6', 'willing_to_pursue')
      ->callback(array($this, "yesToBool"));

    $this->addFieldMapping('field_app7_statement_agree', 'statement_of_faith_agreement');
    $this->addFieldMapping('field_program_policies_agree', 'pertinent_novo_program_policies');

    $this->addFieldMapping('field_app_7_final_agree_1', 'legally_binding_agreement');
    $this->addFieldMapping('field_app_7_final_agree_2', 'answers_true');
    $this->addFieldMapping('field_app_7_final_agree_3', 'rights_to_use');
    $this->addFieldMapping('field_app_7_final_agree_4', 'disclosure');
    $this->addFieldMapping('field_app_7_final_agree_5', 'contact_any_person');
    $this->addFieldMapping('field_app_7_final_agree_6', 'background_inquiry');

    // @todo: To Vasya - finish it.
    // $this->addFieldMapping('field_what_site_want', '');
    // $this->addFieldMapping('field_what_site_want:source_type')->defaultValue('target_id');
    // $this->addFieldMapping('field_expired_date', '');

    $this->addFieldMapping('field_ssn', 'social_security_number')
      ->callback(array($this, "formattingSsn"));
    $this->addFieldMapping('field_parent_prefix', 'parent_title');
    $this->addFieldMapping('field_parent_guardian_first_name', 'parent_first_name');
    $this->addFieldMapping('field_parent_guardian_last_name', 'parent_last_name');
    $this->addFieldMapping('field_parent_email', 'parent_email');

    $this->addFieldMapping('field_app_status', 'application_approved')->callback(array($this, "getApplicationStatus"));
    $this->addFieldMapping('field_app_status:source_type')->defaultValue('tid');
  }

  /**
   * Get term tid by name.
   */
  protected function getTermTid($value, $voc_name) {
    if (!empty($value)) {
      $tid = $this->getTidByName($value, $voc_name);
      if (!empty($tid)) {
        return $tid;
      }
      else {
        Migration::displayMessage(t('Not found tid :tid for value :value', array(
          ":tid" => $tid,
          ":value" => $value
        )));
        return NULL;
      }
    }
    else {
      return NULL;
    }
  }

  /**
   * Convert Yes/No to bool.
   */
  protected function yesToBool($value) {
    return (!empty($value) && $value == "Yes") ? 1 : 0;
  }

  /**
   * Prefix callback function.
   */
  protected function getPrefix($value) {
    return $this->getTermTid($value, "prefix");
  }

  /**
   * How long callback function.
   */
  protected function getHowLong($value) {
    return !empty($value['length']) ? intval($value['length']) : 0;
  }

  /**
   * How long period callback function.
   */
  protected function getHowLongPeriod($value) {
    if (!empty($value['period'])) {
      if ($value['period'] == 'months' || $value['period'] == 'years') {
        return $value['period'];
      }
      else {
        $current_key = $this->source->getCurrentKey();
        $source_user_id = $current_key['id'];
        watchdog("novo_migrate", 'Value :not_valid_value  should be equal months or years in user with source_user_id = :source_user_id', array(
          ":source_user_id" => $source_user_id,
          ":not_valid_value" => $value['period']
        ));
      }
    }
    return NULL;
  }

  /**
   * State callback function.
   */
  protected function getState($value) {
    if (!empty($value)) {
      $tid = $this->getTidByName($value, "states");
      if (!empty($tid)) {
        return $tid;
      }
      else {
        // Load by term description.
        $voc = taxonomy_vocabulary_machine_name_load("states");
        $tree = taxonomy_get_tree($voc->vid);
        foreach ($tree as $term) {
          if (strtolower(trim($term->description)) === strtolower(trim($value))) {
            return $term->tid;
          }
        }

        preg_match("/ok[l]?a/i", $value, $is_oklahoma);
        if (!empty($is_oklahoma[0])) {
          $tid = $this->getTidByName("Oklahoma", "states");
          if (!empty($tid)) {
            return $tid;
          }
        }

        watchdog("novo_migrate", 'Not found tid :tid for value :value', array(
          ":tid" => $tid,
          ":value" => $value
        ));
        return NULL;
      }
    }
    else {
      return NULL;
    }
  }

  /**
   * T-Shirt Size callback function.
   */
  protected function getTshirtSize($value) {
    return $this->getTermTid($value, "t_shirt_size");
  }

  /**
   * Color Preference callback function.
   */
  protected function getColorPref($value) {
    return $this->getTermTid($value, "color_preference");
  }

  /**
   * Convert emergency phone.
   */
  protected function getEmergencyPhone($value) {
    if (!empty($value)) {
      $number = $this->formatPhoneNumber($value);
      if (!empty($number)) {
        return $number;
      }
      else {
        watchdog("novo_migrate", 'Can\' convert phone :phone for field :field', array(
          ":phone" => $value,
          ":field" => "field_masked_emergency_phone"
        ));
      }
    }

    return $value;
  }

  /**
   * Get Taxonomy tid by name.
   */
  protected function getTidByName($term_name, $voc_name) {
    $term = taxonomy_get_term_by_name($term_name, $voc_name);
    $term = array_values($term);
    $term = isset($term[0]) ? $term[0] : -1;
    return (isset($term->tid)) ? $term->tid : NULL;
  }

  /**
   * Cut first five symbols form zip.
   */
  protected function formattingZip($value) {
    if (empty($value)) {
      return NULL;
    }
    $value = (string) $value;
    $value = intval(substr($value, 0, 5));
    return $value;
  }

  /**
   * Delete "-" from ssn.
   */
  protected function formattingSsn($value) {
    if (empty($value)) {
      return NULL;
    }
    $value = (string) $value;
    $value = intval(str_replace("-", "", $value));
    return $value;
  }

  /**
   * Check date of birthday.
   */
  protected function checkDob($value) {
    if (!empty($value)) {
      return NULL;
    }
    $value = trim($value);
    $dob = \DateTime::createFromFormat("m/d/Y", $value);
    $year = $dob->format("Y");

    if ($year[0] == 0) {
      $new_year = preg_replace("/^.{1}/", "1", $year);
      $new_dob = $dob->format("m") . "/" . $dob->format("d") . "/" . $new_year;
      watchdog("novo_migrate", 'Value field_value was changing from :value to :new_value', array(
        ":value" => $value,
        ":new_value" => $new_dob,
      ));
      return $new_dob;
    }
    else {
      return $value;
    }
  }

  /**
   * Check publish or not publish application.
   */
  protected function isPublished($value) {
    return !empty($value) && ($value == "completed") ? TRUE : FALSE;
  }

  /**
   * Approved or Not Approved application.
   */
  protected function getApplicationStatus($value) {
    if (is_null($value)) {
      return NULL;
    }
    $value = intval($value);
    if ($value) {
      return $this->getTermTid("Approved", "application_status");
    }
    else {
      return $this->getTermTid("Not Approved", "application_status");
    }
  }

}
