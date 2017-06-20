<?php

/**
 * @file
 * Volunteer class to handle the novo migration.
 */
class VolunteerNovoMigration extends BaseNovoMigration {
  /**
   * General initialization of a Migration object.
   */
  public function __construct($args) {
    parent::__construct($args);

    $query = Database::getConnection('default', $this->databaseKey)
      ->select('users', 'u')
      ->fields('u', array(
        'id',
        'email',
        'password',
        'created_at',
        'first_name',
        'last_name',
        'birthday',
        'active'
      ))
      ->isNull('u.deleted_at');

    $query->addField("u", "id", "user_id");
    $query->leftJoin("role_user", "r_u", "r_u.user_id = u.id");
    $query->leftJoin("roles", "r", "r.id = r_u.role_id");
    // Only volunteers.
    $query->condition("r.name", "applicant");


    // Add source fields

    $query->innerJoin("user_applications", "ua", "ua.user_id = u.id");
    $query->innerJoin("user_steps", "us", "us.user_application_id = ua.id"); // step_id
    $query->innerJoin("answers", "a", "a.user_step_id = us.step_id"); // question_id

    $query->addField("a", "data", "answer");

    $query->innerJoin("questions", "q", "q.id = a.question_id"); // question_id
    $query->addField("q", "name", "q_name");
    $query->addField("q", "type", "q_type");
    $query->addField("q", "template_data", "q_template_data");


    $this->source = new MigrateSourceSQL($query, array(), NULL, array('map_joinable' => FALSE));
    $this->destination = new MigrateDestinationNode("application");

    // Key schema
    $source_key_schema = array(
      'user_id' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      )
    );
    $this->map = new MigrateSQLMap($this->machineName, $source_key_schema, MigrateDestinationNode::getKeySchema());

    // Mapping
//    $this->addFieldMapping('name', 'name')->dedupe('users', 'name');
//    $this->addFieldMapping('mail', 'email')->dedupe('users', 'mail');
//    $this->addFieldMapping('created', 'created_at');
//    $this->addFieldMapping('field_u_first_name', 'first_name')->defaultValue("User");
//    $this->addFieldMapping('field_u_last_name', 'last_name');
//    $this->addFieldMapping('field_u_birthday', 'birthday');
//    $this->addFieldMapping('status', 'active');
//    $this->addFieldMapping('pass', 'password')->callback(array($this, 'convertPassword'));

    $this->addUnmigratedDestinations(array(

    ));
  }
}
