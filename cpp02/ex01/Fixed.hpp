#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int rawBits;
    static const int fractionalBits;
public:
    Fixed( void );
    Fixed( int rawBit );
    Fixed( float rawBit );
    Fixed( const Fixed& ref );
    Fixed& operator=( const Fixed& ref );
    ~Fixed( void );
    int getRawBits( void ) const;
    void    setRawBits( int const raw );
    float   toFloat( void ) const;
    int     toInt( void ) const;
};

std::ostream&   operator<<( std::ostream& os, const Fixed& ref );

# endif