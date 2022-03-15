#include "Bureaucrat.hpp"
#include "Form.hpp"

void    Bureaucrat::signForm( Form& form ) {
    try {
        form.beSigned(*this);
        std::cout << name << " signs " << form.getName() << '\n';
    } catch (std::exception& err) {
        std::cout << name << " cannot sign " << form.getName() << " because " << err.what() << '\n';
    }
}

const char* Bureaucrat::GradeTooHighException::what( void ) const throw() {
    return ("grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what( void ) const throw() {
    return ("grade is too low");
}

Bureaucrat::Bureaucrat( void ): name("") {
    grade = 0;
}

Bureaucrat::Bureaucrat( std::string _name, int _grade ): name(_name) {
    if (_grade < 1) throw GradeTooHighException();
    else if (_grade > 150) throw GradeTooLowException();
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
    if (grade - 1 < 1) throw GradeTooHighException();
    Bureaucrat  temp = *this;
    grade--;
    return (temp);
}

Bureaucrat  Bureaucrat::operator--( int ) {
    if (grade + 1 > 150) throw GradeTooLowException();
    Bureaucrat  temp = *this;
    grade++;
    return (temp);
}

Bureaucrat  Bureaucrat::operator++( void ) {
    if (grade - 1 < 1) throw GradeTooHighException();
    grade--;
    return (*this);
}

Bureaucrat  Bureaucrat::operator--( void ) {
    if (grade + 1 > 150) throw GradeTooLowException();
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
    std::cout << ref.getName() << ", bureacrat grade " << ref.getGrade();
    return (os);
}