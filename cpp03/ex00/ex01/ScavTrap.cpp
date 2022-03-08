#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name ) {
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

void    ScavTrap::attack( std::string const& target ) {
        std::cout << className << " " << name << " attack " << target << ", causing " << attackDamage << " points of damage!\n";
}

// void    ScavTrap::takeDamage( unsigned int amount ) {
//     int _amount = static_cast<int>(amount);

//     if (guardMode == true) {
//         std::cout << className << " " << name << " is Guard Mode... then, damage " << amount << " is Guarded\n";
//         guardMode = false;
//         std::cout << "Guard Mode is Cleared...\n";
//         return ;
//     } else if (hitPoint <= _amount) {
//             _amount = (hitPoint - _amount) + _amount;
//             hitPoint = 0;
//     } else {
//         hitPoint -= _amount;
//     }
//     std::cout << className << " " << name << " take " << _amount << " damage\n";
// }

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
