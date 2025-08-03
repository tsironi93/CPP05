#include "./ShrubberyCreationForm.hpp"
#include "./AnsiColors.hpp"
#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <ostream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : _target(other._target) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  (void)other;
  return *this;
}

void ShrubberyCreationForm::performAction() const {
  std::ofstream outfile(this->_target + "_shrubbery");
  if (!outfile)
    std::runtime_error("Failed to create the file");
  outfile << YELLOW <<

      "               . . .\n"
      "         .        .  .     ..    .\n"
      "      .                 .         .  .\n"
      "                      .\n"
      "                     .                ..\n"
      "     .          .            .              .\n"
      "     .            '.,        .               .\n"
      "     .              'b      *\n"
      "      .              '$    #.                ..\n"
      "     .    .           $:   #:               .\n"
      "   ..      .  ..      *#  @):        .   . .\n"
      "                .     :@,@):   ,.**:'   .\n"
      "    .      .,         :@@*: ..**'      .   .\n"
      "             '#o.    .:(@'.@*\"'  .\n"
      "     .  .       'bq,..:,@@*'   ,*      .  .\n"
      "                ,p$q8,:@)'  .p*'      .\n"
      "         .     '  . '@@Pp@@*'    .  .\n"
      "          .  . ..    Y7'.'     .  .\n"
      "                    :@):.\n"
      "                   .:@:'.\n"
      "                 .::(@:.\n"
          << RESET << std::endl;
  outfile.close();
  std::cout << YELLOW << BOLD << "Congratz you have a tree!!!" << RESET
            << std::endl;
}
