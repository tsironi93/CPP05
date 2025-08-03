#pragma once

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {

private:
  const std::string _target;

public:
  ShrubberyCreationForm() = delete;
  ShrubberyCreationForm(const std::string &target);
  ~ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm &other) = delete;
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other) = delete;

  //====================================================//
  //====================Fuctionality====================//
  //====================================================//
  void performAction() const override;
};
