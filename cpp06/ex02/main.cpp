#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "util.hpp"

int main(void) {
    Base*   ptr = generate();
    Base&   ref = *ptr;

    identify(ptr);
    identify(ref);
    delete (ptr);
}