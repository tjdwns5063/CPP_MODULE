#include "Cure.hpp"

Cure::Cure( void ): AMateria("cure") {

}

Cure::Cure( const Cure& ref ): AMateria(ref.type) {

}

Cure::~Cure( void ) {

}

Cure&        Cure::operator=( const Cure& ref ) {
    const_cast<std::string&>(type) = ref.type;
    return (*this);
}

AMateria*   Cure::clone() const {
    AMateria*   retPtr;

    retPtr = new Cure();
    return (retPtr);
}

void        Cure::use( ICharacter& target ) {
    std::cout << "* heals " << target.getName() << "’s wounds *\n";
}