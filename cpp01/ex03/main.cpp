#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		std::cout << '\n';
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
		std::cout << '\n';
	}
	{
		std::cout << '\n';
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		std::cout << '\n';
		jim.setWeapon(&club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		std::cout << '\n';
	}
}