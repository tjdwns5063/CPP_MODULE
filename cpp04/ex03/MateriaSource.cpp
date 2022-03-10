#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ): IMateriaSource() {
    initMateria();
}

MateriaSource::~MateriaSource( void ) {
    deleteMateria();
}

MateriaSource::MateriaSource( const MateriaSource& ref ): IMateriaSource() {
    initMateria();
    copyMateria(ref);
}

MateriaSource&  MateriaSource::operator=( const MateriaSource& ref ) {
    if (this == &ref) {
        return (*this);
    }
    deleteMateria();
    copyMateria(ref); 
    return (*this);
}

void    MateriaSource::copyMateria( const MateriaSource& ref ) {
    for (int idx = 0; idx < 4; idx++) {
        if (ref.materia[idx]) {
            if (ref.materia[idx]->getType() == "cure")
                materia[idx] = new Cure();
            else if (ref.materia[idx]->getType() == "ice")
                materia[idx] = new Ice();
        } else {
            materia[idx] = NULL;
        }
    }
}

void    MateriaSource::initMateria( void ) {
    for (int idx = 0; idx < 4; idx++) {
        materia[idx] = NULL;
    }
}

void    MateriaSource::deleteMateria( void ) {
    for (int idx = 0; idx < 4; idx++) {
        if (materia[idx]) {
            delete (materia[idx]);
            materia[idx] = NULL;
        }
    }
}

void    MateriaSource::learnMateria( AMateria* _materia ) {
    for (int idx = 0; idx < 4; idx++) {
        if (!materia[idx]) {
            materia[idx] = _materia;
            return ;
        }
    }
    std::cout << "this slot is already full\n";
    delete (_materia);
}

 AMateria*   MateriaSource::createMateria( std::string const & type ) {
    for (int idx = 0; idx < 4; idx++) {
        if (materia[idx] && materia[idx]->getType() == type) {
            return (materia[idx]);
        }
    }
    std::cout << "this type is unknown\n";
    return (NULL);
 }