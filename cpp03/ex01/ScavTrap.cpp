#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name ) {
    const_cast<int&>(maxHitPoint) = 100;
    const_cast<int&>(maxEnergyPoint) = 50;
    const_cast<int&>(attackDamage) = 20;
    hitPoint = maxHitPoint;
    energyPoint = maxEnergyPoint;
    std::cout << "ScavTrap " << name << " is constructed\n";
}

ScavTrap::~ScavTrap( void ) {
    std::cout << "ScavTrap " << name << " is destructed\n";
}

ScavTrap::ScavTrap( const ScavTrap& ref)  : ClapTrap( ref.name ) {
    *this = ref;
}

ScavTrap&   ScavTrap::operator=( const ScavTrap& ref ) {
    name = ref.name;
    const_cast<int&>(maxHitPoint) = ref.maxHitPoint;
    const_cast<int&>(maxEnergyPoint) = ref.maxEnergyPoint;
    const_cast<int&>(attackDamage) = ref.attackDamage;
    hitPoint = ref.hitPoint;
    energyPoint = ref.energyPoint;
    return (*this);
}

void    ScavTrap::attack( std::string const& target ) {
    ClapTrap::attack(target);
}

void    ScavTrap::takeDamage( unsigned int amount ) {
    if (guardMode == true) {
        std::cout << "ScavTrap " << name << " is Guard Mode... then, damage " << amount << " is Guarded\n";
        return ;
    }
    ClapTrap::takeDamage(amount);
}

void    ScavTrap::beRepaired( unsigned int amount ) {
    ClapTrap::beRepaired(amount);
}

int     ScavTrap::getHitPoint( void ) const {
    return (ClapTrap::getHitPoint());
}

int     ScavTrap::getEnergyPoint( void ) const {
    return (ClapTrap::getEnergyPoint());
}

int     ScavTrap::getAttackDamage( void ) const {
    return (ClapTrap::getAttackDamage());
}

void    ScavTrap::guardGate( void ) {
    guardMode = true;
    std::cout << "ScavTrap " << name << " is Guard Mode\n";
}