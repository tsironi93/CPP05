#pragma once

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {

private:
  const std::string _target;

public:
  ShrubberyCreationForm() = delete;
  ShrubberyCreationForm(const std::string &target);
  ~ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

  //====================================================//
  //====================Fuctionality====================//
  //====================================================//
  void execute(const std::string &target) const override;
};

#endif // !ShrubberyCreationForm
