<?php

/**
 * @file
 * Support for migration from JSON sources.
 */

/**
 * Implementation of MigrateList, for retrieving a list of IDs to be migrated
 * from a JSON object.
 */
class MigrateSourceApplication extends MigrateSource {
  /**
   * A URL pointing to an JSON object containing a list of IDs to be processed.
   *
   * @var string
   */
  protected $items;

  /**
   * The current row/line number in the applications array.
   *
   * @var integer
   */
  protected $rowNumber;


  public function __construct($items = array()) {
    parent::__construct();
    $this->items = $items;
  }

  /**
   * Our public face is the URL we're getting items from
   *
   * @return string
   */
  public function __toString() {
    return "Applications";
  }

  public function fields() {
    $items = reset($this->items);
    $items = array_keys($items);
    return array_combine($items, $items);
  }

  /**
   * Return a count of all available IDs from the source listing. The default
   * implementation assumes the count of top-level elements reflects the number
   * of IDs available - in many cases, you will need to override this to reflect
   * your particular JSON structure.
   */
  public function computeCount() {
    return count($this->items);
  }

  /**
   * Implementation of MigrateSource::performRewind().
   *
   * @return void
   */
  public function performRewind() {
    $this->rowNumber = 0;
  }

  /**
   * Implementation of MigrateSource::getNextRow().
   * Return the next line of the source CSV file as an object.
   *
   * @return null|object
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