#ifndef DIAMOND_HPP
# define DIAMOND_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
    std::string  name;
    DiamondTrap( void );

public:
    DiamondTrap( std::string name );
    DiamondTrap( const DiamondTrap& ref );
    ~DiamondTrap( void );
    DiamondTrap&    operator=( const DiamondTrap& ref );
    std::string     getName( void ) const;
    void            attack( std::string const& target );
    void            whoAmI( void );
};

std::ostream&   operator<<( std::ostream& os, const DiamondTrap& diamondTrap );

# endif