#include "Bureaucrat.hpp"

const char* Bureaucrat::gradeTooHighException::what( void ) const throw() {
    return ("grade is too high\n");
}

const char* Bureaucrat::gradeTooLowException::what( void ) const throw() {
    return ("grade is too low\n");
}

Bureaucrat::Bureaucrat( std::string _name, int _grade ): name(_name), grade(_grade) {

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
    Bureaucrat  temp = *this;
    grade++;
    if (grade > 150) {
        grade = 1;
    }
    return (temp);
}

Bureaucrat  Bureaucrat::operator--( int ) {
    Bureaucrat  temp = *this;
    grade--;
    return (temp);
}

std::string Bureaucrat::getName( void ) const {
    if (grade < 1) throw gradeTooHighException();
    else if (grade > 150) throw gradeTooLowException();
    return (name);
}

int Bureaucrat::getGrade( void ) const {
    if (grade < 1) throw gradeTooHighException();
    else if (grade > 150) throw gradeTooLowException();
    return (grade);
}

std::ostream&   operator<<( std::ostream& os, const Bureaucrat& ref ) {
    std::cout << "<" << ref.getName() << ">, bureacrat grade <" << ref.getGrade() << ">\n";
    return (os);
}