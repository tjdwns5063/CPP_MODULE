#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main(void) {
    {
        const Animal* meta = new Animal();
        const Animal*    j = new Dog();
        const Animal*    i = new Cat();

        std::cout << meta->getType() << std::endl;
        std::cout << j->getType() << std::endl;
        std::cout << i->getType() << std::endl;

        meta->makeSound();
        j->makeSound();
        i->makeSound();

        delete (meta);
        delete (j);
        delete (i);

        std::system("leaks Animal");
        std::cout << "----------------------------------------\n";
    }
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal*    j = new WrongDog();
        const WrongAnimal*    i = new WrongCat();

        std::cout << meta->getType() << std::endl;
        std::cout << j->getType() << std::endl;
        std::cout << i->getType() << std::endl;

        meta->makeSound();
        j->makeSound();
        i->makeSound();

        delete (meta);
        delete (j);
        delete (i);
        std::system("leaks Animal");
        std::cout << "----------------------------------------\n";
    }
}