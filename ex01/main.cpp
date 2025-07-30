#include "./Bureaucrat.hpp"
#include "./Form.hpp"
#include <exception>
#include <iostream>

int main() {
  std::cout << "----- Test 1: Valid signing -----" << std::endl;
  try {
    Bureaucrat highRank("Alice", 5);
    Form topSecret("Top Secret Form", 10, 50);
    std::cout << topSecret << std::endl;

    highRank.signForm(topSecret);
    std::cout << topSecret << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error in Test 1: " << e.what() << std::endl;
  }

  std::cout << "\n----- Test 2: Grade too low to sign -----" << std::endl;
  try {
    Bureaucrat lowRank("Bob", 100);
    Form highClearance("Nuclear Launch Form", 50, 50);
    std::cout << highClearance << std::endl;

    lowRank.signForm(highClearance); // should throw
    std::cout << highClearance << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error in Test 2: " << e.what() << std::endl;
  }

  std::cout << "\n----- Test 3: Invalid form grades -----" << std::endl;
  try {
    Form badForm("InvalidForm", 0, 160); // invalid grades
  } catch (const std::exception &e) {
    std::cerr << "Caught error as expected: " << e.what() << std::endl;
  }

  std::cout << "\n----- Test 4: Re-signing a form -----" << std::endl;
  try {
    Bureaucrat midRank("Charlie", 25);
    Form project("Project Plan", 30, 100);
    std::cout << project << std::endl;

    midRank.signForm(project); // should succeed
    midRank.signForm(project); // should still succeed or do nothing
    std::cout << project << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error in Test 4: " << e.what() << std::endl;
  }

  return 0;
}
