#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern( void ) {
    forms[SHRUBBERY] = new ShrubberyCreationForm("");
    forms[ROBOTOMY] = new RobotomyRequestForm("");
    forms[PRESIDENTIAL] = new PresidentialPardonForm("");
}

Intern::~Intern( void ) {
    for (int idx = 0; idx < 3; idx++) {
        delete (forms[idx]);
    }
}

Intern::Intern( const Intern& ref ) {
    forms[SHRUBBERY] = new ShrubberyCreationForm(ref.forms[SHRUBBERY]->getName());
    forms[ROBOTOMY] = new RobotomyRequestForm(ref.forms[ROBOTOMY]->getName());
    forms[PRESIDENTIAL] = new PresidentialPardonForm(ref.forms[PRESIDENTIAL]->getName());
}

Intern& Intern::operator=( const Intern& ref ) {
    if (this == &ref)
        return (*this);
    for (int idx = 0; idx < 3; idx++) {
        delete (forms[idx]);
    }
    forms[SHRUBBERY] = new ShrubberyCreationForm(ref.forms[SHRUBBERY]->getName());
    forms[ROBOTOMY] = new RobotomyRequestForm(ref.forms[ROBOTOMY]->getName());
    forms[PRESIDENTIAL] = new PresidentialPardonForm(ref.forms[PRESIDENTIAL]->getName());
    return (*this);
}

void    Intern::convertFormName( std::string& formName ) {
    int cutIdx;

    cutIdx = formName.find(' ');
    if (static_cast<unsigned long>(cutIdx) == std::string::npos)
        throw Intern::unknownNameException();
    formName = formName.substr(0, cutIdx);
    formName[0] = std::toupper(formName[0]);
}

const char* Intern::unknownNameException::what( void ) const throw() {
    return ("this form name is unknown");
}

Form*  Intern::makeForm(std::string formName, std::string target) {
    convertFormName(formName);

    for (int idx = 0; idx < 3; idx++) {
        switch (idx) {
            case SHRUBBERY:
                if (forms[SHRUBBERY]->getName().find(formName) == 0) {
                    dynamic_cast<ShrubberyCreationForm*>(forms[SHRUBBERY])->setTarget(target);
                    return (forms[SHRUBBERY]);
                }
            case ROBOTOMY:
                if (forms[ROBOTOMY]->getName().find(formName) == 0) {
                    dynamic_cast<RobotomyRequestForm*>(forms[ROBOTOMY])->setTarget(target);
                    return (forms[ROBOTOMY]);
                }
            case PRESIDENTIAL:
                if (forms[PRESIDENTIAL]->getName().find(formName) == 0) {
                    dynamic_cast<PresidentialPardonForm*>(forms[PRESIDENTIAL])->setTarget(target);
                    return (forms[PRESIDENTIAL]);
                }
        }
    }
    throw Intern::unknownNameException();
}