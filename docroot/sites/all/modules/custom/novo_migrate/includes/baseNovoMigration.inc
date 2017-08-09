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

  /**
   * Check date of birthday.
   */
  protected function checkDob($value) {
    if (empty($value)) {
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

}
