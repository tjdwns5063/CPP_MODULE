#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

Character::Character( std::string name ): ICharacter(), name(name) {
    materiaCnt = 0;
    for (int idx = 0; idx < 4; idx++) {
        materia[idx] = NULL;
    }
}

Character::~Character( void ) {
    for (int idx = 0; idx < 4; idx++) {
        if (materia[idx])
            delete (materia[idx]);
    }
}

Character::Character( const Character& ref ) {
    const_cast<std::string&>(name) = ref.name;
    materiaCnt = ref.materiaCnt;
    for (int idx = 0; idx < 4; idx++) {
        if (ref.materia[idx]->getType() == "ice") {
            try {
                materia[idx] = new Ice();
            } catch (std::bad_alloc error) {
                std::cout << "Allocate Error!\n";
            }
        }
        else if (ref.materia[idx]->getType() == "cure") {
            try {
                materia[idx] = new Cure();
            } catch (std::bad_alloc error) {
                std::cout << "Allocate Error!\n";
            }
        }
        else
            materia[idx] = NULL;
    }
}

Character&  Character::operator=( const Character& ref ) {
    if (this == &ref) {
        return (*this);
    }
    const_cast<std::string&>(name) = ref.name;
    for (int idx = 0; idx < 4; idx++) {
        if (materia[idx]) {
            delete (materia[idx]);
            materia[idx] = NULL;
        }
    }
    for (int idx = 0; idx < 4; idx++) {
        if (ref.materia[idx]->getType() == "ice") {
            try {
                materia[idx] = new Ice();
            } catch (std::bad_alloc error) {
                std::cout << "Allocate Error!\n";
                return (*this);
            }
        }
        else if (ref.materia[idx]->getType() == "cure") {
            try {
                materia[idx] = new Cure();
            } catch (std::bad_alloc error) {
                std::cout << "Allocate Error!\n";
                return (*this);
            }
        }
        else
            materia[idx] = NULL;
    }
    return (*this);
}

std::string const& Character::getName( void ) const {
    return (name);
}

void Character::equip( AMateria* m ) {
    for (int idx = 0; idx < 4; idx++) {
        if (!materia[idx]) {
            materia[idx] = m;
            materiaCnt++;
            std::cout << "equip is success\n";
            return ;
        }
    }
    std::cout << "equip is fail\n";
}

void Character::unequip( int idx ) {
    if (idx > 3) {
        std::cout << "argument is so large\n";
        return ;
    }
    if (materia[idx]) {
        materia[idx] = NULL;
    } else {
        std::cout << "this slot is empty\n";
    }
}

void Character::use( int idx, ICharacter& target ) {
    if (idx > 3) {
        std::cout << "argument is so large\n";
        return ;
    }
    if (materia[idx]) {
        materia[idx]->use(target);
    } else {
        std::cout << "this slot is empty\n";
    }
}