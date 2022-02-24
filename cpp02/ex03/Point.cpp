#include "Point.hpp"

Point::Point( void ) : x(0), y(0) {

}

Point::Point( const Fixed& _x, const Fixed& _y) : x(_x), y(_y) {

}

Point::~Point( void ) {

}

Point::Point( const Point& ref) {
    *this = ref;
}

const Fixed&  Point::getX( void ) {
    return (x);
}

const Fixed&  Point::getY( void ) {
    return (y);
}

const Fixed&  Point::getX( void ) const {
    return (x);
}

const Fixed&  Point::getY( void ) const {
    return (y);
}

Point&  Point::operator=( const Point& ref ) {
    const_cast<Fixed&>(x) = ref.x;
    const_cast<Fixed&>(y) = ref.y;
    return (*this);
}