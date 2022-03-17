#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( std::string _target ): Form("ShrubberyCreationForm", 137, 145) {
    target = _target;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {

}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& ref ): Form(ref.getName(), ref.getExecGrade(), ref.getSignedGrade()) {
    this->setSign(ref.getSign());
    target = ref.target;
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=( const ShrubberyCreationForm& ref ) {
    this->setName(ref.getName());
    this->setExecGrade(ref.getExecGrade());
    this->setSignedGrade(ref.getSignedGrade());
    this->setSign(ref.getSign());
    target = ref.getTarget();
    return (*this);
}

std::string ShrubberyCreationForm::getTarget( void ) const {
    return (target);
}

void    ShrubberyCreationForm::setTarget( std::string _target ) {
    target = _target;
}

void	ShrubberyCreationForm::execute( Bureaucrat const& executor ) const {
    std::ofstream writer;
    std::string tree;

    if (this->getSign() == false)
        throw Form::SignedException();
    if (executor.getGrade() >= this->getExecGrade())
        throw Form::GradeCompareException();

    tree = "       ###\n      #o###\n    #####o###\n   #o#\\#|#/###\n    ###\\|/#o#\n     # }|{  #\n       }|{\n";
    writer.open(target + "__shrubbery", std::ofstream::out | std::ofstream::trunc);
    if (writer.is_open()) {
        writer << tree;
        writer.close();
    }
    std::cout << "Shrubbery is created\n";
}