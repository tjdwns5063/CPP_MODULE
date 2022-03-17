#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
    ShrubberyCreationForm sForm("mkang");
    RobotomyRequestForm rForm("tkim");
    PresidentialPardonForm pForm("jwoo");
    Bureaucrat me;

    try {
       me = Bureaucrat("seongjki", 42);
    } catch (std::exception& err) {
        std::cout << err.what() << '\n';
    }

    try {
        me.signForm(sForm);
        sForm.execute(me);
    } catch (std::exception& err) {
        std::cout << err.what() << '\n';
    }

    try {
        me.signForm(rForm);
        rForm.execute(me);
    } catch (std::exception& err) {
        std::cout << err.what() << '\n';
    }

    try {
        me.signForm(pForm);
        pForm.execute(me);
    } catch (std::exception& err) {
        std::cout << err.what() << '\n';
    }
}