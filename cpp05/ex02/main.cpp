#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
    Bureaucrat me("me", 1);
    ShrubberyCreationForm sForm("seongjki");
    RobotomyRequestForm rForm("tkim");
    PresidentialPardonForm pForm("jwoo");
    

    try {
        me.signForm(sForm);
        std::cout << sForm.getSign() << '\n';
        sForm.execute(me);

        me.signForm(rForm);
        rForm.execute(me);

        me.signForm(pForm);
        pForm.execute(me);
    } catch (std::exception& err) {
        std::cout << err.what() << '\n';
    }
}