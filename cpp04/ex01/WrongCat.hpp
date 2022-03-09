#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class WrongCat: public Animal {
private:
    std::string type;
    Brain*  brain;

public:
    WrongCat( void );
    WrongCat( std::string idea );
    ~WrongCat( void );
    WrongCat( const WrongCat& ref );
    WrongCat& operator=( const WrongCat& ref );
    void    makeSound( void ) const;
    std::string getType( void ) const;
    void    printBrain( void );
    void    setBrain( std::string idea );
    void    deleteBrain( void );
};

#endif