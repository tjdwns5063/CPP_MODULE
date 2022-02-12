#include "Zombie.hpp"

int	main(void) {
	Zombie	zom = Zombie("Tom");
	Zombie*	newZom = newZombie("Tam");
	randomChump("Tim");
	std::cout << "New";
	delete (newZom);
}