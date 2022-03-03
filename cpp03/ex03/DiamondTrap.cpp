#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string _name ) : ClapTrap(_name + "_clap_name"), ScavTrap(_name), FragTrap(_name) {
	const_cast<std::string&>(className) = "Diamond Trap";
	const_cast<int&>(maxHitPoint) = 100;
	const_cast<int&>(maxEnergyPoint) = 50;
	const_cast<int&>(attackDamage) = 30;
	name = _name;
	hitPoint = maxHitPoint;
	energyPoint = maxEnergyPoint;
	std::cout << className << " " << name << " is constructed\n";
}

DiamondTrap::~DiamondTrap( void ) {
    std::cout << className << " " << name << " is destructed\n";
}

DiamondTrap::DiamondTrap( const DiamondTrap& ref ) : ClapTrap(ref.name + "_clap_name"), ScavTrap(ref.name), FragTrap(ref.name) {
    *this = ref;
}

DiamondTrap&    DiamondTrap::operator=( const DiamondTrap& ref ) {
	const_cast<std::string&>(className) = ref.className;
	const_cast<int&>(maxHitPoint) = ref.maxHitPoint;
	const_cast<int&>(maxEnergyPoint) = ref.maxEnergyPoint;
	const_cast<int&>(attackDamage) = ref.attackDamage;
	name = ref.name;
	hitPoint = maxHitPoint;
	energyPoint = maxEnergyPoint;
    return (*this);
}

std::string     DiamondTrap::getName( void ) const {
	return (name);
}

void            DiamondTrap::attack( std::string const& target ) {
	ScavTrap::attack(target);
}

void            DiamondTrap::whoAmI( void ) {
	std::cout << ClapTrap::getName() << '\n';
}

std::ostream&   operator<<( std::ostream& os, const DiamondTrap& diamondTrap ) {
    std::cout << "Class Name : " << diamondTrap.getClassName() << '\n';
    std::cout << "Name : " << diamondTrap.getName() << '\n';
    std::cout << "Hit Point : " << diamondTrap.getHitPoint() << '\n';
    std::cout << "Energy Point : " << diamondTrap.getEnergyPoint() << '\n';
    std::cout << "Attack Point : " << diamondTrap.getAttackDamage() << '\n';
    return (os);
}