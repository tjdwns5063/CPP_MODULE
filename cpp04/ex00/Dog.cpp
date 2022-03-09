#include "Dog.hpp"

Dog::Dog( void ) : Animal() {
    type = "Dog";
    std::cout << "Dog is constructed\n";
}

Dog::~Dog( void ) {
    std::cout <<  "Dog is destructed\n";
}

Dog::Dog( const Dog& ref ) {
    std::cout << "Dog is copied\n";
    *this = ref;
}

Dog& Dog::operator=( const Dog& ref ) {
    type = ref.type;
    return (*this);
}

void    Dog::makeSound( void ) const {
    std::cout << "bowwow!! bowwow!!\n";
}

std::string Dog::getType( void ) const {
    return (type);
}