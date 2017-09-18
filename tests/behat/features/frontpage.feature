@api @d7
Feature: Frontpage feature

  @javascript
  Scenario: Check frontpage is accessible
    Given I am on homepage
    Then I should see the heading "User login"
