#include "Weapon.hpp"

Weapon::Weapon( void ) {
	this->type = "";
	std::cout << "Weapon is Created\n";
}

Weapon::~Weapon( void ) {
	std::cout << "Weapon is Destroyed\n";
}

Weapon::Weapon( std::string type ) {
	this->type = type;
	std::cout << type + " Weapon is Created\n";
}

const std::string&	Weapon::getType( void ) {
	return (this->type);
}

void	Weapon::setType( std::string type ) {
	this->type = type;
}