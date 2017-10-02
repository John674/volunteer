@api @d7
Feature: Account feature

#  Background:
#    Given I am logged in as a user with the "Siteadmin" role


  @javascript @fail
  Scenario: Test
    Given I am logged in as a user with the "Siteadmin" role
    Then I take screenshot
    Then I should see the text "Welcome admin."
    And I should not see the error message "Sorry, unrecognized username or password"
    And I take screenshot


  @javascript
  Scenario: Login reviewer
    Given I go to "/user"
    And I fill in "edit-name" with "reviewer"
    And I fill in "edit-pass" with "reviewer"
    When I press "edit-submit"
    And I should see the heading "reviewer"


  @javascript
  Scenario: Login siteadmin
    Given I go to "/user"
    And I fill in "edit-name" with "siteadmin"
    And I fill in "edit-pass" with "siteadmin"
    When I press "edit-submit"
    And I should see the heading "siteadmin"

  @javascript
  Scenario: Login volunteer
    When I am logged in as a user with the "Applicant US citizen" role
    Then I should see the link "Create Application"
