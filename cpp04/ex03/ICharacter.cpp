#include "ICharacter.hpp"

ICharacter::ICharacter( void ) {

}

ICharacter::ICharacter( const ICharacter& ref ) {
    *this = ref;
}

ICharacter& ICharacter::operator=( const ICharacter& ref ) {
    static_cast<void>(ref);
    return (*this);
}

ICharacter::~ICharacter( void ) {

}