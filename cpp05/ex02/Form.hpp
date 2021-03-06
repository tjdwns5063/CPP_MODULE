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
	Form( void );

public:
	virtual ~Form( void );
	Form( const Form& ref );
	Form&	operator=( const Form& ref );
	Form( std::string name, int execGrade, int signedGrade );
	std::string	getName( void ) const;
	void	setName( std::string _name );
	int	getExecGrade( void ) const;
	void	setExecGrade( int _execGrade );
	int	getSignedGrade( void ) const;
	void	setSignedGrade( int _signedGrade );
	bool	getSign( void ) const;
	void	setSign( bool _sign );
	void	beSigned( Bureaucrat& bureaucrat );
	class GradeTooHighException: public std::exception {
        public:
            const char* what( void ) const throw();
    };
    class GradeTooLowException: public std::exception {
        public:
            const char* what( void ) const throw();
    };
    class GradeCompareException: public std::exception {
        public:
            const char* what( void ) const throw();
    };
	class SignedException: public std::exception {
        public:
            const char* what( void ) const throw();
    };
	virtual void	execute( Bureaucrat const& executor ) const = 0;
};

std::ostream&	operator<<( std::ostream& os, const Form& form );

# endif