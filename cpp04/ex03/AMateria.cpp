#include "AMateria.hpp"

AMateria::AMateria(std::string const & type): type(type) {

}

AMateria::~AMateria(void) {

}

AMateria::AMateria(const AMateria& ref) {
    *this = ref;
}

AMateria&   AMateria::operator=(const AMateria& ref) {
    const_cast<std::string&>(type) = ref.type;
    return (*this);
}

void AMateria::use(ICharacter& target) {
    std::cout << "using unknown materia\n";
    static_cast<void>(target);
}

std::string const& AMateria::getType() const {
    return (type);
}
