#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap :  public ClapTrap {
private:
	FragTrap( void );

public:
	FragTrap( std::string name );
	~FragTrap( void );
	FragTrap( const FragTrap& ref );
	FragTrap&	operator=( const FragTrap& ref );
	void	highFivesGuys( void );
};

# endif