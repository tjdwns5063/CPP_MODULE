#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm: public Form {
private:
    std::string target;
    PresidentialPardonForm( void );
public:
    PresidentialPardonForm( std::string _target );
    ~PresidentialPardonForm( void );
    PresidentialPardonForm( const PresidentialPardonForm& ref );
    PresidentialPardonForm& operator=( const PresidentialPardonForm& ref );
    std::string getTarget( void ) const;
    void    setTarget( std::string _target );
    void	execute( Bureaucrat const& executor ) const;
};

# endif