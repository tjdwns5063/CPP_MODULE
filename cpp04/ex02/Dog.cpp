#include "Dog.hpp"

Dog::Dog( void ) : Animal() {
    type = "Dog";
    try {
		brain = new Brain();
	} catch (std::bad_alloc& err) {
		std::cout << "Allocate Error!\n";
	}
    std::cout << "Dog is constructed\n";
}

Dog::Dog( std::string idea ) : Animal() {
    type = "Dog";
    try {
		brain = new Brain(idea);
	} catch (std::bad_alloc& err) {
		std::cout << "Allocate Error!\n";
	}
    std::cout << "Dog is constructed\n";
}

Dog::~Dog( void ) {
    std::cout <<  "Dog is destructed\n";
    delete (brain);
}

Dog::Dog( const Dog& ref ) {
    std::cout << "Dog is copied\n";
    type = ref.type;
    try {
		brain = new Brain(ref.brain->getIdea());
	} catch (std::bad_alloc& err) {
		std::cout << "Allocate Error!\n";
	}
}

Dog& Dog::operator=( const Dog& ref ) {
    if (this == &ref)
        return (*this);
    type = ref.type;
    if (brain) {
        delete (brain);
        brain = NULL;
    }
    try {
		brain = new Brain(ref.brain->getIdea());
	} catch (std::bad_alloc& err) {
		std::cout << "Allocate Error!\n";
	}
    return (*this);
}

void    Dog::makeSound( void ) const {
    std::cout << "bowwow!! bowwow!!\n";
}

std::string Dog::getType( void ) const {
    return (type);
}

void        Dog::setType( std::string type ) {
    this->type = type;
}

void    Dog::printBrain( void ) {
    brain->printIdeas();
}

void    Dog::setBrain( std::string idea ) {
    brain->setIdeas(idea);
}