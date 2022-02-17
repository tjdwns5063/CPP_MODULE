#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string	name;
public:
	void	announce( void );
	void	setName( std::string name );
	void	setCnt( int	cnt );
	Zombie( void );
	Zombie( std::string name );
	~Zombie( void );
};

Zombie*	zombieHorde( int N, std::string name );

# endif