#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
protected:
	FragTrap( void );

public:
	FragTrap( std::string name );
	~FragTrap( void );
	FragTrap( const FragTrap& ref );
	FragTrap&	operator=( const FragTrap& ref );
	void	highFivesGuys( void );
};

std::ostream&	operator<<(std::ostream& os, const FragTrap& fragTrap);

# endif