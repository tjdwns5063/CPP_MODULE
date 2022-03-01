#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : ClapTrap {
private:
    bool    guardMode;

public:
    ScavTrap( std::string name );
    ~ScavTrap( void );
    ScavTrap( const ScavTrap& ref );
    void    attack( std::string const& target );
    void    takeDamage( unsigned int amount );
    void    beRepaired( unsigned int amount );
    int         getHitPoint( void ) const;
    int         getEnergyPoint( void ) const;
    int         getAttackDamage( void ) const;
    ScavTrap&   operator=( const ScavTrap& ref );
    void    guardGate( void );
};

# endif