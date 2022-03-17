#include "Data.hpp"

int main(void) {
    // {
    //     Data*   dataPtr = new Data(4);
    //     uintptr_t serial;

    //     Data*   deserial;


    //     serial = serialize(dataPtr);
    //     deserial = deserialize(serial);


    //     std::cout << dataPtr << '\n';
    //     std::cout << deserial << '\n';
        
    //     std::cout << *dataPtr << '\n';
    //     std::cout << *deserial << '\n';
    // }
    {
        std::string str = "abcd";
        std::string* strPtr = &str;
        int*    numPtr;
        std::string* newPtr;

        numPtr = reinterpret_cast<int*>(strPtr);
        newPtr = reinterpret_cast<std::string*>(numPtr);
        std::cout << *newPtr << '\n';
        std::cout << *strPtr << '\n';
    }
}