@api @d7
Feature: Kids feature

  Background:
    Given I am logged in as a user with the "Siteadmin" role

  @javascript
  Scenario: Create staff.
    Given I follow "Staff" in the "navbar"
    Then I wait until AJAX is finished
    Then I follow "Add" in the "views_attachment"

    And I fill in "First Name" with "Behat staff"

    And I fill in "Goes By" with "tv"
    And I fill in "Middle Name" with "middle"
    And I fill in "Last Name" with "last"
    And I fill in "Job Title" with "Ms"
    And I fill in "edit-field-email-und-0-email" with "test@test.com"

    And I fill in "edit-field-phone-und-0-field-phone-number-und-0-value" with "111-111-1111"
    And I select "Home" from "edit-field-phone-und-0-field-phone-type-und"

    And I select "Discipline" from "Training Completed"
    And I fill in "Training Completed Date" with "10/10/2017"

    And I press the "Save" button
    Then I should not see the following error messages:
      | error messages |
      | field is required |