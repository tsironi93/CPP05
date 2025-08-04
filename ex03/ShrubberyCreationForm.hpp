#pragma once

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {

private:
  const std::string _target;

public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string &target);
  ~ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

  //====================================================//
  //====================Fuctionality====================//
  //====================================================//
  void performAction() const override;
};
