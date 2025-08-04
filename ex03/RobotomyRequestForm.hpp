#pragma once

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {

private:
  const std::string _target;

public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string &target);
  ~RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm &other);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

  //====================================================//
  //====================Fuctionality====================//
  //====================================================//
  void performAction() const override;
};
