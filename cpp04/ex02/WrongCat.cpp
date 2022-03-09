#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : Animal() {
    type = "WrongCat";
    try {
		brain = new Brain();
	} catch (std::bad_alloc& err) {
		std::cout << "Allocate Error!\n";
	}
    std::cout << "WrongCat is constructed\n";
}

WrongCat::WrongCat( std::string idea ) : Animal() {
    type = "WrongCat";
    try {
		brain = new Brain(idea);
	} catch (std::bad_alloc& err) {
		std::cout << "Allocate Error!\n";
	}
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
    brain = ref.brain;
    return (*this);
}

void    WrongCat::makeSound( void ) const {
    std::cout << "meow!! meow!!\n";
}

std::string WrongCat::getType( void ) const {
    return (type);
}

void    WrongCat::printBrain( void ) {
    brain->printIdeas();
}

void    WrongCat::setBrain( std::string idea ) {
    brain->setIdeas(idea);
}

void    WrongCat::deleteBrain( void ) {
    delete (brain);
}