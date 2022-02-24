#include "Point.hpp"

Fixed getMaxXpos(Point firstP, Point secondP, Point thirdP) {
    Fixed   maxXpos;

    maxXpos = Fixed::max(firstP.getX(), secondP.getX());
    maxXpos = Fixed::max(maxXpos, thirdP.getX());
    return (maxXpos);
}

Fixed getMinXpos(Point firstP, Point secondP, Point thirdP) {
    Fixed   minXpos;

    minXpos = Fixed::min(firstP.getX(), secondP.getX());
    minXpos = Fixed::min(minXpos, thirdP.getX());
    return (minXpos);
}

Fixed getMaxYpos(Point firstP, Point secondP, Point thirdP) {
    Fixed   maxYpos;

    maxYpos = Fixed::max(firstP.getY(), secondP.getY());
    maxYpos = Fixed::max(maxYpos, thirdP.getY());
    return (maxYpos);
}

Fixed getMinYpos(Point firstP, Point secondP, Point thirdP) {
    Fixed   minYpos;

    minYpos = Fixed::min(firstP.getY(), secondP.getY());
    minYpos = Fixed::min(minYpos, thirdP.getY());
    return (minYpos);
}

bool    bsp(Point const firstP, Point const secondP, Point const thirdP, Point const evalP) {
    if ((firstP.getX() == secondP.getX() && secondP.getX() == thirdP.getX()) \
    || (firstP.getY() == secondP.getY() && secondP.getY() == thirdP.getY())) {
        std::cout << "this is not triangle\n";
        std::exit(1);
    }

    Fixed minXpos = getMinXpos(firstP, secondP, thirdP);
    Fixed maxXpos = getMaxXpos(firstP, secondP, thirdP);
    Fixed minYpos = getMinYpos(firstP, secondP, thirdP);
    Fixed maxYpos = getMaxYpos(firstP, secondP, thirdP);

    if ((minXpos < evalP.getX() && evalP.getX() < maxXpos) && \
    (minYpos < evalP.getY() && evalP.getY() < maxYpos)) {
        return (true);
    } else {
        return (false);
    }
}