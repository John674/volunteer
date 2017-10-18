@api @d7
Feature: Kids feature

  Background:
    Given I am logged in as a user with the "Siteadmin" role

  @javascript
  Scenario: Create partner.
    Given I follow "Partners" in the "navbar"
    Then I wait until AJAX is finished
    Then I follow "Add" in the "views_attachment"

    And I fill in "Partner Name" with "Behat partner"

    And I fill in "Address" with "Hello street"
    And I fill in "Address 2" with "Bye"
    And I fill in "Address Apartment number" with "212"
    And I fill in "City" with "Oklahoma"

    And I select "Oklahoma" from "State"
    And I fill in "Zip" with "123456"

    And I select "-None-" from "Staff contact"

    And I fill in "First Name" with "Lenny" in the "edit-field-contact-und-0-field-first-name-und-0-value"
    And I fill in "Last Name" with "Last" in the "edit-field-contact-und-0-field-last-name-und-0-value"
    And I fill in "edit-field-contact-und-0-field-email-und-0-email" with "test@test.com"

    And I fill in "edit-field-contact-und-0-field-phone-und-0-field-phone-number-und-0-value" with "222-222-2222"
    And I select "Home" from "edit-field-contact-und-0-field-phone-und-0-field-phone-type-und"

    And I press the "Save" button
    Then I should not see the following error messages:
      | error messages |
      | field is required |