#include "FragTrap.hpp"

int main(void) {
    FragTrap a = FragTrap("a");
    FragTrap b = FragTrap("b");

    std::cout << '\n' << "-------------------------------\n";
    std::cout << '\n' << a << '\n';
    std::cout << "-------------------------------\n";
    std::cout <<'\n' << b << '\n';
    std::cout << "-------------------------------\n\n";
    aattack("b");
    b.takeDamage(a.getAttackDamage());
    std::cout << '\n' << "-------------------------------\n";
    std::cout << '\n' << a << '\n';
    std::cout << "-------------------------------\n";
    std::cout <<'\n' << b << '\n';
    std::cout << "-------------------------------\n\n";
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
    a.highFivesGuys();
    std::cout << "\n-------------------------------\n\n";
}