#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string _name ) : className("ClapTrap"), maxHitPoint(10), maxEnergyPoint(10), attackDamage(0) {
    name = _name;
    hitPoint = maxHitPoint;
    energyPoint = maxEnergyPoint;
    std::cout << className << " " << name << " constructed\n";
}

ClapTrap::~ClapTrap( void ) {
    const_cast<std::string&>(className) = "ClapTrap";
    std::cout << className << " " << name << " destructed\n";
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
    if ((hitPoint - amount) < 0)
        return ;
    hitPoint -= amount;
    std::cout << className << " " << name << " take " << amount << " damage\n";
}

void    ClapTrap::beRepaired( unsigned int amount ) {
    if (hitPoint <= 0) {
        return ;
    }
    if ((hitPoint + amount) >= static_cast<unsigned int>(maxHitPoint)) {
        hitPoint = maxHitPoint;
        return ;
    }
    hitPoint += amount;
    std::cout << className << " " << name << " repaired " << amount << " damage\n";
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