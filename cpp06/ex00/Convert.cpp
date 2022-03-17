#include "Convert.hpp"
#include <sstream>
#include <cmath>

Convert::Convert( std::string _str ) {
	str = extractNumeric(_str);
	value = toDouble();
}

Convert::~Convert( void ) {

}

Convert::Convert( const Convert& ref ) {
	str = ref.str;
}

Convert&	Convert::operator=( const Convert& ref ) {
	str = ref.str;
	return (*this);
}

const char*	Convert::NotDecimalExpressionException::what( void ) const throw() {
	return ("this argument is not decimal expression");
}

std::string Convert::extractNumeric( std::string& _str ) {
	int	length = _str.size();

	if (str[length - 1] == 'f')
		_str.erase(length - 1);
	return (_str);
}

double Convert::toDouble( void ) const {
	std::stringstream ss(str);
	double value = 0;

	ss >> value;
	if (ss.fail() == 1)
		throw NotDecimalExpressionException();
	return (value);
}

char	Convert::toChar( void ) const {
	char	charValue = static_cast<char>(value);

	return (charValue);	
}

int	Convert::toInt( void ) const {
	int	intValue = static_cast<int>(value);

	return (intValue);
}

float	Convert::toFloat( void ) const {
	float	floatValue = static_cast<float>(value);

	return (floatValue);
}

void	Convert::print( char charValue ) const {
	if (std::isnan(value) || std::isinf(value))
		std::cout << "impossible\n";
	else if (!std::isprint(charValue))
		std::cout << "Non displayable\n";
	else
		std::cout << charValue << '\n';
}

void	Convert::print( int intValue ) const {
	if (std::isnan(value) || std::isinf(value))
		std::cout << "impossible\n";
	else
		std::cout << intValue << '\n';
}

void	Convert::print( float floatValue ) const {
	std::cout << floatValue << '\n';
}

void	Convert::print( double doubleValue ) const {
	std::cout << doubleValue << '\n';
}

std::ostream&	operator<<( std::ostream& os, const Convert& convert ) {
	char	charValue = convert.toChar();
	int		intValue = convert.toInt();
	float	floatValue = convert.toFloat();
	double	doubleValue = convert.toDouble();

	std::cout << "char: ";
	convert.print(charValue);
	std::cout << "int: ";
	convert.print(intValue);
	std::cout << "float: ";
	convert.print(floatValue);
	std::cout << "double: ";
	convert.print(doubleValue);
	return (os);
} 