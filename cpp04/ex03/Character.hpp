#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character: public ICharacter {
private:
    const std::string name;
    AMateria*   materia[4];
    Character( void );
public:
    Character( std::string name );
    ~Character( void );
    Character( const Character& ref );
    Character&  operator=( const Character& ref );
    std::string const& getName( void ) const;
    void equip( AMateria* m );
    void unequip( int idx );
    void use( int idx, ICharacter& target );
};

# endif