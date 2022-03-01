#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name ) {
    const_cast<std::string&>(className) = "ScavTrap";
    const_cast<int&>(maxHitPoint) = 100;
    const_cast<int&>(maxEnergyPoint) = 50;
    const_cast<int&>(attackDamage) = 20;
    hitPoint = maxHitPoint;
    energyPoint = maxEnergyPoint;
    guardMode = false;
    std::cout << "ScavTrap " << name << " is constructed\n";
}

ScavTrap::~ScavTrap( void ) {
    std::cout << "ScavTrap " << name << " is destructed\n";
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
        std::cout << "ScavTrap " << name << " is Guard Mode... then, damage " << amount << " is Guarded\n";
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
    std::cout << "ScavTrap " << name << " transform Guard Mode\n";
}