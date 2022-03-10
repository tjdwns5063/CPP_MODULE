#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
protected:
    std::string type;

public:
    WrongAnimal( void );
    virtual ~WrongAnimal( void );
    WrongAnimal( const WrongAnimal& ref );
    WrongAnimal& operator=( const WrongAnimal& ref );
    virtual void    makeSound( void ) const;
    virtual std::string getType( void ) const;
    virtual void        setType( std::string type );
};

# endif