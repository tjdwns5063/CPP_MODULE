#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : weapon(weapon) {
	this->name = name;
	std::cout << "Human A is Created\n";
}

HumanA::~HumanA( void ) {
	std::cout << "Human A is Destroyed\n";
}

void	HumanA::attack( void ) {
	std::cout << this->name <<  " attacks with his " << this->weapon.getType() << '\n';
}