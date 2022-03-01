#include "ClapTrap.hpp"

int main(void) {
    ClapTrap a("a");
    ClapTrap b("b");


    a.attack("b");
    b.takeDamage(a.getAttackDamage());
    b.attack("a");
    a.takeDamage(b.getAttackDamage());
    b.beRepaired(5);
}