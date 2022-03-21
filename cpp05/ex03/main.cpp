#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main(void) {
    Bureaucrat bureaucrat;
    Intern  intern;
    Form*   form;

    try {
        bureaucrat = Bureaucrat("seongjki", 70);
    } catch (std::exception& err) {
        std::cout << err.what() << '\n';
    }

    try {
        form = intern.makeForm("shrubbery creation", "jwoo");
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
    } catch (std::exception& err) {
        std::cout << err.what() << '\n';
    }

    try {
        form = intern.makeForm("robotomy request", "tkim");
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
    } catch (std::exception& err) {
        std::cout << err.what() << '\n';
    }

    try {
        form = intern.makeForm("presidential pardon", "mkang");
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
    } catch (std::exception& err) {
        std::cout << err.what() << '\n';
    }
}