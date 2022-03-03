#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string _name ) : ClapTrap( _name ) {
    const_cast<std::string&>(className) = "ScavTrap";
    const_cast<int&>(maxHitPoint) = 100;
    const_cast<int&>(maxEnergyPoint) = 50;
    const_cast<int&>(attackDamage) = 20;
    hitPoint = maxHitPoint;
    energyPoint = maxEnergyPoint;
    guardMode = false;
    std::cout << className << " " << name << " is constructed\n";
}

ScavTrap::~ScavTrap( void ) {
    const_cast<std::string&>(className) = "ScavTrap";
    std::cout << className << " " << name << " is destructed\n";
}

ScavTrap::ScavTrap( const ScavTrap& ref)  : ClapTrap( ref.name ) {
    *this = ref;
}

ScavTrap&   ScavTrap::operator=( const ScavTrap& ref ) {
    const_cast<std::string&>(className) = "ScavTrap";
    const_cast<int&>(maxHitPoint) = ref.maxHitPoint;
    const_cast<int&>(maxEnergyPoint) = ref.maxEnergyPoint;
    const_cast<int&>(attackDamage) = ref.attackDamage;
    name = ref.name;
    hitPoint = ref.hitPoint;
    energyPoint = ref.energyPoint;
    guardMode = ref.guardMode;
    return (*this);
}

void    ScavTrap::takeDamage( unsigned int amount ) {
    if (guardMode == true) {
        std::cout << className << " " << name << " is Guard Mode... then, damage " << amount << " is Guarded\n";
        guardMode = false;
        std::cout << "Guard Mode is Cleared...\n";
        return ;
    }
    std::cout << className << " " << name << " take " << amount << " damage\n";
    if ((hitPoint - amount) <= 0) {
        hitPoint = 0;
        return ;
    }
    hitPoint -= amount;
}

void    ScavTrap::guardGate( void ) {
    guardMode = true;
    std::cout << className << " " << name << " transform Guard Mode\n";
}

std::ostream&   operator<<(std::ostream& os, const ScavTrap& scavTrap) {
    std::cout << "Class Name : " << scavTrap.getClassName() << '\n';
    std::cout << "Name : " << scavTrap.getName() << '\n';
    std::cout << "Hit Point : " << scavTrap.getHitPoint() << '\n';
    std::cout << "Energy Point : " << scavTrap.getEnergyPoint() << '\n';
    std::cout << "Attack Point : " << scavTrap.getAttackDamage() << '\n';
    return (os);
}
