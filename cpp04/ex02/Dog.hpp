#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
    std::string type;
    Brain*  brain;

public:
    Dog( void );
    Dog( std::string idea );
    ~Dog( void );
    Dog( const Dog& ref );
    Dog& operator=( const Dog& ref );
    void    makeSound( void ) const;
    std::string getType( void ) const;
    void        setType( std::string type );
    void        printBrain( void );
    void        setBrain( std::string idea );
};

# endif 