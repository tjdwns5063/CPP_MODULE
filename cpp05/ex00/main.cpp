#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
    Bureaucrat temp = Bureaucrat("me", 150);
    for (int i = 0; i < 3; i++) {
        std::cout << temp++;
    }
    std::cout << temp;
    try {
        temp.getGrade();
    } catch (std::exception& err) {
        std::cout << err.what();
    }
}