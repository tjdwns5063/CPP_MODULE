#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) {
    type = "WrongAnimal";
    std::cout << "WrongAnimal is constructed\n";
}

WrongAnimal::~WrongAnimal( void ) {
    std::cout << "WrongAnimal is destructed\n";
}

WrongAnimal::WrongAnimal( const WrongAnimal& ref ) {
    std::cout << "WrongAnimal is copied\n";
    *this = ref;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& ref ) {
    type = ref.type;
    return (*this);
}

void    WrongAnimal::makeSound( void ) const {
    std::cout << "Ambiguos Sound...\n";
}

std::string WrongAnimal::getType( void ) const {
    return (type);
}

void        WrongAnimal::setType( std::string type ) {
    this->type = type;
}