#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main(void) {
    Bureaucrat bureaucrat("mkang", 1);
    Intern  intern;
    

    try {
        Form* form = intern.makeForm("shrubbery request", "jwoo");
        bureaucrat.signForm(*form);
        form->execute(bureaucrat);
        

        form = intern.makeForm("robotomy request", "tkim");
        bureaucrat.signForm(*form);
        form->execute(bureaucrat);

        form = intern.makeForm("presidential request", "seongjki");
        bureaucrat.signForm(*form);
        form->execute(bureaucrat);
    } catch (std::exception& err) {
        std::cout << err.what() << '\n';
    }
}