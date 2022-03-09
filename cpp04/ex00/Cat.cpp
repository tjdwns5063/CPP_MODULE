#include "Cat.hpp"

Cat::Cat( void ) : Animal() {
    type = "Cat";
    std::cout << "Cat is constructed\n";
}

Cat::~Cat( void ) {
    std::cout <<  "Cat is destructed\n";
}

Cat::Cat( const Cat& ref ) {
    std::cout << "Cat is copied\n";
    *this = ref;
}

Cat& Cat::operator=( const Cat& ref ) {
    type = ref.type;
    return (*this);
}

void    Cat::makeSound( void ) const {
    std::cout << "meow!! meow!!\n";
}

std::string Cat::getType( void ) const {
    return (type);
}