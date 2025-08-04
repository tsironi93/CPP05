#include "./Intern.hpp"
#include "./AForm.hpp"
#include "./AnsiColors.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include <iostream>
#include <ostream>

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const std::string &I_HATE_CANONICAL_FORM) {
  std::cout << BOLD << RED << "I HATE CANONICAL FORM!" << I_HATE_CANONICAL_FORM
            << RESET << std::endl;
}

Intern::Intern(const Intern &other) { (void)other; }

Intern &Intern::operator=(const Intern &other) {
  (void)other;
  return *this;
}

AForm *Intern::makeForm(const std::string &formName,
                        const std::string &targetName) {

  struct FormMap {
    std::string _name;
    AForm *(*create)(const std::string &);
  };

  FormMap forms[] = {
      {"shrubbery creation",
       [](const std::string &t) -> AForm * {
         return new ShrubberyCreationForm(t);
       }},
      {"robotomy request",
       [](const std::string &t) -> AForm * {
         return new RobotomyRequestForm(t);
       }},
      {"Presidential pardon", [](const std::string &t) -> AForm * {
         return new PresidentialPardonForm(t);
       }}};

  for (const auto &f : forms) {
    if (f._name == formName) {
      std::cout << CYAN << "Intern creates " << formName << " form." << RESET
                << std::endl;
      return f.create(targetName);
    }
  }

  std::cout << RED << BOLD << "ERROR: This form: " << formName
            << " doesnt exist." << std::endl;
  return nullptr;
}
