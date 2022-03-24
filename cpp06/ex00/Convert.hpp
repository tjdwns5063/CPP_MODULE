#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>

class Convert {
private:
	double		value;

	Convert( void );
	void	eraseF( std::string& _str );
	void	strToValue( std::string& _str );

public:
	Convert( std::string _str );
	~Convert( void );
	Convert( const Convert& ref );
	Convert&	operator=( const Convert& ref );
	class NotDecimalExpressionException: public std::exception {
		const char*	what( void ) const throw();
	};
	char	toChar( void ) const;
	int		toInt( void ) const;
	float	toFloat( void ) const;
	double	toDouble( void ) const;
	void	print( char charValue ) const;
	void	print( int intValue ) const;
	void	print( float floatValue ) const;
	void	print( double doubleValue ) const;
};

std::ostream&	operator<<( std::ostream& os, const Convert& convert );

# endif