#include "./Bureaucrat.hpp"
#include "./ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

int main() {
  try {
    Bureaucrat b("malakas", 75);
    ShrubberyCreationForm a("malaka");
    a.beSigned(b);
    a.execute("malakatree");

  } catch (const std::exception &e) {
    std::cerr << "ERROR: " << e.what() << std::endl;
  }
}
