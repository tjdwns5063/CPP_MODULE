#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
protected:
    const std::string   className;
    std::string         name;
    const int           maxHitPoint;
    int                 hitPoint;
    const int           maxEnergyPoint;
    int                 energyPoint;
    const int           attackDamage;
    ClapTrap( void );

public:
    ClapTrap( std::string name );
    virtual ~ClapTrap( void );
    ClapTrap( const ClapTrap& ref );
    ClapTrap&   operator=( const ClapTrap& ref );
    void        attack( std::string const& target );
    void        takeDamage( unsigned int amount );
    void        beRepaired( unsigned int amount );
    std::string getClassName( void ) const;
    int         getHitPoint( void ) const;
    int         getEnergyPoint( void ) const;
    int         getAttackDamage( void ) const;
    std::string getName( void ) const;
};

std::ostream&    operator<<(std::ostream& os, const ClapTrap& clapTrap);

#endif