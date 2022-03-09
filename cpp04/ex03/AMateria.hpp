#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria {
protected:
    const std::string type;
public:
    AMateria( void );
    AMateria( std::string const & type );
    AMateria( const AMateria& ref );
    AMateria&   operator=( const AMateria& ref );
    std::string const& getType() const; //Returns the materia type
    virtual ~AMateria( void );
    virtual AMateria* clone() const = 0;
    virtual void use( ICharacter& target );
};

# endif