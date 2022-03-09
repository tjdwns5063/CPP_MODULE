#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main(void) {
    {
        Animal* array[10];

        for (int idx = 0; idx < 10; idx++) {
            if (idx < 5) {
                try {
                    array[idx] = new Dog("5");
                } catch (std::bad_alloc& err) {
                    std::cout << "Allocate Error!\n";
                    return (0);
                }
            } else {
                try {
                    array[idx] = new Cat("10");
                } catch (std::bad_alloc& err) {
                    std::cout << "Allocate Error!\n";
                    return (0);
                }
            }
        }
        for (int idx = 0; idx < 10; idx++) {
            delete (array[idx]);
        }
        std::system("leaks Animal");
    }
    {
        std::cout << "-----------------------------------\n";
        Dog b("4");
        
        Dog a(b);
        std::cout << "---------------prev-------------\n";
        a.printBrain();
        b.printBrain();
        std::cout << "---------------next-------------\n";
        b.setBrain("5");
        a.printBrain();
        b.printBrain();
        std::system("leaks Animal");
    }
    // {
    //     std::cout << "-----------------------------------\n";
    //     Animal* array[10];

    //     for (int idx = 0; idx < 10; idx++) {
    //         if (idx < 5) {
    //             try {
    //                 array[idx] = new WrongDog("5");
    //             } catch (std::bad_alloc& err) {
    //                 std::cout << "Allocate Error!\n";
    //                 return (NULL);
    //             }
    //         } else {
    //             try {
    //                 array[idx] = new WrongCat("10");
    //             } catch (std::bad_alloc& err) {
    //                 std::cout << "Allocate Error!\n";
    //                 return (NULL);
    //             }
    //         }
    //     }
    //     for (int idx = 0; idx < 10; idx++) {
    //         if (idx < 5) {
    //             dynamic_cast<WrongDog*>(array[idx])->deleteBrain();
    //         } else {
    //             dynamic_cast<WrongCat*>(array[idx])->deleteBrain();
    //         }
    //         delete (array[idx]);
    //     }
    //     std::system("leaks Animal");
    // }
    // {
    //     std::cout << "-----------------------------------\n";
    //     WrongDog c("4");
    //     WrongDog d;

    //     d = c;
    //     std::cout << "---------------prev-------------\n";
    //     c.printBrain();
    //     d.printBrain();
    //     std::cout << "---------------next-------------\n";
    //     c.setBrain("5");
    //     c.printBrain();
    //     d.printBrain();
    //     std::system("leaks Animal");
    // }
}