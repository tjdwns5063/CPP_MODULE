#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm: public Form
{
private:
    std::string target;
    ShrubberyCreationForm( void );
public:
    ShrubberyCreationForm( std::string _target );
    ~ShrubberyCreationForm( void );
    ShrubberyCreationForm( const ShrubberyCreationForm& ref );
    ShrubberyCreationForm&  operator=( const ShrubberyCreationForm& ref );
    std::string getTarget( void ) const;
    void    setTarget( std::string _target );
    void	execute( Bureaucrat const& executor ) const;
};

# endif