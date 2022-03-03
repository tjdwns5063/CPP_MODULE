#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
protected:
    std::string type;

public:
    Dog( void );
    ~Dog( void );
    Dog( const Dog& ref );
    Dog& operator=( const Dog& ref );
    void    makeSound( void ) const;
};

# endif