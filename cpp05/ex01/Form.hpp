#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {
private:
	const std::string name;
	const int execGrade;
	const int signedGrade;
	bool sign;

public:
	Form( void );
	~Form( void );
	Form( const Form& ref );
	Form&	operator=( const Form& ref );
	Form( std::string name, int execGrade, int signedGrade );
	std::string	getName( void ) const;
	int	getExecGrade( void ) const;
	int	getSignedGrade( void ) const;
	bool	getSign( void ) const;
	void	beSigned( Bureaucrat& bureaucrat );

};

# endif