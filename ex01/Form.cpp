#include "./Form.hpp"
#include "./Bureaucrat.hpp"
#include <iostream>

Form::Form(const std::string &name, const int toSign, const int toExec)
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

Form::~Form() {}

Form::Form(const Form &other)
    : _name(other._name), _toSign(other._toSign), _toExec(other._toExec),
      _isSigned(other._isSigned) {}

Form &Form::operator=(const Form &other) {
  if (this != &other) {
    this->_isSigned = other.getIsSigned();
  }
  return *this;
}

const std::string &Form::getName() const { return _name; }

int Form::getToSign() const { return _toSign; }

int Form::getExec() const { return _toExec; }

bool Form::getIsSigned() const { return _isSigned; }

const char *Form::GradeTooHighException::what() const noexcept {
  return "GradeTooHighException triggered\nGrade needs to be between 1 and "
         "150\n";
}

const char *Form::GradeTooLowException::what() const noexcept {
  return "GradeTooLowException triggered\nGrade needs to be between 1 and "
         "150\n";
}

std::ostream &operator<<(std::ostream &os, const Form &f) {
  os << std::boolalpha << "Form name is " << f.getName()
     << " with a grade to sign " << f.getToSign() << " and a grade to excecute "
     << f.getExec() << ". "
     << "The form is signed: " << f.getIsSigned() << "." << std::noboolalpha;
  return os;
}

bool Form::beSigned(const Bureaucrat &b) {
  if (this->_toSign < b.getGrade()) {
    throw GradeTooLowException();
    return false;
  }
  this->_isSigned = true;
  return true;
}
