@api @d7
Feature: Account feature

#  Background:
#    Given I am logged in as a user with the "Siteadmin" role

  @javascript
  Scenario: Test
    Given I go to "/user"
    Then I am on homepage
    Then I take screenshot
