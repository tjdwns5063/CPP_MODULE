#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
    bool                guardMode;
    ScavTrap( void );

public:
    ScavTrap( std::string name );
    virtual ~ScavTrap( void );
    ScavTrap( const ScavTrap& ref );
    ScavTrap&   operator=( const ScavTrap& ref );
    void    takeDamage( unsigned int amount );
    void    guardGate( void );
};

std::ostream&   operator<<(std::ostream& os, const ScavTrap& scavTrap);

# endif