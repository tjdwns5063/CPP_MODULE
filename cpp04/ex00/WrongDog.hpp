#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {
private:
    std::string type;

public:
    WrongDog( void );
    ~WrongDog( void );
    WrongDog( const WrongDog& ref );
    WrongDog& operator=( const WrongDog& ref );
    void    makeSound( void ) const;
    std::string getType( void ) const;
};

# endif