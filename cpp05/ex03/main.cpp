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
        bureaucrat = Bureaucrat("seongjki", 45);
    } catch (std::exception& err) {
        std::cout << err.what() << '\n';
    }

    try {
        form = intern.makeForm("shrubbery request", "jwoo");
        bureaucrat.signForm(*form);
        form->execute(bureaucrat);
    } catch (std::exception& err) {
        std::cout << err.what() << '\n';
    }

    try {
        form = intern.makeForm("robotomy request", "tkim");
        bureaucrat.signForm(*form);
        form->execute(bureaucrat);
    } catch (std::exception& err) {
        std::cout << err.what() << '\n';
    }

    try {
        form = intern.makeForm("presidential request", "mkang");
        bureaucrat.signForm(*form);
        form->execute(bureaucrat);
    } catch (std::exception& err) {
        std::cout << err.what() << '\n';
    }
}