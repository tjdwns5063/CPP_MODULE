#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook   temp;
    std::string order;

    while (1)
    {
        std::cin >> order;
        if (order == "ADD")
            temp.add();
        else if (order == "SEARCH")
            temp.search();
        else if (order == "EXIT")
            temp.exit();
        else
        {
            std::cin.clear();
            continue ;
        }
    }
}