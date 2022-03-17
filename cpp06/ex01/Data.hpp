#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data {
private:
    int source;
    Data( void );

public:
    Data( int _source );
    ~Data( void );
    Data( const Data& ref );
    Data&   operator=( const Data& ref );
    int     getSource( void ) const;
};

uintptr_t   serialize(Data* ptr);
Data*       deserialize(uintptr_t raw);

# endif