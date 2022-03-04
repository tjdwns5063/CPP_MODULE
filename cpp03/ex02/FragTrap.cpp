#include "FragTrap.hpp"

FragTrap::FragTrap( std::string _name ) : ClapTrap( _name ) {
	const_cast<std::string&>(className) = "FragTrap";
	const_cast<int&>(maxHitPoint) = 100;
	const_cast<int&>(maxEnergyPoint) = 100;
	const_cast<int&>(attackDamage) = 30;
	hitPoint = maxHitPoint;
	energyPoint = maxEnergyPoint;
	std::cout << className << " " << name << " is constructed\n";
}
FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap " << name << " is destructed\n";
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
	std::cout << className << " is highFives each other....\n";
}

std::ostream&	operator<<(std::ostream& os, const FragTrap& fragTrap) {
    std::cout << "Class Name : " << fragTrap.getClassName() << '\n';
    std::cout << "Name : " << fragTrap.getName() << '\n';
    std::cout << "Hit Point : " << fragTrap.getHitPoint() << '\n';
    std::cout << "Energy Point : " << fragTrap.getEnergyPoint() << '\n';
    std::cout << "Attack Point : " << fragTrap.getAttackDamage() << '\n';
    return (os);
}