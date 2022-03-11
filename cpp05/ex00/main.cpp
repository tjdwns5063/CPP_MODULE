#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
    {
        std::cout << '\n' << "-------------test1--------------\n\n";
        try {
            Bureaucrat  temp("temp", 10);
            int iter = 10;

            while (iter--) {
                std::cout << ++temp << '\n';
            }
        } catch (std::exception& err) {
            std::cerr << err.what() << '\n';
        }
    }
    {
        std::cout << '\n' << "-------------test2--------------\n\n";
        try {
            Bureaucrat  temp("temp", 141);
            int iter = 10;

            while (iter--) {
                std::cout << --temp << '\n';
            }
            std::cout << temp << '\n';
        } catch (std::exception& err) {
            std::cerr << err.what() << '\n';
        }
    }
    {
        std::cout << '\n' << "-------------test3--------------\n\n";
        try {
            Bureaucrat  temp("temp", 0);
        } catch (std::exception& err) {
            std::cerr << err.what() << '\n';
        }
    }
    {
        std::cout << '\n' << "-------------test4--------------\n\n";
        try {
            Bureaucrat  temp("temp", 151);
        } catch (std::exception& err) {
            std::cerr << err.what() << '\n';
        }
    }
}