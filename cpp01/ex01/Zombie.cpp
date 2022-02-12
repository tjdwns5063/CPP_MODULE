#include "Zombie.hpp"

void	Zombie::announce( void ) {
	std::cout << this->name << " BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie( void ) {
	this->name = "";
}

Zombie::Zombie( std::string name ) {
	this->name = name;
	announce();
}

void	Zombie::setName( std::string name ) {
	this->name = name;
	announce();
}

Zombie::~Zombie( void ) {
	std::cout << this->name << " is Dead...\n";
}