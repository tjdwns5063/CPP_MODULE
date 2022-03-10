#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat: std::exception {
private:
    const std::string   name;
    int                 grade;
    std::string message;
    Bureaucrat( void );

public:
    Bureaucrat( std::string _name, int _grade );
    ~Bureaucrat( void ) throw();
    Bureaucrat( const Bureaucrat& ref );
    Bureaucrat& operator=( const Bureaucrat& ref );
    std::string getName( void );
    int getGrade( void );
    void gradeTooHighException(void);
    void gradeTooLowException(void);
    const char* what( void ) const throw();
};

#endif