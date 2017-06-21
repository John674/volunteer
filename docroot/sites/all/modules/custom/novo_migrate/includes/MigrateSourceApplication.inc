<?php

/**
 * @file
 * Support for migration from JSON sources.
 */

/**
 * Implementation of MigrateSource.
 */
class MigrateSourceApplication extends MigrateSource {

  /**
   * A URL pointing to an JSON object containing a list of IDs to be processed.
   *
   * @var array
   */
  protected $items;

  /**
   * The current row/line number in the applications array.
   *
   * @var int
   */
  protected $rowNumber;

  /**
   * MigrateSourceApplication constructor.
   */
  public function __construct($items = array()) {
    parent::__construct();
    $this->items = $items;
  }

  /**
   * Our public face is the URL we're getting items from.
   */
  public function __toString() {
    return "Applications";
  }

  /**
   * Return Fields.
   */
  public function fields() {
    $items = reset($this->items);
    $items = array_keys($items);
    return array_combine($items, $items);
  }

  /**
   * Return a count of all available IDs from the source listing.
   */
  public function computeCount() {
    return count($this->items);
  }

  /**
   * Implementation of MigrateSource::performRewind().
   */
  public function performRewind() {
    $this->rowNumber = 0;
  }

  /**
   * Implementation of MigrateSource::getNextRow().
   */
  public function getNextRow() {
    if (isset($this->items[$this->rowNumber])) {
      $data = (object) $this->items[$this->rowNumber];
      $this->rowNumber++;
      return $data;
    }
    else {
      return NULL;
    }
  }

}
