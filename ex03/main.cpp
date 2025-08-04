#include "./AForm.hpp"
#include "./Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
  Intern intern;

  // Create a RobotomyRequestForm for "Bender"
  AForm *form1 = intern.makeForm("robotomy request", "Bender");
  if (form1) {
    std::cout << "Form created\n";
    delete form1; // cleanup!
  }

  // Create a ShrubberyCreationForm for "Home"
  AForm *form2 = intern.makeForm("shrubbery creation", "Home");
  if (form2) {
    std::cout << "Form created\n";
    delete form2;
  }

  // Create a PresidentialPardonForm for "Ford"
  AForm *form3 = intern.makeForm("presidential pardon", "Ford");
  if (form3) {
    std::cout << "Form created\n";
    delete form3;
  }

  // Try to create an unknown form
  AForm *form4 = intern.makeForm("nonsense form", "Nobody");
  if (!form4) {
    std::cout << "Unknown form was not created.\n";
  } else {
    delete form4;
  }

  return 0;
}
