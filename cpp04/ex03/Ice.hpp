#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria {
private:

public:
    Ice( void );
    Ice( const Ice& ref );
    ~Ice( void );
    Ice&        operator=( const Ice& ref );
    AMateria*   clone() const;
    void        use( ICharacter& target );
};

# endif