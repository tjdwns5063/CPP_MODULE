#include "Zombie.hpp"
#include <cstdlib>

void	randomChump( std::string name ) {
	int	random;

	srand(static_cast<unsigned int>(time(NULL)));
	random = rand();
	if (random % 2 == 0) {
		Zombie zom = Zombie(name);
	} else {
		Zombie* zom = newZombie(name);
		std::cout << "New ";
		delete (zom);
	}
	return ;
}