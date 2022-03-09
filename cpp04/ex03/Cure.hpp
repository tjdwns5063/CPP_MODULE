#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria {
private:

public:
    Cure( void );
    Cure( const Cure& ref );
    ~Cure( void );
    Cure&        operator=( const Cure& ref );
    AMateria*   clone() const;
    void        use( ICharacter& target );
};

# endif