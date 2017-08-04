<?php

/**
 * @file
 * Support for migration.
 */

/**
 * Implementation of MigrateDestinationNode.
 */

class MigrateDestinationNodeApplication extends MigrateDestinationNode {

  public function __construct($bundle, array $options = []) {
    parent::__construct($bundle, $options);
  }


  /**
   * Give handlers a shot at modifying the object before saving it.
   *
   * @param $entity
   *  Entity object to build. Prefilled with any fields mapped in the Migration.
   * @param $source_row
   *  Raw source data object - passed through to prepare handlers.
   */
  public function prepare($entity, stdClass $source_row) {
    // Add source keys for debugging and identification of migrated data by hooks.
    $entity->test_field = "test_seconds_tewffdsa";
    parent::prepare($entity, $source_row);
  }
}
