#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( std::string _name, int _execGrade, int _signedGrade ):\
	name(_name), execGrade(_execGrade), signedGrade(_signedGrade) {
		if (execGrade > 150 || signedGrade > 150)
			throw Form::GradeTooLowException();
		else if (execGrade < 1 || signedGrade < 1)
			throw Form::GradeTooHighException();
		else {
			sign = false;
		}
	}

Form::Form( const Form& ref ):\
	name(ref.name), execGrade(ref.execGrade), signedGrade(ref.signedGrade) {
		if (execGrade > 150 || signedGrade > 150)
			throw Form::GradeTooLowException();
		else if (execGrade < 1 || signedGrade < 1)
			throw Form::GradeTooHighException();
		else 
		 	sign = ref.sign;
	}

Form&	Form::operator=( const Form& ref ) {
	if (execGrade > 150 || signedGrade > 150)
		throw Form::GradeTooLowException();
	else if (execGrade < 1 || signedGrade < 1)
		throw Form::GradeTooHighException();
	else {
		const_cast<std::string&>(name) = ref.name;
		const_cast<int&>(execGrade) = ref.execGrade;
		const_cast<int&>(signedGrade) = ref.signedGrade;
		sign = ref.sign;
	}
	return (*this);
}

Form::~Form( void ) {

}

const char* Form::GradeTooHighException::what( void ) const throw() {
    return ("grade is too high");
}

const char* Form::GradeTooLowException::what( void ) const throw() {
    return ("grade is too low");
}

const char*	Form::GradeCompareException::what( void ) const throw() {
	return ("bureacrat's grade is lower than form's grade");
}

void	Form::beSigned( Bureaucrat& bureaucrat ) {
	if (bureaucrat.getGrade() <= signedGrade)
		sign = true;
	else
		throw Form::GradeCompareException();
}

std::string	Form::getName( void ) const {
	return (name);
}

void	Form::setName( std::string _name ) {
	const_cast<std::string&>(name) = _name;
}

int	Form::getExecGrade( void ) const {
	return (execGrade);
}

void	Form::setExecGrade( int _execGrade ) {
	const_cast<int&>(execGrade) = _execGrade;
}

int	Form::getSignedGrade( void ) const {
	return (signedGrade);
}

void	Form::setSignedGrade( int _signedGrade ) {
	const_cast<int&>(signedGrade) = _signedGrade;
}

bool	Form::getSign( void ) const {
	return (sign);
}

void	Form::setSign( bool _sign ) {
	sign = _sign;
}

std::ostream&	operator<<( std::ostream& os, const Form& form ) {
	std::cout << "Name: " << form.getName() << '\n';
	std::cout << "SignedGrade: " << form.getSignedGrade() << '\n';
	std::cout << "ExecGrade: " << form.getExecGrade() << '\n';
	std::cout << "Sign: " << form.getSign();
	return (os); 
}