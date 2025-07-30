#pragma once

#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;

class Form {

private:
  const std::string _name;
  const int _toSign;
  const int _toExec;
  bool _isSigned;

public:
  Form() = delete;
  Form(const std::string &name, const int toSign, const int toExec);
  ~Form();
  Form(const Form &other);
  Form &operator=(const Form &other);

  //====================================================//
  //======================Exceptions====================//
  //====================================================//
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const noexcept override;
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const noexcept override;
  };

  //====================================================//
  //=======================Geters=======================//
  //====================================================//
  const std::string &getName() const;
  bool getIsSigned() const;
  int getToSign() const;
  int getExec() const;

  //====================================================//
  //====================Fuctionality====================//
  //====================================================//
  bool beSigned(const Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif // !FORM_HPP
