#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main(void) {
    {
        Dog a("5");
        Dog* b = new Dog("4");
        b->makeSound();
        a.makeSound();
        delete (b);
        
        Cat c;
        Cat* d = new Cat();
        c.makeSound();
        d->makeSound();
        delete (d);
    }
}