#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
protected:
    std::string type;

public:
    Animal( void );
    ~Animal( void );
    Animal( const Animal& ref );
    Animal& operator=( const Animal& ref );
    void    makeSound( void ) const;
};

# endif