#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class   PhoneBook
{
private:
    Contact     contacts[8];
    int         curr_idx;
    int         curr_cnt;
    std::string format_output(std::string output);
    void        formatted_print(std::string output);
    void        show_recorded_name(void);
    void        find_and_show_phone_number(void);
public:
    PhoneBook();
    ~PhoneBook();
    void    add(void);
    void    search(void);
    void    exit(void);
};

# endif