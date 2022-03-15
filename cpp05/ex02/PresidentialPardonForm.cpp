#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string _target ): Form("PresidentialPardonForm", 5, 25) {
    target = _target;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {

}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& ref ): Form(ref.getName(), ref.getExecGrade(), ref.getSignedGrade()) {
    target = ref.getTarget();
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& ref ) {
    this->setName(ref.getName());
    this->setExecGrade(ref.getExecGrade());
    this->setSignedGrade(ref.getSignedGrade());
    this->setSign(ref.getSign());
    target = ref.getTarget();
    return (*this);
}

std::string PresidentialPardonForm::getTarget( void ) const {
    return (target);
}

void    PresidentialPardonForm::setTarget( std::string _target ) {
    target = _target;
}

void	PresidentialPardonForm::execute( Bureaucrat const& executor ) const {
    if (this->getSign() == false)
        throw Form::SignedException();
    if (executor.getGrade() >= this->getExecGrade())
        throw Form::GradeCompareException();

    std::cout << target << " has been pardoned by Zafod Beeblebrox\n";
}