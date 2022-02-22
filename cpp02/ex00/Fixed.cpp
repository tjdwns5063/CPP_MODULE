#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed( void ) {
    rawBits = 0;
    std::cout << "Default constructor called\n";
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
    std::cout << "getRawBits member function called\n";
    return (rawBits);
}

void    Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called\n";
    rawBits = raw;
}

