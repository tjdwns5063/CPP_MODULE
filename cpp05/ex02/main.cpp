#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
    ShrubberyCreationForm sForm("jwoo"); //sign : 145, exec : 137
    RobotomyRequestForm rForm("tkim"); // sign : 72, exec : 45
    PresidentialPardonForm pForm("mkang"); // sign : 25, exec : 5
    Bureaucrat me;

    try {
       me = Bureaucrat("seongjki", 1);
    } catch (std::exception& err) {
        std::cout << err.what() << '\n';
    }

    try {
        me.signForm(sForm);
        me.executeForm(sForm);
    } catch (std::exception& err) {
        std::cout << err.what() << '\n';
    }

    try {
        me.signForm(rForm);
        me.executeForm(rForm);
    } catch (std::exception& err) {
        std::cout << err.what() << '\n';
    }

    try {
        me.signForm(pForm);
        me.executeForm(pForm);
    } catch (std::exception& err) {
        std::cout << err.what() << '\n';
    }
}