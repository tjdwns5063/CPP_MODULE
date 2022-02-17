#include "Karen.hpp"

Karen::Karen( void ) {
	this->m_pFunc[0] = &Karen::debug;
	this->m_pFunc[1] = &Karen::info;
	this->m_pFunc[2] = &Karen::warning;
	this->m_pFunc[3] = &Karen::error;
	this->m_pFuncName[0] = "debug";
	this->m_pFuncName[1] = "info";
	this->m_pFuncName[2] = "warning";
	this->m_pFuncName[3] = "error";
}

Karen::~Karen( void ) {

}

int	Karen::getState( std::string level ) {
	for (int idx = 0; idx < 4; idx++) {
		if (level == this->m_pFuncName[idx]) {
			return (idx);
		}
	}
	return (-1);
}

void	Karen::complain( std::string level ) {
	int	state = getState(level);
	
	if (state < 0) {
		std::cout << "invalid input\n";
	} else {
		(this->*m_pFunc[state])();
	}
}

void	Karen::debug( void ) {
	std::cout << \
	"I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\n";
}

void	Karen::info( void ) {
	std::cout << \
	"I cannot believe adding extra bacon cost more money.\
 You don’t put enough! If you did I would not have to ask for it!\n";
}

void	Karen::warning( void ) {
	std::cout << \
	"I think I deserve to have some extra bacon for free.\
 I’ve been coming here for years and you just started working here last month.\n";
}

void	Karen::error( void ) {
	std::cout << \
	"This is unacceptable, I want to speak to the manager now.\n";
}