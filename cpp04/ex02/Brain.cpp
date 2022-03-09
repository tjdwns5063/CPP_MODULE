#include "Brain.hpp"

Brain::Brain( void ) {
    std::cout << "Brain is constructed\n";
}

Brain::Brain( std::string _idea ) {
    idea = _idea;
    setIdeas( idea );
    std::cout << "Brain is constructed\n";
}

Brain::Brain( const Brain& ref ) {
    std::cout << "Brain is copied\n";
    *this = ref;
    setIdeas( ref.idea );
}

Brain::~Brain( void ) {
    std::cout << "Brain is destructed\n";
}

Brain&  Brain::operator=( const Brain& ref ) {
    setIdeas( ref.idea );
    return (*this);
}

void    Brain::setIdeas( std::string idea ) {
    for (int idx = 0; idx < 100; idx++) {
        ideas[idx] = idea;
    }
}
void    Brain::printIdeas( void ) {
    for (int idx = 0; idx < 100; idx++) {
        std::cout << idx << " : " << ideas[idx] << '\n';
    }
}

std::string Brain::getIdea( void ) const {
    return (idea);
}
