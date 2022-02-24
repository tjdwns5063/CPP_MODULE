#include "Point.hpp"

int main( void ) {
    Point   first(3, 4);
    Point   second(10, 9);
    Point   third(3, 10);
    Point   eval(5, 3);

    std::cout << "first : (" << first.getX() << ", " << first.getY() << ")\n";
    std::cout << "second : (" << second.getX() << ", " << second.getY() << ")\n";
    std::cout << "third : (" << third.getX() << ", " << third.getY() << ")\n";
    std::cout << "eval : (" << eval.getX() << ", " << eval.getY() << ")\n";

    std::cout << std::boolalpha << bsp(first, second, third, eval) << '\n';
    return 0;
}