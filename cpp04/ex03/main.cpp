#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main(void) {
    Ice i1;
    Cure c1;
    Character*  me = new Character("Me");
    Character*  tom = new Character("Tom");

    std::cout << me->getName() << '\n';
    std::cout << tom->getName() << '\n';
    std::cout << i1.getType() << '\n';
    std::cout << c1.getType() << '\n';
}