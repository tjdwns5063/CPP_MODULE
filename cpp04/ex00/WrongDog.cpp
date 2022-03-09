#include "WrongDog.hpp"

WrongDog::WrongDog( void ) : WrongAnimal() {
    type = "Dog";
    std::cout << "Dog is constructed\n";
}

WrongDog::~WrongDog( void ) {
    std::cout <<  "WrongDog is destructed\n";
}

WrongDog::WrongDog( const WrongDog& ref ) {
    std::cout << "WrongDog is copied\n";
    *this = ref;
}

WrongDog& WrongDog::operator=( const WrongDog& ref ) {
    type = ref.type;
    return (*this);
}

void    WrongDog::makeSound( void ) const {
    std::cout << "bowwow!! bowwow!!\n";
}

std::string WrongDog::getType( void ) const {
    return (type);
}