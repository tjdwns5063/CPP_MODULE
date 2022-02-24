#include "Fixed.hpp"
#include <cmath>

const int Fixed::fractionalBits = 8;

Fixed::Fixed( void ) {
    rawBits = 0;
    std::cout << "Default constructor called\n";
}

Fixed::Fixed( int rawBit ) {
    rawBits = rawBit << fractionalBits;
    std::cout << "Int constructor called\n";
}
Fixed::Fixed( float rawBit ) {
    rawBits = roundf(rawBit * (1 << fractionalBits));
    std::cout << "Float constructor called\n";
}

Fixed::Fixed( const Fixed& ref ) {
    std::cout << "Copy constructor called\n";
    *this = ref;
}

Fixed& Fixed::operator=( const Fixed& ref ) {
    std::cout << "Assignation operator called\n";
    rawBits = ref.getRawBits();
    return (*this);
}

Fixed::~Fixed( void ) {
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const {
    return (rawBits);
}

void    Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called\n";
    rawBits = raw << fractionalBits;
}

float   Fixed::toFloat( void ) const {
    float   ret;

    ret = static_cast<float>(this->rawBits) / (1 << fractionalBits);
    return (ret);
}

int     Fixed::toInt( void ) const {
    int ret;

    ret = this->getRawBits() >> fractionalBits;
    return (ret);
}

std::ostream&   operator<<( std::ostream& os, const Fixed& ref ) {
    std::cout << ref.toFloat();
    return (os);
}