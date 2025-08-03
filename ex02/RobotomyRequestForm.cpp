#include "./RobotomyRequestForm.hpp"
#include "./AnsiColors.hpp"
#include "AForm.hpp"
#include <chrono>
#include <iostream>
#include <random>
#include <thread>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("Default") {};

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : _target(other._target) {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  (void)other;
  return *this;
}

int RandomNum() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(1, 1000);

  const int rndm = dist(gen);
  // std::cout << rndm << std::endl;
  return rndm;
}

void RobotomyRequestForm::performAction() const {
  std::cout << BOLD << MAGENTA << "Making drilling noizes!!!\nZzZzZz...."
            << RESET << std::endl;
  while (RandomNum() > 250) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << BOLD << MAGENTA << "ZzZzZz...." << RESET << std::endl;
  }
  if (RandomNum() > 500) {
    std::cout << YELLOW << BOLD << "The taget " << this->_target
              << " robotomization FAILED" << RESET << std::endl;
    return;
  }
  std::cout << YELLOW << BOLD << "The taget " << this->_target
            << " has been robotomized SUCCESSFULLY" << RESET << std::endl;
}
