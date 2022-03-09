#include "Cat.hpp"

Cat::Cat( void ) : Animal() {
    type = "Cat";
    try {
		brain = new Brain();
	} catch (std::bad_alloc& err) {
		std::cout << "Allocate Error!\n";
	}
    std::cout << "Cat is constructed\n";
}

Cat::Cat( std::string idea ) : Animal() {
    type = "Cat";
    try {
		brain = new Brain(idea);
	} catch (std::bad_alloc& err) {
		std::cout << "Allocate Error!\n";
	}
    std::cout << "Cat is constructed\n";
}

Cat::~Cat( void ) {
    std::cout <<  "Cat is destructed\n";
    delete (brain);
}

Cat::Cat( const Cat& ref ) {
    std::cout << "Cat is copied\n";
    type = ref.type;
    try {
		brain = new Brain(ref.brain->getIdea());
	} catch (std::bad_alloc& err) {
		std::cout << "Allocate Error!\n";
	}
}

Cat& Cat::operator=( const Cat& ref ) {
    if (this == &ref)
        return (*this);
    type = ref.type;
    if (brain) {
        delete (brain);
        brain = NULL;
    }
    brain = new Brain(ref.brain->getIdea());
    try {
		brain = new Brain(ref.brain->getIdea());
	} catch (std::bad_alloc& err) {
		std::cout << "Allocate Error!\n";
	}
    return (*this);
}

void    Cat::makeSound( void ) const {
    std::cout << "meow!! meow!!\n";
}

std::string Cat::getType( void ) const {
    return (type);
}

void    Cat::printBrain( void ) {
    brain->printIdeas();
}

void    Cat::setBrain( std::string idea ) {
    brain->setIdeas(idea);
}