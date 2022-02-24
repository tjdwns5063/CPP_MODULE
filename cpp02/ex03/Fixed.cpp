#include "Fixed.hpp"
#include <cmath>

const int Fixed::fractionalBits = 8;

Fixed::Fixed( void ) {
    rawBits = 0;
}

Fixed::Fixed( int rawBit ) {
    rawBits = rawBit << fractionalBits;
}
Fixed::Fixed( float rawBit ) {
    rawBits = roundf(rawBit * (1 << fractionalBits));
}

Fixed::Fixed( const Fixed& ref ) {
    *this = ref;
}

Fixed& Fixed::operator=( const Fixed& ref ) {
    rawBits = ref.getRawBits();
    return (*this);
}

Fixed::~Fixed( void ) {

}

int Fixed::getRawBits( void ) const {
    return (rawBits);
}

void    Fixed::setRawBits( int const raw ) {
    rawBits = raw << fractionalBits;
}

float   Fixed::toFloat( void ) const {
    float   ret;

    ret = static_cast<float>(rawBits) / (1 << fractionalBits);
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

bool    Fixed::operator>( const Fixed& next) const {
    return (rawBits > next.rawBits);
}

bool    Fixed::operator<( const Fixed& next ) const {
    return (rawBits < next.rawBits);
}

bool    Fixed::operator>=( const Fixed& next ) const {
    return (rawBits >= next.rawBits);
}

bool    Fixed::operator==( const Fixed& next ) const {
    return (rawBits == next.rawBits);
}

bool    Fixed::operator<=( const Fixed& next ) const {
    return (rawBits <= next.rawBits);
}

bool    Fixed::operator!=( const Fixed& next ) const {
    return (rawBits != next.rawBits);
}

Fixed   Fixed::operator+( const Fixed& next ) const {
    Fixed   temp(this->toFloat() + next.toFloat());
    return (temp);
}

Fixed   Fixed::operator-( const Fixed& next ) const {
    Fixed   temp(this->toFloat() - next.toFloat());
    return (temp);
}

Fixed   Fixed::operator*( const Fixed& next ) const {
    Fixed   temp(this->toFloat() * next.toFloat());
    return (temp);
}

Fixed   Fixed::operator/( const Fixed& next ) const {
    if (next.getRawBits() == 0) {
        std::cout << "division by zero is undefined!!!\n";
    }
    Fixed   temp(this->toFloat() / next.toFloat());
    return (temp);
}

Fixed&   Fixed::operator++( void ) {
    ++rawBits;
    return (*this);
}

Fixed   Fixed::operator++( int ) {
    Fixed   temp = *this;
    operator++();
    return (temp);
}

Fixed&	Fixed::operator--( void ) {
	--rawBits;
	return (*this);
}

Fixed	Fixed::operator--( int ) {
	Fixed	temp = *this;
    operator--();
	return (temp);
}

Fixed&   Fixed::max( const Fixed& prev, const Fixed& next ) {
	if (prev >= next) {
		return (const_cast<Fixed&>(prev));
	} else {
		return (const_cast<Fixed&>(next));
	}
}

Fixed&	Fixed::min( const Fixed& prev, const Fixed& next ) {
	if (prev <= next) {
		return (const_cast<Fixed&>(prev));
	} else {
		return (const_cast<Fixed&>(next));
	}
}