#include "FragTrap.hpp"

int main(void) {
    FragTrap A("A");
    FragTrap B("B");


    A.attack("B");
    B.takeDamage(A.getAttackDamage());
    std::cout << "current B's HitPoint is " << B.getHitPoint() << '\n';
    B.attack("A");
    A.takeDamage(B.getAttackDamage());
    std::cout << "current A's HitPoint is " << A.getHitPoint() << '\n';
    B.beRepaired(5);
    std::cout << "current B's HitPoint is " << B.getHitPoint() << '\n';
    A.highFivesGuys();
}