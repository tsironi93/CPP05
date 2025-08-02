#include "./AForm.hpp"
#include "./Bureaucrat.hpp"
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
  return "GradeTooHighException triggered\nGrade needs to be between 1 and "
         "150\n";
}

const char *AForm::GradeTooLowException::what() const noexcept {
  return "GradeTooLowException triggered\nGrade needs to be between 1 and "
         "150\n";
}

std::ostream &operator<<(std::ostream &os, const AForm &f) {
  os << std::boolalpha << "AForm name is " << f.getName()
     << " with a grade to sign " << f.getToSign() << " and a grade to excecute "
     << f.getExec() << ". "
     << "The form is signed: " << f.getIsSigned() << "." << std::noboolalpha;
  return os;
}

bool AForm::beSigned(const Bureaucrat &b) {
  if (this->_toSign < b.getGrade()) {
    throw GradeTooLowException();
    return false;
  }
  this->_isSigned = true;
  return true;
}
