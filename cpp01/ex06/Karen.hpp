#ifndef KAREN_HPP
# define KAREN_HPP

#include <iostream>

class Karen {
public:
	void	complain( std::string level );
	void	setFilter( std::string level );
	Karen( void );
	Karen( std::string level );
	~Karen( void );
private:
	void(Karen::*m_pFunc[4])( void );
	std::string	m_pFuncName[4];
	int			filter;
	enum		e_level {
		DEBUG,
		INFO,
		WARNING,
		ERROR,
	};

	void		convert_alphabet_to_lower_case(std::string& str);
	int			calcLevel( std::string level );
	void		debug( void );
	void		info( void );
	void		warning( void );
	void		error( void );
};

# endif