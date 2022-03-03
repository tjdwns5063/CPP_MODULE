#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
    const Animal* meta = new Animal();
    const Dog*    j = new Dog();
    const Cat*    i = new Cat();

    meta->makeSound();
    j->makeSound();
    i->makeSound();
    delete (meta);
    delete (j);
    delete (i);
}