#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
	Weapon*		weapon;
	std::string	name;
public:
	void	attack( void );
	void	setWeapon( Weapon* weapon );
	HumanB( std::string name );
	HumanB( std::string weaponType, std::string name );
	HumanB( void );
	~HumanB( void );
};

# endif