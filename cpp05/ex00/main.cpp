#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
    Bureaucrat temp = Bureaucrat("me", 0);
    try {
        temp.getGrade();
    } catch (std::exception& err) {
        std::cerr << err.what();
    }
}