#include "Cat.hpp"

Cat::Cat( void ) : Animal() {
    type = "Cat";
    std::cout << "Cat is created\n";
}

Cat::~Cat( void ) {
    std::cout <<  "Cat is destructed\n";
}

Cat::Cat( const Cat& ref ) {
    *this = ref;
}

Cat& Cat::operator=( const Cat& ref ) {
    type = ref.type;
    return (*this);
}

void    Cat::makeSound( void ) const {
    std::cout << "meow!! meow!!\n";
}