#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(void) {
    // size=35088790000000 fail
    // size=140355160002560

	const Array<int> numbers(35088790000000);
    if (numbers.fail()) {
        std::cout << "fail\n";
        return (EXIT_FAILURE);
    }
    std::cout << "success\n";
	// for (int i = 0; i < 10; i++) {
	// 	numbers[i] = i + 1;
	// }
	// Array<int> assign = numbers;
	// for (int i = 0; i < 10; i++) {
	// 	assign[i] = i + 10;
	// }
	// const Array<int> copy(assign);
	// for (int i = 0; i < 10; i++) {
	// 	copy[i] = i + 20;
	// }
	// std::cout << "------------numbers---------\n";
	// for (int i = 0; i < 10; i++) {
		
	// 	std::cout << "numbers[" << i << "] " << numbers[i] << '\n';
	// }
	// std::cout << "------------assign---------\n";
	// for (int i = 0; i < 10; i++) {
	// 	std::cout << "assign[" << i << "] " << assign[i] << '\n';
	// }
	// std::cout << "------------copied---------\n";
	// for (int i = 0; i < 10; i++) {
	// 	std::cout << "copy[" << i << "] " << copy[i] << '\n';
	// }
	// std::cout << numbers.size() << '\n';
	// std::cout << assign.size() << '\n';
	// std::cout << copy.size() << '\n';

}
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
// 		std::cout << "heree\n";
//         Array<int> tmp = numbers;
// 		std::cout << "fuc\n";
//         Array<int> test(tmp);
// 		std::cout << "error\n";
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;
//     return 0;
// }