#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap( name ) {
	const_cast<std::string&>(className) = "FragTrap";
	const_cast<int&>(maxHitPoint) = 100;
	const_cast<int&>(maxEnergyPoint) = 100;
	const_cast<int&>(attackDamage) = 30;
	hitPoint = maxHitPoint;
	energyPoint = maxEnergyPoint;
	std::cout << "FragTrap " << name << " constructed\n";
}
FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap " << name << " destructed\n";
}

FragTrap::FragTrap( const FragTrap& ref ): ClapTrap(ref.name) {
	*this = ref;
}

FragTrap&	FragTrap::operator=( const FragTrap& ref ) {
	const_cast<std::string&>(className) = "FragTrap";
	const_cast<int&>(maxHitPoint) = ref.maxHitPoint;
	const_cast<int&>(maxEnergyPoint) = ref.maxEnergyPoint;
	const_cast<int&>(attackDamage) = ref.attackDamage;
	name = ref.name;
	hitPoint = ref.maxHitPoint;
	energyPoint = ref.maxEnergyPoint;
	return (*this);
}

void	FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap is highFives each other....\n";
}