#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
protected:
    std::string type;

public:
    Animal( void );
    virtual ~Animal( void );
    Animal( const Animal& ref );
    Animal& operator=( const Animal& ref );
    virtual void    makeSound( void ) const = 0;
    virtual std::string getType( void ) const = 0;
    virtual void        setType( std::string type ) = 0;
};

# endif