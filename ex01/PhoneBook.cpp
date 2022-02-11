#include <iomanip>
#include <stdlib.h>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->curr_idx = 0;
    this->curr_cnt = 0;
    std::cout << "======================" << '\n';
    std::cout << "      Phone Book      " << '\n';
    std::cout << "======================" << '\n';
    std::cout << "[ADD] : ADD CONTACT" << '\n';
    std::cout << "[SEARCH] : SEARCH CONTACT" << '\n';
    std::cout << "[EXIT] : EXIT PHONE BOOK" << '\n';
}

PhoneBook::~PhoneBook()
{
}

std::string PhoneBook::format_output(std::string str)
{
    int         len;
    std::string ret;

    len = str.size();
    if (len > 10)
    {
        str[9] = '.';
        ret = str.substr(0, 10);
    }
    else
        ret = str;
    return (ret);
}

void    PhoneBook::formatted_print(std::string output)
{
    std::cout << std::setw(10) << output << '|';
}

void    PhoneBook::show_recorded_name(void)
{
    std::string  output;

    for (int idx = 0; idx < this->curr_cnt; idx++)
    {
        std::cout << std::setw(10) << idx + 1 << '|';
        output = format_output(this->contacts[idx].get_first_name());
        formatted_print(output);
        output = format_output(this->contacts[idx].get_last_name());
        formatted_print(output);
        output = format_output(this->contacts[idx].get_nickname());
        formatted_print(output);
        std::cout << '\n';
    }
}

void    PhoneBook::add_contact_info(std::string& info)
{
    getline(std::cin, info);
    if (std::cin.fail())
        std::exit(EXIT_FAILURE);
}

void    PhoneBook::find_and_show_phone_number(void)
{
    int target_idx;

    std::cout << "write index then print phone_number" << '\n';
    std::cin >> target_idx;
    try {
        if (std::cin.fail()) throw 0;
        if (target_idx > this->curr_cnt)
            std::cout << "current available contact : " << this->curr_cnt << '\n';
        for (int idx = 0; idx < this->curr_cnt; idx++)
        {
            if (idx == target_idx - 1)
                std::cout << "phone_number : " << this->contacts[idx].get_phone_number() << '\n';
        }
    } catch (int except) {
        if (std::cin.eof())
            std::exit(EXIT_FAILURE);
        std::cout << "ERROR : please, input index(int)" << '\n';
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "search is end" << '\n';
}

void    PhoneBook::search(void)
{
    try {
        if (this->curr_cnt == 0) throw 0;
        formatted_print("index");
        formatted_print("first_name");
        formatted_print("last_name");
        formatted_print("nickname");
        std::cout << '\n';
        show_recorded_name();
        find_and_show_phone_number();
    } catch (int except) {
        std::cout << "current available contact : 0\n";
        return ;
    }
}

void    PhoneBook::add(void)
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "write first name : " << '\n';
    add_contact_info(first_name);
    this->contacts[curr_idx].set_first_name(first_name);
    std::cout << "write last name : " << '\n';
    add_contact_info(last_name);
    this->contacts[curr_idx].set_last_name(last_name);
    std::cout << "write nickname : " << '\n';
    add_contact_info(nickname);
    this->contacts[curr_idx].set_nickname(nickname);
    std::cout << "write phone number : " << '\n';
    add_contact_info(phone_number);
    this->contacts[curr_idx].set_phone_number(phone_number);
    std::cout << "write darkest secret : " << '\n';
    add_contact_info(darkest_secret);
    this->contacts[curr_idx].set_darkest_secret(darkest_secret);
    std::cout << "add is done" << '\n';

    this->curr_idx++;
    if (curr_idx == 8)
        this->curr_idx = 0;
    if (curr_cnt < 8)
        this->curr_cnt++;
}

void    PhoneBook::exit(void)
{
    std::exit(EXIT_SUCCESS);
}