#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Form;

class Bureaucrat {
private:
    const std::string   name;
    int                 grade;
    std::string message;

public:
    Bureaucrat( void );
    Bureaucrat( std::string _name, int _grade );
    ~Bureaucrat( void );
    Bureaucrat( const Bureaucrat& ref );
    Bureaucrat& operator=( const Bureaucrat& ref );
    std::string getName( void ) const;
    int         getGrade( void ) const;
    Bureaucrat  operator++( int );
    Bureaucrat  operator--( int );
    Bureaucrat  operator++( void );
    Bureaucrat  operator--( void );
    void        signForm( Form& form );
    class GradeTooHighException: public std::exception {
        public:
            const char* what( void ) const throw();
    };
    class GradeTooLowException: public std::exception {
        public:
            const char* what( void ) const throw();
    };
};

std::ostream&   operator<<( std::ostream& os, const Bureaucrat& ref );

#endif