#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource(void) {

}

IMateriaSource::~IMateriaSource(void) {

}

IMateriaSource::IMateriaSource(const IMateriaSource& ref) {
    *this = ref;
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource& ref) {
    static_cast<void>(ref);
    return (*this);
}