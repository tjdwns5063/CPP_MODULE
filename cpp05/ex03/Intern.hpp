#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>

class Form;

class Intern {
private:
    Form* forms[3];
    enum formsEnum {
        SHRUBBERY,
        ROBOTOMY,
        PRESIDENTIAL,
    };
    void    convertFormName( std::string& formName );

public:
    Intern( void );
    ~Intern( void );
    Intern( const Intern& ref );
    Intern& operator=( const Intern& ref );
    Form*  makeForm(std::string formName, std::string target);
    class unknownNameException: public std::exception {
        public:
            const char* what( void ) const throw();
    };
};

# endif