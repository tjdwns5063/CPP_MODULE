#include "Data.hpp"

Data::Data( int _source ) {
    source = _source;
}

Data::~Data( void ) {

}

Data::Data( const Data& ref ) {
    *this = ref;
}

Data&   Data::operator=( const Data& ref ) {
    source = ref.source;
    return (*this);
}

int     Data::getSource( void ) const {
    return (source);
}

uintptr_t   serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data*       deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data*>(raw));
}