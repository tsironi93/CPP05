#pragma once

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;

class AForm {

private:
  const std::string _name;
  const int _toSign;
  const int _toExec;
  bool _isSigned;

public:
  AForm() = delete;
  AForm(const std::string &name, const int toSign, const int toExec);
  virtual ~AForm();
  AForm(const AForm &other);
  AForm &operator=(const AForm &other);

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
  virtual void execute(const std::string &target) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &f);
