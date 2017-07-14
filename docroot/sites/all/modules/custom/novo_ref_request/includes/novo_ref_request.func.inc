<?php

/**
 * @file
 * Novo ref request functions.
 */

/**
 * Attach ref node to parent node.
 */
function novo_ref_request_attach_ref(&$node, $field, $parent_term_name) {
  $ref_items = field_get_items("node", $node, $field);
  if (empty($ref_items)) {
    $ref_nid = novo_ref_request_create_ref_entity($parent_term_name, $node);
    if ($ref_nid) {
      $lang = (isset($node->language)) ? $node->language : LANGUAGE_NONE;
      $node->{$field}[$lang][0]['target_id'] = $ref_nid;
      return $ref_nid;
    }
  }
  return NULL;
}

/**
 * Crete reference node with questions.
 */
function novo_ref_request_create_ref_entity($q_type = NULL, $node = NULL) {
  global $user;
  if (!empty($q_type)) {
    // Prepare questions from taxonomy.
    $ref1_terms = taxonomy_get_term_by_name($q_type, NOVO_REF_QUESTIONS_VOC);
    $ref1_terms = reset($ref1_terms);
    $questions = array();
    if (isset($ref1_terms->tid)) {
      $term_childrens = taxonomy_get_children($ref1_terms->tid);
      if ($term_childrens) {
        foreach ($term_childrens as $child) {
          $questions[] = $child->name;
        }
      }
    }

    // Tokens.
    foreach ($questions as $key => $q) {
      $user_name = novo_ref_request_get_appl_user_name($node);
      $questions[$key] = str_replace("[ref_name]", $user_name, $q);
    }

    // Create ref node.
    $node = entity_create('node', array('type' => 'reference_request'));
    $node->uid = $user->uid;
    $entity = entity_metadata_wrapper('node', $node);
    $entity->save();
    $en = $entity->value();

    // Add questions to fc.
    foreach ($questions as $q) {
      $collection = entity_create('field_collection_item', array('field_name' => 'field_ref_faq'));
      $collection->setHostEntity('node', $en);

      $cwrapper = entity_metadata_wrapper('field_collection_item', $collection);
      $cwrapper->field_faq_q->set($q);
      $cwrapper->save();
    }
    return isset($en->nid) ? $en->nid : NULL;
  }
  return NULL;
}

/**
 * Add tasks.
 */
function novo_ref_request_add_tasks_callback($ref_nids) {

  foreach ($ref_nids as $nid) {
    if ($nid) {
      // Create tasks.
      $ref = novo_ref_request_get_ref_data_by_ref_nid($nid);
      if (isset($ref->ref_email)) {
        $title = "";

        switch ($ref->ref_type) {
          case "ref_1":
          case "ref_2":
            $title = t("Reference request");
            break;

          case "ref_church":
            $title = t("Church reference request");
            break;

          case "ref_parents":
            $title = t("Parent reference request");
            break;

          case "ref_standby":
            $title = t("Standby reference request");
            break;
        }

        $task_name = $title . " " . $ref->ref_username;
        novo_ref_request_task_add($ref->parent_uid, $nid, $ref->parent_nid, $ref->parent_name, $task_name, $ref->ref_email, $ref->ref_phone);
      }
    }
  }
}

/**
 * Get application user first/last names.
 */
function novo_ref_request_get_appl_user_name($node) {
  $last_name = field_get_items("node", $node, "field_last_name");
  $names = array($node->title);
  if (isset($last_name[0]['value'])) {
    $names[] = $last_name[0]['value'];
  }
  return implode(" ", $names);
}

/**
 * Get ref name by ref id.
 */
function novo_ref_get_ref_name($ref_nid) {
  $ref = novo_ref_request_get_ref_data_by_ref_nid($ref_nid);
  return (isset($ref->ref_username) && !empty($ref->ref_username)) ? "(" . $ref->ref_username . ")" : "";
}

/**
 * Get referal data (email, first/lst name) and parent nid/uid.
 */
