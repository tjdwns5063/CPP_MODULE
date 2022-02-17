#include "Karen.hpp"

Karen::Karen( void ) {
	this->filter = -1;
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

void	Karen::convert_alphabet_to_lower_case(std::string& str) {
	int			size;

	size = str.size();
	for (int idx = 0; idx < size; idx++) {
		str[idx] = std::tolower(str[idx]);
	}
}

int	Karen::calcLevel( std::string level ) {
	convert_alphabet_to_lower_case(level);

	for (int _idx = 0; _idx < 4; _idx++) {
		if (this->m_pFuncName[_idx].compare(level) == 0) {
			return (_idx);
		}
	}
	return (-1);
}

void	Karen::setFilter( std::string level ) {
	this->filter = calcLevel(level);

	switch (this->filter) {
		case DEBUG:
			complain(this->m_pFuncName[DEBUG]);
		case INFO:
			complain(this->m_pFuncName[INFO]);
		case WARNING:
			complain(this->m_pFuncName[WARNING]);
		case ERROR:
			complain(this->m_pFuncName[ERROR]);
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n\n";
			break ;
	}
}

void	Karen::complain( std::string level ) {
	int	_level;

	_level = calcLevel(level);
	try {
		if (_level < this->filter)
			throw 0;
	} catch (int except) {
		return ;
	}
	(this->*m_pFunc[_level])();
	std::cout << '\n';
}

void	Karen::debug( void ) {
	std::cout << "[ DEBUG ]\n";
	std::cout << \
	"I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\n";
}

void	Karen::info( void ) {
	std::cout << "[ INFO ]\n";
	std::cout << \
	"I cannot believe adding extra bacon cost more money.\
 You don’t put enough! If you did I would not have to ask for it!\n";
}

void	Karen::warning( void ) {
	std::cout << "[ WARNING ]\n";
	std::cout << \
	"I think I deserve to have some extra bacon for free.\
 I’ve been coming here for years and you just started working here last month.\n";
}

void	Karen::error( void ) {
	std::cout << "[ ERROR ]\n";
	std::cout << \
	"This is unacceptable, I want to speak to the manager now.\n";
}