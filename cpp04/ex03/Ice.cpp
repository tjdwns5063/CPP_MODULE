#include "Ice.hpp"

Ice::Ice( void ): AMateria("ice") {

}

Ice::Ice( const Ice& ref ): AMateria(ref.type) {

}

Ice::~Ice( void ) {

}

Ice&        Ice::operator=( const Ice& ref ) {
    const_cast<std::string&>(type) = ref.type;
    return (*this);
}

AMateria*   Ice::clone() const {
    AMateria*   retPtr;

    retPtr = new Ice();
    return (retPtr);
}

void        Ice::use( ICharacter& target ) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}