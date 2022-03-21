#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void) {
    {
        std::cout << '\n' << "-------------test1--------------\n\n";
        try {
            Bureaucrat me("me", 5);
            Form    form("tempForm", 5, 5);

            me.signForm(form);
            std::cout << form << '\n';
        } catch (std::exception& err) {
            std::cerr << err.what() << '\n';
        }
    }
    {
        std::cout << '\n' << "-------------test2--------------\n\n";
        try {
            Bureaucrat me("me", 6);
            Form    form("tempForm", 5, 5);

            me.signForm(form);
            std::cout << form << '\n';
        } catch (std::exception& err) {
            std::cerr << err.what() << '\n';
        }
    }
    {
        std::cout << '\n' << "-------------test3--------------\n\n";
        try {
            Bureaucrat me("me", 6);
            Form    form("tempForm", 151, 5);

            me.signForm(form);
            std::cout << form << '\n';
        } catch (std::exception& err) {
            std::cerr << err.what() << '\n';
        }
    }
    {
        std::cout << '\n' << "-------------test4--------------\n\n";
        try {
            Bureaucrat me("me", 6);
            Form    form("tempForm", 5, 0);

            me.signForm(form);
            std::cout << form << '\n';
        } catch (std::exception& err) {
            std::cerr << err.what() << '\n';
        }
    }
}
