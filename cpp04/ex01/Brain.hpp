#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
private:
    std::string idea;
    std::string ideas[100];
public:
    Brain( void );
    Brain( std::string _idea );
    Brain( const Brain& ref );
    ~Brain( void );
    Brain&          operator=( const Brain& ref );
    void            setIdeas( std::string idea );
    std::string     getIdea( void ) const;
    void            printIdeas( void );
};

# endif