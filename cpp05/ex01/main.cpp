#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void) {
    {
        try {
            Bureaucrat me("me", 5);
            Form    form("form", 5, 5);

            me.signForm(form);
        } catch (std::exception& err) {
            std::cout << err.what() << '\n';
        }
    }
    {
        try {
            Bureaucrat me("me", 6);
            Form    form("form", 5, 5);

            me.signForm(form);
        } catch (std::exception& err) {
            std::cout << err.what() << '\n';
        }
    }
    {
        try {
            Bureaucrat me("me", 6);
            Form    form("form", 151, 5);

            me.signForm(form);
        } catch (std::exception& err) {
            std::cout << err.what() << '\n';
        }
    }
    {
        try {
            Bureaucrat me("me", 6);
            Form    form("form", 5, 0);

            me.signForm(form);
        } catch (std::exception& err) {
            std::cout << err.what() << '\n';
        }
    }
}
