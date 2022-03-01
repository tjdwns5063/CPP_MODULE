#include "ScavTrap.hpp"

int main(void) {
    ScavTrap a("a");
    ScavTrap b("b");

    std::cout << b.getHitPoint() << '\n';
    a.attack("b");
    b.takeDamage(a.getAttackDamage());
    std::cout << b.getHitPoint() << '\n';
    b.beRepaired(30);
    std::cout << b.getHitPoint() << '\n';
    b.guardGate();
    b.takeDamage(a.getAttackDamage());
}