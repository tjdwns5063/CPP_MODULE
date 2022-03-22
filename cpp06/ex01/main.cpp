#include "Data.hpp"

int main(void) {
    {
        Data*   dataPtr = new Data(4);
        uintptr_t serial;

        Data*   deserial;


        serial = serialize(dataPtr);
        deserial = deserialize(serial);


        std::cout << dataPtr << '\n';
        std::cout << deserial << '\n';
        
        std::cout << *dataPtr << '\n';
        std::cout << *deserial << '\n';
    }
}