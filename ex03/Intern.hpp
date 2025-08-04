#pragma once

#include <string>
class AForm;

class Intern {

public:
  Intern();
  ~Intern();
  Intern(const std::string &I_HATE_CANONICAL_FORM);
  Intern(const Intern &other);
  Intern &operator=(const Intern &other);

  AForm *makeForm(const std::string &formName, const std::string &targetName);
};
