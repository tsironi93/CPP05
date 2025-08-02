#pragma once

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>

class AForm;

class Bureaucrat {

private:
  const std::string _name;
  int _grade;

public:
  Bureaucrat() = delete;
  Bureaucrat(const std::string &name, int grade);
  ~Bureaucrat();
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);

  const std::string &getName() const;
  int getGrade() const;

  //-----------------Exeptions-----------------------//
  //-------------------------------------------------//
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const noexcept override;
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const noexcept override;
  };

  void incrementGrade();
  void decrementGrade();

  void signForm(AForm &f);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif // !BUREAUCRAT_HPP
