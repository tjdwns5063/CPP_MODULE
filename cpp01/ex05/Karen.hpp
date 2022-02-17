#ifndef KAREN_HPP
# define KAREN_HPP

#include <iostream>

class Karen {
public:
	void	complain( std::string level );
	Karen( void );
	~Karen( void );
private:
	void(Karen::*m_pFunc[4])( void );
	std::string	m_pFuncName[4];

	int		getState( std::string level );
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
};

# endif