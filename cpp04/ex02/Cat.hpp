#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
    std::string type;
    Brain*  brain;

public:
    Cat( void );
    Cat( std::string idea );
    ~Cat( void );
    Cat( const Cat& ref );
    Cat&        operator=( const Cat& ref );
    void        makeSound( void ) const;
    std::string getType( void ) const;
    void        setType( std::string type );
    void        printBrain( void );
    void        setBrain( std::string idea );
};

# endif