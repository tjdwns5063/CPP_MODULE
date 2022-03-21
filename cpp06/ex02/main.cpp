#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
    int random;

    std::srand(static_cast<unsigned int>(std::time(NULL)));
    random = std::rand();
    if (random % 3 == 0) {
        return (new A());
    } else if (random % 3 == 1) {
        return (new B());
    } else {
        return (new C());
    }
    return (NULL);
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "A" << '\n';
    } else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "B" << '\n';
    } else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "C" << '\n';
    } else {
        std::cout << "Unknown" << '\n';
    }
}

void identify(Base& p) {
    try {
        p = dynamic_cast<A&>(p);
        std::cout << "A" << '\n';
    } catch (std::exception& err) {
        //std::cout << "this is not A" << '\n';
    }
    try {
        p = dynamic_cast<B&>(p);
        std::cout << "B" << '\n';
    } catch (std::exception& err) {
        //std::cout << "this is not B" << '\n';
    }
    try {
        p = dynamic_cast<C&>(p);
        std::cout << "C" << '\n';
    } catch (std::exception& err) {
        //std::cout << "this is not C" << '\n';
    }
}

int main(void) {
    Base*   ptr;

    ptr = generate();
    Base&   ref = *ptr;

    identify(ptr);
    identify(ref);
}