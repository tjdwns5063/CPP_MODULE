#include "Zombie.hpp"

Zombie*	newZombie( std::string name ) {
	std::cout << "New ";
	Zombie*	zom = new Zombie(name);
	return (zom);
}