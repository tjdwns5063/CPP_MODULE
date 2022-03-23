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
    } else if (random % 3 == 2) {
        return (new C());
    } else {
        return (NULL);
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "Ptr : A\n";
        return ;
    } else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "Ptr : B\n";
        return ;
    } else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "Ptr : C\n";
        return ;
    } else {
        std::cout << "Unknown\n";
    }
}

void identify(Base& p) {
    try {
        p = dynamic_cast<A&>(p);
        std::cout << "Ref : A\n";
        return ;
    } catch (std::exception& err) {
        //std::cout << "this is not A" << '\n';
    }
    try {
        p = dynamic_cast<B&>(p);
        std::cout << "Ref : B\n";
        return ;
    } catch (std::exception& err) {
        //std::cout << "this is not B" << '\n';
    }
    try {
        p = dynamic_cast<C&>(p);
        std::cout << "Ref : C\n";
        return ;
    } catch (std::exception& err) {
        //std::cout << "this is not C" << '\n';
    }
    std::cout << "Unknown\n";
}

int main(void) {
    Base*   ptr = generate();
    Base&   ref = *ptr;

    identify(ptr);
    identify(ref);
    delete (ptr);
}