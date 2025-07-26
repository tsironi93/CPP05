#include "./Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main() {
  try {

    Bureaucrat a("malaka", -1);

    Bureaucrat b("malakaB", 151);

    Bureaucrat c("MisterNice", 1);
    std::cout << c << std::endl;
    c.incrementGrade();

    Bureaucrat d("MisterNot", 150);
    std::cout << d << std::endl;
    d.decrementGrade();

    Bureaucrat f("MisterAverage", 75);
    std::cout << f << std::endl;
    f.decrementGrade();
    std::cout << f << std::endl;
    f.incrementGrade();
    std::cout << f << std::endl;

  } catch (std::exception &e) {
    std::cout << e.what();
  }
}