function novo_ref_request_get_ref_data_by_ref_nid($ref_nid) {
  $query = db_select("node", "n");
  $query->fields("n", array("nid"));
  $query->addField("n", "nid", "parent_nid");
  $query->addField("n", "uid", "parent_uid");

  $query->leftJoin("field_data_field_last_name", "last_name", "n.nid = last_name.entity_id");
  $query->addExpression("CONCAT(n.title, ' ', last_name.field_last_name_value)", "parent_name");

  $query->leftJoin("field_data_field_reference_request_1", "ref_1", "n.nid = ref_1.entity_id");
  $query->leftJoin("field_data_field_reference_request_2", "ref_2", "n.nid = ref_2.entity_id");
  $query->leftJoin("field_data_field_reference_request_church", "ref_church", "n.nid = ref_church.entity_id");
  $query->leftJoin("field_data_field_reference_request_parents", "ref_parents", "n.nid = ref_parents.entity_id");
  $query->leftJoin("field_data_field_reference_request_standby", "ref_standby", "n.nid = ref_standby.entity_id");

  $or = db_or();
  $or->condition("ref_1.field_reference_request_1_target_id", $ref_nid);
  $or->condition("ref_2.field_reference_request_2_target_id", $ref_nid);
  $or->condition("ref_church.field_reference_request_church_target_id", $ref_nid);
  $or->condition("ref_parents.field_reference_request_parents_target_id", $ref_nid);
  $or->condition("ref_standby.field_reference_request_standby_target_id", $ref_nid);
  $query->condition($or);

  // Get type.
  $query->addExpression("CASE
    WHEN ref_1.field_reference_request_1_target_id = :id THEN 'ref_1'
    WHEN ref_2.field_reference_request_2_target_id = :id THEN 'ref_2'
    WHEN ref_standby.field_reference_request_standby_target_id = :id THEN 'ref_standby'
    WHEN ref_church.field_reference_request_church_target_id = :id THEN 'ref_church'
    WHEN ref_parents.field_reference_request_parents_target_id = :id THEN 'ref_parents'
    END", "ref_type", array(":id" => $ref_nid));

  // Get email.
  $ref_1_subselect = novo_ref_request_get_ref_subselect("field_data_field_ref_1_email", "field_ref_1_email_email");
  $ref_2_subselect = novo_ref_request_get_ref_subselect("field_data_field_ref_2_email", "field_ref_2_email_email");
  $ref_standby_subselect = novo_ref_request_get_ref_subselect("field_data_field_ref_3_email", "field_ref_3_email_email");
  $ref_church_subselect = novo_ref_request_get_ref_subselect("field_data_field_church_email", "field_church_email_email");
  $ref_parents_subselect = novo_ref_request_get_ref_subselect("field_data_field_parent_email", "field_parent_email_email");
  $query->addExpression("CASE
    WHEN ref_1.field_reference_request_1_target_id = :id THEN (" . $ref_1_subselect . ")
    WHEN ref_2.field_reference_request_2_target_id = :id THEN (" . $ref_2_subselect . ")
    WHEN ref_standby.field_reference_request_standby_target_id = :id THEN (" . $ref_standby_subselect . ")
    WHEN ref_church.field_reference_request_church_target_id = :id THEN (" . $ref_church_subselect . ")
    WHEN ref_parents.field_reference_request_parents_target_id = :id THEN (" . $ref_parents_subselect . ")
    END", "ref_email", array(":id" => $ref_nid));

  // Get phone.
  $ref_1_subselect = novo_ref_request_get_ref_subselect_fc("field_data_field_ref_1_phone", "field_ref_1_phone_value", "field_data_field_phone_number", "field_phone_number_value");
  $ref_2_subselect = novo_ref_request_get_ref_subselect_fc("field_data_field_ref_2_phone", "field_ref_2_phone_value", "field_data_field_phone_number", "field_phone_number_value");
  $ref_standby_subselect = novo_ref_request_get_ref_subselect_fc("field_data_field_ref_3_phone", "field_ref_3_phone_value", "field_data_field_phone_number", "field_phone_number_value");
  $ref_church_subselect = novo_ref_request_get_ref_subselect_fc("field_data_field_church_phone", "field_church_phone_value", "field_data_field_phone_number", "field_phone_number_value");
  $ref_parents_subselect = novo_ref_request_get_ref_subselect_fc("field_data_field_parent_phone", "field_parent_phone_value", "field_data_field_phone_number", "field_phone_number_value");
  $query->addExpression("CASE
    WHEN ref_1.field_reference_request_1_target_id = :id THEN (" . $ref_1_subselect . ")
    WHEN ref_2.field_reference_request_2_target_id = :id THEN (" . $ref_2_subselect . ")
    WHEN ref_standby.field_reference_request_standby_target_id = :id THEN (" . $ref_standby_subselect . ")
    WHEN ref_church.field_reference_request_church_target_id = :id THEN (" . $ref_church_subselect . ")
    WHEN ref_parents.field_reference_request_parents_target_id = :id THEN (" . $ref_parents_subselect . ")
    END", "ref_phone", array(":id" => $ref_nid));

  // Get name.
  $ref_1_subselect = novo_ref_request_get_ref_subselect("field_data_field_ref_1_first_name", "field_ref_1_first_name_value", "field_data_field_ref_1_last_name", "field_ref_1_last_name_value");
  $ref_2_subselect = novo_ref_request_get_ref_subselect("field_data_field_ref_2_first_name", "field_ref_2_first_name_value", "field_data_field_ref_2_last_name", "field_ref_2_last_name_value");
  $ref_standby_subselect = novo_ref_request_get_ref_subselect("field_data_field_ref_3_first_name", "field_ref_3_first_name_value", "field_data_field_ref_3_last_name", "field_ref_3_last_name_value");
  $ref_church_subselect = novo_ref_request_get_ref_subselect("field_data_field_church_home", "field_church_home_value");
  $ref_parents_subselect = novo_ref_request_get_ref_subselect("field_data_field_parent_guardian_first_name", "field_parent_guardian_first_name_value", "field_data_field_parent_guardian_last_name", "field_parent_guardian_last_name_value");
  $query->addExpression("CASE
    WHEN ref_1.field_reference_request_1_target_id = :id THEN (" . $ref_1_subselect . ")
    WHEN ref_2.field_reference_request_2_target_id = :id THEN (" . $ref_2_subselect . ")
    WHEN ref_standby.field_reference_request_standby_target_id = :id THEN (" . $ref_standby_subselect . ")
    WHEN ref_church.field_reference_request_church_target_id = :id THEN (" . $ref_church_subselect . ")
    WHEN ref_parents.field_reference_request_parents_target_id = :id THEN (" . $ref_parents_subselect . ")
    END", "ref_username", array(":id" => $ref_nid));

  $query->range(0, 1);

  $result = $query->execute()->fetchAll();
  $result = reset($result);
  return $result;
}

/**
 * Build ref subselect.
 */
function novo_ref_request_get_ref_subselect($table_1, $field_1, $table_2 = NULL, $field_2 = NULL) {
  if (!empty($table_2) && !empty($field_2)) {
    return "SELECT GROUP_CONCAT(concat(" . $table_1 . "." . $field_1 . ", ' ', " . $table_2 . "." . $field_2 . ") SEPARATOR ', ')
          FROM " . $table_1 . " 
          LEFT JOIN " . $table_2 . " on " . $table_1 . ".entity_id = " . $table_2 . ".entity_id
          WHERE " . $table_1 . ".entity_id = n.nid";
  }
  else {
    return "SELECT GROUP_CONCAT(" . $table_1 . "." . $field_1 . " SEPARATOR ', ') FROM " . $table_1 . " WHERE " . $table_1 . ".entity_id = n.nid";
  }
}

/**
 * Build ref subselect for field collection.
 */
function novo_ref_request_get_ref_subselect_fc($table_1, $field_1, $fc_table, $fc_field) {
  return "SELECT GROUP_CONCAT(" . $fc_table . "." . $fc_field . " SEPARATOR ', ') FROM " . $table_1 . " 
  INNER JOIN field_data_field_phone_number ON field_data_field_phone_number.entity_id = " . $table_1 . "." . $field_1 . "
  WHERE " . $table_1 . ".entity_id = n.nid";
}