#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    Fixed const x;
    Fixed const y;

public:
    Point( void );
    Point( const Fixed& _x, const Fixed& _y );
    ~Point( void );
    Point( const Point& ref );
    const Fixed&  getX( void );
    const Fixed&  getY( void );
    const Fixed&  getX( void ) const;
    const Fixed&  getY( void ) const;
    Point&  operator=( const Point& ref );
};

bool    bsp(Point const firstP, Point const secondP, Point const thirdP, Point const evalP);


# endif