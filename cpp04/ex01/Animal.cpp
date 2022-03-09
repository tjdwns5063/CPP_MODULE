#include "Animal.hpp"

Animal::Animal( void ) {
    type = "Animal";
    std::cout << "Animal is constructed\n";
}

Animal::~Animal( void ) {
    std::cout << "Animal is destructed\n";
}

Animal::Animal( const Animal& ref ) {
    std::cout << "Animal is copied\n";
    *this = ref;
}

Animal& Animal::operator=( const Animal& ref ) {
    type = ref.type;
    return (*this);
}

void    Animal::makeSound( void ) const {
    std::cout << "Ambiguos Sound...\n";
}

std::string Animal::getType( void ) const {
    return (type);
}

void        Animal::setType( std::string type ) {
    this->type = type;
}