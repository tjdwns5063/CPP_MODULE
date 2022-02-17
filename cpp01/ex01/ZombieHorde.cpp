#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name) {
	Zombie*	zombieHorde;

	try {
		zombieHorde = new Zombie[N];
	} catch (std::bad_alloc& err) {
		std::cout << "Allocate Error!\n";
		return (NULL);
	}
	for (int i = 0; i < N; i++) {
		std::cout << "[ " << i << " ] ";
		zombieHorde[i].setName(name);
	}
	return (zombieHorde);
}