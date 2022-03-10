#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
private:
    const std::string   name;
    int                 grade;
    std::string message;
    Bureaucrat( void );

public:
    Bureaucrat( std::string _name, int _grade );
    ~Bureaucrat( void );
    Bureaucrat( const Bureaucrat& ref );
    Bureaucrat& operator=( const Bureaucrat& ref );
    std::string getName( void ) const;
    int         getGrade( void ) const;
    Bureaucrat  operator++( int );
    Bureaucrat  operator--( int );
    class gradeTooHighException: public std::exception {
        public:
            const char* what( void ) const throw();
    };
    class gradeTooLowException: public std::exception {
        public:
            const char* what( void ) const throw();
    };
};

std::ostream&   operator<<( std::ostream& os, const Bureaucrat& ref );

#endif