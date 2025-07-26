#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <cstdint>
#include <exception>
#include <string>

class Bureaucrat {

private:
  const std::string _name;
  uint_fast8_t _grade;

public:
  Bureaucrat(const std::string &name, uint_fast8_t grade);
  ~Bureaucrat();

  const std::string &getName() const;
  uint_fast8_t getGrade() const;

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
};

#endif // !BUREAUCRAT_HPP
