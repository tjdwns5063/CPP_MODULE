#include "ClapTrap.hpp"

int main(void) {
    ClapTrap a("a");
    ClapTrap b("b");

    std::cout << '\n' << "-------------------------------\n";
    std::cout << '\n' << a << '\n';
    std::cout << "-------------------------------\n";
    std::cout <<'\n' << b << '\n';
    std::cout << "-------------------------------\n\n";
    a.attack("b");
    b.takeDamage(b.getAttackDamage());
    std::cout << '\n' << "-------------------------------\n";
    std::cout << '\n' << a << '\n';
    std::cout << "-------------------------------\n";
    std::cout <<'\n' << b << '\n';
    std::cout << "-------------------------------\n\n";
    b.attack("a");
    a.takeDamage(a.getAttackDamage());
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