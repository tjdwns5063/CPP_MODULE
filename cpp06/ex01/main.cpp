#include <iostream>
#include "Data.hpp"

int main(void) {
    {
        Data*   dataPtr = new Data;
        dataPtr->source = 4;
        uintptr_t serial;
        Data*   deserial;

        std::cout << "--------------size--------------------\n\n";
        std::cout << "ptr : " << sizeof(Data*) << '\n';
        std::cout << "uintptr_t : " << sizeof(uintptr_t) << '\n';

        serial = serialize(dataPtr);
        deserial = deserialize(serial);

        std::cout << "\n--------------memory--------------------\n\n";
        std::cout << "memory : " << dataPtr << '\n';
        std::cout << "memory : " << deserial << '\n';

        std::cout << "\n--------------value--------------------\n\n";        
        std::cout << "value : " << dataPtr->source << '\n';
        std::cout << "value : " << deserial->source << "\n\n";

        delete (dataPtr);
    }
}