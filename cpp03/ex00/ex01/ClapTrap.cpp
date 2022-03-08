#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string _name ) : className("ClapTrap"), maxHitPoint(10), maxEnergyPoint(10), attackDamage(0) {
    name = _name;
    hitPoint = maxHitPoint;
    energyPoint = maxEnergyPoint;
    std::cout << className << " " << name << " is constructed\n";
}

ClapTrap::~ClapTrap( void ) {
    std::cout << "ClapTrap " << name << " is destructed\n";
}

ClapTrap::ClapTrap( const ClapTrap& ref ) : maxHitPoint(10), maxEnergyPoint(10), attackDamage(0) {
    *this = ref;
}

ClapTrap&   ClapTrap::operator=( const ClapTrap& ref ) {
    const_cast<std::string&>(className) = ref.className;
    const_cast<int&>(maxHitPoint) = ref.maxHitPoint;
    const_cast<int&>(maxEnergyPoint) = ref.maxEnergyPoint;
    const_cast<int&>(attackDamage) = ref.attackDamage;
    name = ref.name;
    hitPoint = ref.hitPoint;
    energyPoint = ref.energyPoint;
    return (*this);
}

void    ClapTrap::attack( std::string const& target ) {
    std::cout << className << " " << name << " attack " << target << ", causing " << attackDamage << " points of damage!\n";
}

void    ClapTrap::takeDamage( unsigned int amount ) {
    int _amount = static_cast<int>(amount);

    if (hitPoint <= _amount) {
        _amount = (hitPoint - _amount) + _amount;
        hitPoint = 0;
    } else {
        hitPoint -= _amount;
    }
    std::cout << className << " " << name << " take " << _amount << " damage\n";
}

void    ClapTrap::beRepaired( unsigned int amount ) {
    int _amount = static_cast<int>(amount);

    if (hitPoint <= 0) {
        std::cout << className << " " << name << " is Already Dead...\n";
        return ;
    } else if ((hitPoint + _amount) >= maxHitPoint) {
        _amount = maxHitPoint - hitPoint;
        hitPoint = maxHitPoint;
    } else {
        hitPoint += _amount;
    }
    std::cout << className << " " << name << " repaired " << _amount << " damage\n";
}

int   ClapTrap::getHitPoint( void ) const {
    return (hitPoint);
}

int   ClapTrap::getEnergyPoint( void ) const {
    return (energyPoint);
}

int   ClapTrap::getAttackDamage( void ) const {
    return (attackDamage);
}

std::string ClapTrap::getName( void ) const {
    return (name);
}

std::string ClapTrap::getClassName( void ) const {
    return (className);
}

std::ostream&    operator<<(std::ostream& os, const ClapTrap& clapTrap) {
    std::cout << "Class Name : " << clapTrap.getClassName() << '\n';
    std::cout << "Name : " << clapTrap.getName() << '\n';
    std::cout << "Hit Point : " << clapTrap.getHitPoint() << '\n';
    std::cout << "Energy Point : " << clapTrap.getEnergyPoint() << '\n';
    std::cout << "Attack Point : " << clapTrap.getAttackDamage() << '\n';
    return (os);
}