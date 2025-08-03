#include "./AForm.hpp"
#include "./Bureaucrat.hpp"
#include "AnsiColors.hpp"
#include <iostream>

AForm::AForm(const std::string &name, const int toSign, const int toExec)
    : _name(name), _toSign(toSign), _toExec(toExec), _isSigned(false) {

  if (_toExec < 1)
    throw GradeTooHighException();
  if (_toExec > 150)
    throw GradeTooLowException();

  if (_toSign < 1)
    throw GradeTooHighException();
  if (_toSign > 150)
    throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &other)
    : _name(other._name), _toSign(other._toSign), _toExec(other._toExec),
      _isSigned(other._isSigned) {}

AForm &AForm::operator=(const AForm &other) {
  if (this != &other) {
    this->_isSigned = other.getIsSigned();
  }
  return *this;
}

const std::string &AForm::getName() const { return _name; }

int AForm::getToSign() const { return _toSign; }

int AForm::getExec() const { return _toExec; }

bool AForm::getIsSigned() const { return _isSigned; }

const char *AForm::GradeTooHighException::what() const noexcept {
  return RESET BOLD YELLOW
      "GradeTooHighException triggered\nGrade needs to be between 1 and "
      "150\n" RESET;
}

const char *AForm::GradeTooLowException::what() const noexcept {
  return RESET BOLD YELLOW
      "GradeTooLowException triggered\nGrade needs to be between 1 and "
      "150\n" RESET;
}

const char *AForm::FormNotSignedException::what() const noexcept {
  return RESET BOLD YELLOW
      "Form cant be executed because its not signed\n" RESET;
}

const char *AForm::FormIsAlreadySignedException::what() const noexcept {
  return RESET BOLD YELLOW "Form is already signed by another Bureaucrat" RESET;
}

std::ostream &operator<<(std::ostream &os, const AForm &f) {
  os << std::boolalpha << "AForm name is " << f.getName()
     << " with a grade to sign " << f.getToSign() << " and a grade to excecute "
     << f.getExec() << ". "
     << "The form is signed: " << f.getIsSigned() << "." << std::noboolalpha;
  return os;
}

bool AForm::beSigned(const Bureaucrat &b) {
  if (this->getIsSigned()) {
    throw FormIsAlreadySignedException();
    return false;
  }
  if (this->_toSign < b.getGrade()) {
    throw GradeTooLowException();
    return false;
  }
  this->_isSigned = true;
  return true;
}

void AForm::execute(Bureaucrat const &executor) const {
  if (!_isSigned)
    throw FormNotSignedException();
  if (executor.getGrade() > this->_toExec)
    throw GradeTooLowException();
  performAction();
}
