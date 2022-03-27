#include "Convert.hpp"
#include <sstream>
#include <cmath>
#include <iomanip>

Convert::Convert( std::string _str ) {
	try {
		eraseF(_str);
		strToValue(_str);
	} catch (std::exception& err) {
		std::cout << err.what() << '\n';
		std::exit(EXIT_FAILURE);
	}
}

Convert::~Convert( void ) {

}

Convert::Convert( const Convert& ref ) {
	*this = ref;
}

Convert&	Convert::operator=( const Convert& ref ) {
	value = ref.value;
	return (*this);
}

const char*	Convert::NotDecimalExpressionException::what( void ) const throw() {
	return ("this argument is not decimal expression");
}

void	Convert::strToValue( std::string& _str ) {
std::stringstream ss(_str);
	double _value = 0;

	ss >> _value;
	if (ss.fail() == 1)
		throw NotDecimalExpressionException();
	value = _value;
}

void Convert::eraseF( std::string& str ) {
	int	length = str.size();

	if (str == "inf" || str == "nan" || str == "-inf" || str == "+inf" || str == "+nan" || str == "-nan")
		return ;
	if (str[length - 1] == 'f') {
		str.erase(length - 1);
	} else if (str[length - 1] != 'f' && (!std::isdigit(str[length - 1])))
		throw NotDecimalExpressionException();
}



double Convert::toDouble( void ) const {
	return (value);
}

char	Convert::toChar( void ) const {
	char charValue = static_cast<char>(value);

	return (charValue);	
}

int	Convert::toInt( void ) const {
	int	intValue = static_cast<int>(value);

	return (intValue);
}

float	Convert::toFloat( void ) const {
	float floatValue = static_cast<float>(value);

	return (floatValue);
}

void	Convert::print( char charValue ) const {
	if (std::isnan(value) || std::isinf(value))
		std::cout << "impossible\n";
	else if (!std::isprint(charValue))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << charValue << "'" << '\n';
}

void	Convert::print( int intValue ) const {
	if (std::isnan(value) || std::isinf(value))
		std::cout << "impossible\n";
	else
		std::cout << intValue << '\n';
}

void	Convert::print( float floatValue ) const {
	if (std::isinf(value))
		std::cout.setf(std::ios::showpos);
	std::cout.setf(std::ios::fixed);
	std::cout << std::setprecision(1)<< floatValue << 'f' << '\n';
	std::cout.unsetf(std::ios::showpos);
}

void	Convert::print( double doubleValue ) const {
	if (std::isinf(value))
		std::cout.setf(std::ios::showpos);
	std::cout.setf(std::ios::fixed);
	std::cout << std::setprecision(1) << doubleValue << '\n';
	std::cout.unsetf(std::ios::showpos);
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