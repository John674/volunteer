<?php
/**
 * @file
 * Feature context.
 */

// Contexts.
use Behat\Behat\Context\Context;
use Behat\Mink\Driver\Selenium2Driver;
use Drupal\DrupalExtension\Context\RawDrupalContext;

use Behat\Behat\Hook\Scope\AfterStepScope;


/**
 * Class FeatureContext.
 */
class FeatureContext extends RawDrupalContext implements Context {

  /**
   * Initializes context.
   *
   * Every scenario gets its own context instance.
   * You can also pass arbitrary arguments to the
   * context constructor through behat.yml.
   */
  public function __construct() {

  }


  /**
   * @AfterStep
   */
  public function takeScreenShotAfterFailedStep(afterStepScope $scope) {
    if (99 === $scope->getTestResult()->getResultCode()) {
      $driver = $this->getSession()->getDriver();
      if (!($driver instanceof Selenium2Driver)) {
        return;
      }
      file_put_contents(__DIR__ . '/../../../tmp/debug.png', $this->getSession()
        ->getDriver()
        ->getScreenshot());
    }
  }


  /**
   * @When I take screenshot
   */
  public function iTakeScreenshot() {
    static $counter = 0;
    $filename = 'filename' . $counter . '.png';


    $driver = $this->getSession()->getDriver();

    var_export($driver->getContent());
    var_export($driver->getCurrentUrl());
    if (!($driver instanceof Selenium2Driver)) {
      throw new Exception(format_string("Selenium2Driver not found."));
    }

    $base64 = $driver->getScreenshot();
    var_export($base64);
    if (!empty($base64)) {
      file_put_contents(__DIR__ . '/../../../tmp/' . $filename, $base64);
      print_r($filename);
      $counter++;
    }
  }

  /**
   * @Then I visit content :title
   *
   * Query the node by title and redirect.
   */
  public function iVisitContent($title) {
    $query = new entityFieldQuery();
    $result = $query
      ->entityCondition('entity_type', 'node')
      ->propertyCondition('title', $title)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->range(0, 1)
      ->execute();
    if (empty($result['node'])) {
      $params = ['@title' => $title];
      throw new Exception(format_string("Node @title not found.", $params));
    }
    $nid = key($result['node']);
    $this->getSession()->visit($this->locatePath('node/' . $nid));
  }

  /**
   * @When I debug output
   */
  public function iDebugOutput() {
    $output = $this->getSession()->getPage()->getOuterHtml();
    $filepath = __DIR__ . '../../../tmp/behat-debug-' . rand(0, 10000) . '.html';
    file_put_contents($filepath, $output);
    print_r('Debug ' . $filepath);
  }

  /**
   * @When I wait for AJAX to finish with delay
   */
  public function iWaitForAjaxToFinishWithDelay() {
    $this->getSession()
      ->wait(5000, '(typeof(jQuery)=="undefined" || (0 === jQuery.active && 0 === jQuery(\':animated\').length))');
    $this->iWaitForMs(1000);
  }

  /**
   * @When I check that :number emails was sent to :to
   */
  public function checkThatEmailsWasSent($number, $to) {
    $count = 0;
    foreach ($this->getAllEmailMessages() as $message) {
      if ($message['to'] === $to || (isset($message['params']['headers']['Cc']) && $message['params']['headers']['Cc'] == $to)) {
        $count++;
      }
    }

    if ($count == $number) {
      return TRUE;
    }

    throw new \RuntimeException(sprintf('The message was not sent to "%s" email.', $to));
  }

  /**
   * @When I click by element with id :id
   */
  public function clickByElementWithId($id) {
    $page = $this->getSession()->getPage();
    $element = $page->find('css', '#' . $id);
    if ($element) {
      $element->click();
    }
    else {
      throw new \RuntimeException(sprintf("Can't find element with ID '%s'.", $id));
    }
  }

  /**
   * @When I click by label with for :for
   */
  public function clickByLabelWithFor($for) {
    $page = $this->getSession()->getPage();
    $element = $page->find('xpath', "//label[@for='" . $for . "']");
    if ($element) {
      $element->click();
    }
    else {
      throw new \RuntimeException(sprintf("Can't find label with ащк '%s'.", $for));
    }
  }

  /**
   * Find text in a table row containing given text.
   *
   * @Then I should see the text :text in the :rowText row multiple
   */
  public function assertTextInTableRowMultiple($text, $rowText) {
    $page = $this->getSession()->getPage();
    $rows = $page->findAll('css', 'tr');

    if (empty($rows)) {
      throw new \Exception(sprintf('No rows found on the page %s', $this->getSession()
        ->getCurrentUrl()));
    }
    $new_rows = [];
    foreach ($rows as $key => $row) {
      if (strpos($row->getText(), $rowText) !== FALSE) {
        $new_rows[] = $row;
      }
    }
    if (empty($new_rows)) {
      throw new \Exception(sprintf('Failed to find a row containing "%s" on the page %s', $rowText, $this->getSession()
        ->getCurrentUrl()));
    }

    foreach ($new_rows as $row) {
      if (strpos($row->getText(), $text) !== FALSE) {
        return;
      }
    }

    throw new \Exception(sprintf('Found a row containing "%s", but it did not contain the text "%s".', $rowText, $text));
  }

  /**
   * Get all email messages
   *
   * @return array
   *   An array of messages that was sent.
   */
  public function getAllEmailMessages() {
    // We can't use variable_get() because Behat has another bootstrapped
    // variable $conf that is not updated from curl bootstrapped
    // Drupal instance.
    if (empty($this->all_messages)) {
      $this->all_messages = db_select('variable', 'v')
        ->fields('v', ['value'])
        ->condition('name', 'drupal_test_email_collector', '=')
        ->execute()
        ->fetchField();

      $this->all_messages = unserialize($this->all_messages);
    }

    if (empty($this->all_messages)) {
      throw new \RangeException('No one message was sent.');
    }

    return $this->all_messages;
  }

}