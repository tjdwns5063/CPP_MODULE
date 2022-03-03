#include "Animal.hpp"

Animal::Animal( void ) {
    type = "Animal";
    std::cout << "Animal is created\n";
}

Animal::~Animal( void ) {
    std::cout << "Animal is destructed\n";
}

Animal::Animal( const Animal& ref ) {
    *this = ref;
}

Animal& Animal::operator=( const Animal& ref ) {
    type = ref.type;
    return (*this);
}

void    Animal::makeSound( void ) const {
    std::cout << "Ambiguos Sound...\n";
}