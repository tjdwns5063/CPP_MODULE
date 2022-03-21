#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>

class Form;

class Intern {
private:
    std::string* forms[3];
    enum formsEnum {
        SHRUBBERY, 
        ROBOTOMY, 
        PRESIDENTIAL, 
    };

public:
    Intern( void );
    ~Intern( void );
    Intern( const Intern& ref );
    Intern& operator=( const Intern& ref );
    Form*  makeForm(std::string formName, std::string target);
    class UnknownNameException: public std::exception {
        public:
            const char* what( void ) const throw();
    };
};

# endif