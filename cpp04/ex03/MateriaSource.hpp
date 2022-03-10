#ifndef  MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
private:
    AMateria*   materia[4];
    void    initMateria( void );
    void    deleteMateria( void );
	void	copyMateria( const MateriaSource& ref );

public:
    MateriaSource( void );
    MateriaSource( const MateriaSource& ref );
    MateriaSource& operator=( const MateriaSource& ref );
    ~MateriaSource( void );
    void learnMateria( AMateria* );
    AMateria*   createMateria( std::string const & type );
};

# endif