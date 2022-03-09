#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class WrongDog: public Animal {
private:
    std::string type;
    Brain*  brain;

public:
    WrongDog( void );
    WrongDog( std::string idea );
    ~WrongDog( void );
    WrongDog( const WrongDog& ref );
    WrongDog& operator=( const WrongDog& ref );
    void    makeSound( void ) const;
    std::string getType( void ) const;
    void    printBrain( void );
    void    setBrain( std::string idea );
    void    deleteBrain( void );
};

#endif