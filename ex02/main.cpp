#include "./Bureaucrat.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "AnsiColors.hpp"
#include <iostream>

void runTest(const std::string &testName, std::function<void()> testFunc) {
  std::cout << "=== " << testName << " ===\n";
  try {
    testFunc();
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << "\n";
  }
  std::cout << "\n";
}

int main() {
  runTest("1. Signing with insufficient grade", []() {
    Bureaucrat lowRank("Tom", 150);
    ShrubberyCreationForm form("home");
    lowRank.signForm(form); // Should fail
  });

  runTest("2. Successful signing and execution", []() {
    Bureaucrat bob("Bob", 1); // High rank
    ShrubberyCreationForm form("park");
    bob.signForm(form);
    bob.executeForm(form); // Should create file
  });

  runTest("3. Execution without signing", []() {
    Bureaucrat alice("Alice", 1);
    PresidentialPardonForm form("Ford");
    alice.executeForm(form); // Should throw FormNotSignedException
  });

  runTest("4. Execution with too low grade", []() {
    Bureaucrat joe("Joe", 140); // Sign is OK, exec is too low
    ShrubberyCreationForm form("backyard");
    joe.signForm(form);    // Should succeed
    joe.executeForm(form); // Should fail
  });

  runTest("5. Robotomy 10 attempts (see randomness)", []() {
    Bureaucrat driller("RoboOp", 1);
    RobotomyRequestForm form("Marvin");
    driller.signForm(form);
    for (int i = 0; i < 10; ++i) {
      std::cout << BOLD << "=================================================\n"
                << RESET << std::endl;
      driller.executeForm(form); // Random success/failure
    }
  });

  runTest("6. Pardon with exact grade", []() {
    Bureaucrat zaphod("Zaphod", 5);
    PresidentialPardonForm form("Arthur");
    zaphod.signForm(form);    // Needs 25 — OK
    zaphod.executeForm(form); // Needs 5 — OK
  });

  return 0;
}
