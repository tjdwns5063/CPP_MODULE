#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal() {
    type = "WrongCat";
    std::cout << "WrongCat is constructed\n";
}

WrongCat::~WrongCat( void ) {
    std::cout <<  "WrongCat is destructed\n";
}

WrongCat::WrongCat( const WrongCat& ref ) {
    std::cout << "WrongCat is copied\n";
    *this = ref;
}

WrongCat& WrongCat::operator=( const WrongCat& ref ) {
    type = ref.type;
    return (*this);
}

void    WrongCat::makeSound( void ) const {
    std::cout << "meow!! meow!!\n";
}

std::string WrongCat::getType( void ) const {
    return (type);
}