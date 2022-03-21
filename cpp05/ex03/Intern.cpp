#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <sstream>

Intern::Intern( void ) {
    forms[SHRUBBERY] = new std::string("shrubbery creation");
    forms[ROBOTOMY] = new std::string("robotomy request");
    forms[PRESIDENTIAL] = new std::string("presidential pardon");
}

Intern::~Intern( void ) {
    for (int idx = 0; idx < 3; idx++) {
        delete (forms[idx]);
    }
}

Intern::Intern( const Intern& ref ) {
    forms[SHRUBBERY] = new std::string(*ref.forms[SHRUBBERY]);
    forms[ROBOTOMY] = new std::string(*ref.forms[ROBOTOMY]);
    forms[PRESIDENTIAL] = new std::string(*ref.forms[PRESIDENTIAL]);
}

Intern& Intern::operator=( const Intern& ref ) {
    if (this == &ref)
        return (*this);
    for (int idx = 0; idx < 3; idx++) {
        delete (forms[idx]);
    }
    forms[SHRUBBERY] = new std::string(*ref.forms[SHRUBBERY]);
    forms[ROBOTOMY] = new std::string(*ref.forms[ROBOTOMY]);
    forms[PRESIDENTIAL] = new std::string(*ref.forms[PRESIDENTIAL]);
    return (*this);
}

const char* Intern::UnknownNameException::what( void ) const throw() {
    return ("this form name is unknown");
}

Form*  Intern::makeForm(std::string formName, std::string target) {
    for (int idx = 0; idx < 3; idx++) {
        switch (idx) {
            case SHRUBBERY:
                if (*forms[SHRUBBERY] == formName) {
                    return (new ShrubberyCreationForm(target));
                }
            case ROBOTOMY:
                if (*forms[ROBOTOMY] == formName) {
                    return (new RobotomyRequestForm(target));
                }
            case PRESIDENTIAL:
                if (*forms[PRESIDENTIAL] == formName) {
                    return (new PresidentialPardonForm(target));
                }
        }
    }
    throw Intern::UnknownNameException();
}