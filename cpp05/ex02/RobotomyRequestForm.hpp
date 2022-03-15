#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm: public Form {
private:
    std::string target;
    RobotomyRequestForm( void );

public:
    RobotomyRequestForm( std::string _target );
    ~RobotomyRequestForm( void );
    RobotomyRequestForm( const RobotomyRequestForm& ref );
    RobotomyRequestForm& operator=( const RobotomyRequestForm& ref );
    std::string getTarget( void ) const;
    void    setTarget( std::string _target );
    void	execute( Bureaucrat const& executor ) const;
};

# endif