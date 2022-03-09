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
    virtual void    makeSound( void ) const;
    virtual std::string getType( void ) const;
    virtual void        setType( std::string type );
};

# endif