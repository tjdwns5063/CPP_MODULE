#ifndef  IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource {
public:
    IMateriaSource( void );
    IMateriaSource( const IMateriaSource& ref );
    IMateriaSource& operator=( const IMateriaSource& ref );
    virtual ~IMateriaSource( void );
    virtual void learnMateria( AMateria* ) = 0;
    virtual AMateria* createMateria( std::string const & type ) = 0;
};

# endif