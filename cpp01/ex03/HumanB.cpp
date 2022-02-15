#include "HumanB.hpp"

HumanB::HumanB( std::string name ) {
	this->name = name;
	std::cout << "Human B is Created\n";
}

HumanB::HumanB( void ) {
	this->name = "";
	std::cout << "Human B is Created\n";
}

HumanB::~HumanB( void ) {
	std::cout << "Human B is Destroyed\n";
}

void	HumanB::setWeapon( Weapon* weapon ) {
	this->weapon = weapon;
}

void	HumanB::attack( void ) {
	
	std::cout << this->name <<  " attacks with his " << (*this->weapon).getType() << '\n';
}