#include "WrongDog.hpp"

WrongDog::WrongDog( void ) : Animal() {
    type = "WrongDog";
    try {
		brain = new Brain();
	} catch (std::bad_alloc& err) {
		std::cout << "Allocate Error!\n";
	}
    std::cout << "WrongDog is constructed\n";
}

WrongDog::WrongDog( std::string idea ) : Animal() {
    type = "WrongDog";
    try {
		brain = new Brain(idea);
	} catch (std::bad_alloc& err) {
		std::cout << "Allocate Error!\n";
	}
    std::cout << "WrongDog is constructed\n";
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
    brain = ref.brain;
    return (*this);
}

void    WrongDog::makeSound( void ) const {
    std::cout << "meow!! meow!!\n";
}

std::string WrongDog::getType( void ) const {
    return (type);
}

void    WrongDog::printBrain( void ) {
    brain->printIdeas();
}

void    WrongDog::setBrain( std::string idea ) {
    brain->setIdeas(idea);
}

void    WrongDog::deleteBrain( void ) {
    delete (brain);
}