#include <limits>
#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook   temp;
    std::string order;

    while (1)
    {
        std::cin >> std::ws >>  order;
        try {
            if (std::cin.fail()) throw 0;
            if (order == "ADD" || order == "add")
                temp.add();
            else if (order == "SEARCH" || order == "search")
                temp.search();
            else if (order == "EXIT" || order == "exit")
                temp.exit();
            else
                std::cout << "invalid order\n";
        } catch (int except) {
            std::exit(EXIT_FAILURE);
        }
    }
}