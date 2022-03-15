#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string _target ): Form("RobotomyRequestForm", 45, 72) {
    target = _target;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {

}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& ref ): Form(ref.getName(), ref.getExecGrade(), ref.getSignedGrade()) {
    target = ref.getTarget();
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& ref ) {
    this->setName(ref.getName());
    this->setExecGrade(ref.getExecGrade());
    this->setSignedGrade(ref.getSignedGrade());
    this->setSign(ref.getSign());
    target = ref.getTarget();
    return (*this);
}

std::string RobotomyRequestForm::getTarget( void ) const {
    return (target);
}

void    RobotomyRequestForm::setTarget( std::string _target ) {
    target = _target;
}

void	RobotomyRequestForm::execute( Bureaucrat const& executor ) const {
    int random;

    if (this->getSign() == false)
        throw Form::SignedException();
    if (executor.getGrade() >= this->getExecGrade())
        throw Form::GradeCompareException();

    std::srand(static_cast<unsigned int>(std::time(NULL)));
    random = rand();
    if (random % 2 == 0) {
        std::cout << "wiiiiing wiiiiing... " << target << " has been robotomized\n";
    } else {
        std::cout << "wiiiiing wiiiiing... robotomize is failed\n";
    }
}