#include "./Bureaucrat.hpp"
#include <cstdint>
#include <string>

Bureaucrat::Bureaucrat(const std::string &name, uint_fast8_t grade)
    : _name(name) {

  if (grade < 1)
    throw GradeTooHighException();
  if (grade > 150)
    throw GradeTooHighException();
  this->_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const { return _name; }

uint_fast8_t Bureaucrat::getGrade() const { return _grade; }

const char *Bureaucrat::GradeTooHighException::what() const noexcept {
  return "GradeTooHighException triggered\n Grade needs to be between 1 and "
         "150\n";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept {
  return "GradeTooLowException triggered\n Grade needs to be between 1 and "
         "150\n";
}

void Bureaucrat::incrementGrade() {
  if (_grade <= 1)
    throw GradeTooHighException();
  --_grade;
}

void Bureaucrat::decrementGrade() {
  if (_grade >= 150)
    throw GradeTooLowException();
  ++_grade;
}
