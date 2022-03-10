#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string _name, int _grade ): std::exception(), name(_name), grade(_grade) {

}

Bureaucrat::~Bureaucrat( void ) throw() {

}

Bureaucrat::Bureaucrat( const Bureaucrat& ref ): std::exception(), name(ref.name), grade(ref.grade) {

}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& ref ) {
    const_cast<std::string&>(name) = ref.name;
    const_cast<int&>(grade) = ref.grade;
    return (*this);
}

std::string Bureaucrat::getName( void ) {
    if (grade < 1) throw gradeTooHighException();
    else if (grade > 150) throw gradeTooLowException();
    grade++;
    return (name);
}

int Bureaucrat::getGrade( void ) {
    if (grade < 1) throw gradeTooHighException();
    else if (grade > 150) throw gradeTooLowException();
    grade--;
    return (grade);
}

void Bureaucrat::gradeTooHighException( void ) {
    message = "grade is too high\n";
}

void Bureaucrat::gradeTooLowException( void ) {
    message = "grade is too low\n";
}

const char* Bureaucrat::what( void ) const throw() {
    return (message.c_str());
}