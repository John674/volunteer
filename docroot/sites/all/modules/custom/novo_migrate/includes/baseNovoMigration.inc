<?php

/**
 * @file
 * Basic class to handle the novo migration.
 */

/**
 * Class BaseNovoMigration.
 */
class BaseNovoMigration extends Migration {

  public $databaseKey = NULL;

  /**
   * General initialization of a Migration object.
   */
  public function __construct($args) {
    parent::__construct($args);
    $this->databaseKey = "old_database";
  }

}
