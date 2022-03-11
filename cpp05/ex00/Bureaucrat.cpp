#include "Bureaucrat.hpp"

const char* Bureaucrat::gradeTooHighException::what( void ) const throw() {
    return ("grade is too high\n");
}

const char* Bureaucrat::gradeTooLowException::what( void ) const throw() {
    return ("grade is too low\n");
}

Bureaucrat::Bureaucrat( void ): name("") {
    grade = 0;
}

Bureaucrat::Bureaucrat( std::string _name, int _grade ): name(_name) {
    if (_grade < 1) throw gradeTooHighException();
    else if (_grade > 150) throw gradeTooLowException();
    grade = _grade;
}

Bureaucrat::~Bureaucrat( void ) {

}

Bureaucrat::Bureaucrat( const Bureaucrat& ref ): name(ref.name), grade(ref.grade) {

}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& ref ) {
    const_cast<std::string&>(name) = ref.name;
    const_cast<int&>(grade) = ref.grade;
    return (*this);
}

Bureaucrat  Bureaucrat::operator++( int ) {
    if (grade - 1 < 1) throw gradeTooHighException();
    Bureaucrat  temp = *this;
    grade--;
    return (temp);
}

Bureaucrat  Bureaucrat::operator--( int ) {
    if (grade + 1 > 150) throw gradeTooLowException();
    Bureaucrat  temp = *this;
    grade++;
    return (temp);
}

Bureaucrat  Bureaucrat::operator++( void ) {
    if (grade - 1 < 1) throw gradeTooHighException();
    grade--;
    return (*this);
}

Bureaucrat  Bureaucrat::operator--( void ) {
    if (grade + 1 > 150) throw gradeTooLowException();
    grade++;
    return (*this);
}

std::string Bureaucrat::getName( void ) const {
    return (name);
}

int Bureaucrat::getGrade( void ) const {
    return (grade);
}

std::ostream&   operator<<( std::ostream& os, const Bureaucrat& ref ) {
    std::cout << "<" << ref.getName() << ">, bureacrat grade <" << ref.getGrade() << ">";
    return (os);
}