@api @d7
Feature: Kids feature

  Background:
    Given I am logged in as a user with the "Siteadmin" role

  @javascript
  Scenario: Create kid.
    Given I follow "Kids" in the "navbar"
    Then I wait until AJAX is finished
    Then I follow "Add" in the "views_attachment"

    And I fill in "First Name" with "Behat kid"

    And I fill in "Goes By" with "sv"
    And I fill in "Middle Name" with "middle"
    And I fill in "Last Name" with "pet"
    And I fill in "Suffix" with "Mr"
    And I fill in "Date of Birth" with "09/05/2007"
    And I select the radio button "M"

    And I fill in "Address" with "Vince street"
    And I fill in "Address 2" with "Afrik"
    And I fill in "Address Apartment number" with "786"
    And I fill in "City" with "Oklahoma"

    And I select "Nevada" from "State"
    And I fill in "Zip" with "12345"

    And I fill in "School name" with "Stanley"
    And I select "8" from "Grade"

    And I fill in "Teacher name" with "Ammy Wilson"
    And I fill in "Church name" with "behat Church name"
    And I select the radio button "Yes"

    And I fill in "Food Allergies" with "no"
    And I fill in "Health Concerns" with "behat Health Concerns"
    And I check the box "Moved"

    And I select "other" from "Ethnicity"
    And I select the radio button "XXL"

    And I fill in "First Name" with "Alex" in the "field_parent_guardian_values"
    And I fill in "Last Name" with "Stage" in the "field_parent_guardian_values"
    And I fill in "edit-field-parent-guardian-und-0-field-phone-und-0-field-phone-number-und-0-value" with "999-999-9999"

    And I press the "Save" button
    Then I should not see the following error messages:
      | error messages |
      | field is required |