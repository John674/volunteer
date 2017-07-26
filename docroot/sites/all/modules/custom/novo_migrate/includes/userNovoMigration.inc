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

    $this->addFieldMapping('roles')
      ->defaultValue(DRUPAL_AUTHENTICATED_RID);
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
   * Implements complete.
   */
  public function complete($entity, $row) {
    $user = user_load($entity->uid);
    $this->addRoleToUser($user, $row->role);
    $this->uniqueUsername($user);
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
  public function addRoleToUser($user, $role) {

    switch ($role) {
      case "super_admin":
        $role_name = 'Siteadmin';
        break;

      case "reviewer":
        $role_name = 'Reviewer';
        break;

      case "applicant":
        $role_name = 'Applicant US citizen';
        break;
    }
    // Add new role to existing roles.
    if (isset($user->uid) && $user->uid > 0) {
      $user_roles = $new_role = [];
      // If the user doesn't already have the role, add the role to that user.
      $role_exist = array_search($role_name, $user->roles);
      if (empty($role_exist)) {
        // Get the rid from the roles table.
        $roles = user_roles(TRUE);
        $rid = array_search($role_name, $roles);
        if (is_numeric($rid)) {
          $new_role[$rid] = $role_name;
          $user_roles['roles'] = $user->roles + $new_role;
        }
      }
      user_save($user, $user_roles);
    }
  }

  /**
   * Check or create a unique username.
   */
  public function uniqueUsername($user) {
    $user_name = $user->name;
    $user_name = str_replace(" ", "_", $user_name);
    $uid = $user->uid;
    $i = 0;
    do {
      $new_name = empty($i) ? $user_name : $user_name . '_' . $i;

      if ($uid) {
        $found = db_query_range("SELECT uid from {users} WHERE uid <> :uid AND name = :name", 0, 1, array(':uid' => $uid, ':name' => $new_name))->fetchAssoc();
      }
      else {
        $found = db_query_range("SELECT uid from {users} WHERE name = :name", 0, 1, array(':name' => $new_name))->fetchAssoc();
      }

      $i++;
    } while (!empty($found));

    // Replace with generated username.
    db_update('users')
      ->fields(array('name' => $new_name))
      ->condition('uid', $user->uid)
      ->execute();
  }

}
