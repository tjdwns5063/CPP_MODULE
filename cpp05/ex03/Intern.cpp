#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <sstream>

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
    *this = ref;
}

Intern& Intern::operator=( const Intern& ref ) {
    if (this == &ref)
        return (*this);
    for (int idx = 0; idx < 3; idx++) {
        if (forms[idx])
            delete (forms[idx]);
    }
    forms[SHRUBBERY] = new ShrubberyCreationForm("");
    forms[ROBOTOMY] = new RobotomyRequestForm("");
    forms[PRESIDENTIAL] = new PresidentialPardonForm("");
    return (*this);
}

const char* Intern::UnknownNameException::what( void ) const throw() {
    return ("this form name is unknown");
}

void    Intern::convertFormName( std::string& formName ) {
    std::stringstream ss(formName);
    std::string name;
    std::string order;

    ss >> name;
    ss >> order;
    name[0] = std::toupper(name[0]);
    order[0] = std::toupper(order[0]);
    name += order;
    formName = name;
}

bool    Intern::checkFormName( std::string& formName, const std::string& compareName ) {
    std::string compare = compareName.substr(0, compareName.length() - 4);

    if (formName == compare) {
        return (true);
    }
    return (false);
}

Form*  Intern::makeForm(std::string formName, std::string target) {
    convertFormName(formName);
    for (int idx = 0; idx < 3; idx++) {
        switch (idx) {
            case SHRUBBERY:
                if (checkFormName(formName, forms[SHRUBBERY]->getName())) {
                    std::cout << "Intern creates " << forms[SHRUBBERY]->getName() << '\n';
                    return (new ShrubberyCreationForm(target));
                }
            case ROBOTOMY:
                if (checkFormName(formName, forms[ROBOTOMY]->getName())) {
                    std::cout << "Intern creates " << forms[ROBOTOMY]->getName() << '\n';
                    return (new RobotomyRequestForm(target));
                }
            case PRESIDENTIAL:
                if (checkFormName(formName, forms[PRESIDENTIAL]->getName())) {
                    std::cout << "Intern creates " << forms[PRESIDENTIAL]->getName() << '\n';
                    return (new PresidentialPardonForm(target));
                }
        }
    }
    throw Intern::UnknownNameException();
}