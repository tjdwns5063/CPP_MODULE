#ifndef DATA_HPP
# define DATA_HPP

#include <cstdint>

typedef struct Data {
    int source;
} Data;

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

# endif