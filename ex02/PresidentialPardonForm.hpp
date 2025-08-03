#pragma once

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {

private:
  const std::string _target;

public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string &target);
  ~PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm &other);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

  //====================================================//
  //====================Fuctionality====================//
  //====================================================//
  void performAction() const override;
};
