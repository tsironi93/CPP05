#include "./PresidentialPardonForm.hpp"
#include "./AnsiColors.hpp"
#include "AForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), _target("Default") {};

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : _target(other._target) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  (void)other;
  return *this;
}

void PresidentialPardonForm::performAction() const {}
