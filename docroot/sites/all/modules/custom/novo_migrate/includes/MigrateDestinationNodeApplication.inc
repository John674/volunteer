<?php

/**
 * @file
 * Support for migration.
 */

/**
 * Implementation of MigrateDestinationNode.
 */
class MigrateDestinationNodeApplication extends MigrateDestinationNode {

  /**
   * MigrateDestinationNodeApplication constructor.
   */
  public function __construct($bundle, array $options = []) {
    parent::__construct($bundle, $options);
  }

  /**
   * Give handlers a shot at modifying the object before saving it.
   */
  public function prepare($entity, stdClass $source_row) {
    // Add source keys for debugging and identification of migrated data by hooks.
    $entity->{VolunteerNovoMigration::NOVO_MIGRATE_REF_REQUEST} = [];
    if (isset($source_row->reference_request) && !empty($source_row->reference_request)) {
      $entity->{VolunteerNovoMigration::NOVO_MIGRATE_REF_REQUEST} = $source_row->reference_request;
    }
    parent::prepare($entity, $source_row);
  }

}
