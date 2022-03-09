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