<?php

/**
 * @file
 * Volunteer class to handle the novo migration.
 */

/**
 * Class UserNovoMigration.
 */
class UserNovoMigration extends BaseNovoMigration {

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
    $query->addField("r", "name", "role");

    // Only volunteers.
    /*$query->condition("r.name", "applicant");*/
    $this->source = new MigrateSourceSQL($query, array(), NULL, array('map_joinable' => FALSE));
    $this->destination = new MigrateDestinationUser(array('md5_passwords' => TRUE));

    // Key schema.
    $source_key_schema = array(
      'user_id' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ),
    );
    $this->map = new MigrateSQLMap($this->machineName, $source_key_schema, MigrateDestinationUser::getKeySchema());

    // Mapping.
    $this->addFieldMapping('name', 'name')->dedupe('users', 'name');
    $this->addFieldMapping('mail', 'email')->dedupe('users', 'mail');
    $this->addFieldMapping('created', 'created_at');
    $this->addFieldMapping('field_u_first_name', 'first_name')
      ->defaultValue("User");
    $this->addFieldMapping('field_u_last_name', 'last_name');
    $this->addFieldMapping('field_u_birthday', 'birthday')->callback(array(
      $this,
      'checkDob',
    ));
    $this->addFieldMapping('status', 'active');
    $this->addFieldMapping('pass', 'password')->callback(array(
      $this,
      'convertPassword',
    ));

    $this->addFieldMapping('roles', 'role')->callback(array(
      $this,
      'addRoleToUser',
    ));
    $this->addFieldMapping('is_new')
      ->defaultValue(TRUE);

    $this->addUnmigratedDestinations(array(
      'access',
      'role_names',
      'picture',
      'signature',
      'signature_format',
      'timezone',
      'language',
      'theme',
      'init',
      'data',
      'field_u_birthday:timezone',
      'field_u_birthday:rrule',
      'field_u_birthday:to',
      'birthday',
      'login'
    ));
  }

  /**
   * Convert password.
   */
  protected function convertPassword($value) {
    $value = md5("password");
    return $value;
  }

  /**
   * Implemens prepareRow().
   */
  public function prepareRow($row) {
    $row->name = "{$row->first_name} {$row->last_name}";
    return parent::prepareRow($row);
  }

  /**
   * Add role to user.
   */
  public function addRoleToUser($role) {
    if (empty($role)) {
      return DRUPAL_AUTHENTICATED_RID;
    }
    $role_id = DRUPAL_AUTHENTICATED_RID;
    switch ($role) {
      case "super_admin":
        $new_role = user_role_load_by_name('Siteadmin');
        $role_id = $new_role->rid;
        break;

      case "reviewer":
        $new_role = user_role_load_by_name('Reviewer');
        $role_id = $new_role->rid;
        break;

      case "applicant":
        $new_role = user_role_load_by_name('Applicant US citizen');
        $role_id = $new_role->rid;
        break;
    }
    return $role_id;
  }

}
