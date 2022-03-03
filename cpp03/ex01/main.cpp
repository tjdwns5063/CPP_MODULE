#include "ScavTrap.hpp"

int main(void) {
    ScavTrap a("a");
    ScavTrap b("b");

    std::cout << '\n' << "-------------------------------\n";
    std::cout << '\n' << a << '\n';
    std::cout << "-------------------------------\n";
    std::cout <<'\n' << b << '\n';
    std::cout << "-------------------------------\n\n";
    a.attack("b");
    b.takeDamage(a.getAttackDamage());
    std::cout << '\n' << "-------------------------------\n";
    std::cout << '\n' << a << '\n';
    std::cout << "-------------------------------\n";
    std::cout <<'\n' << b << '\n';
    std::cout << "-------------------------------\n\n";
    a.guardGate();
    b.attack("a");
    a.takeDamage(b.getAttackDamage());
    std::cout << '\n' << "-------------------------------\n";
    std::cout << '\n' << a << '\n';
    std::cout << "-------------------------------\n";
    std::cout <<'\n' << b << '\n';
    std::cout << "-------------------------------\n\n";
    b.beRepaired(5);
    std::cout << '\n' << "-------------------------------\n";
    std::cout << '\n' << a << '\n';
    std::cout << "-------------------------------\n";
    std::cout <<'\n' << b << '\n';
    std::cout << "-------------------------------\n\n";
}