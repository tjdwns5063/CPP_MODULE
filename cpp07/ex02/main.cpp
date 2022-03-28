#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(void) {
	{
		Array<int> numbers(10);
		for (int i = 0; i < 10; i++) {
			numbers[i] = i + 1;
		}
		Array<int> assign = numbers;
		for (int i = 0; i < 10; i++) {
			assign[i] = i + 10;
		}
		Array<int> copy(assign);
		for (int i = 0; i < 10; i++) {
			copy[i] = i + 20;
		}
		std::cout << "------------numbers---------\n";
		std::cout << numbers << '\n';
		std::cout << "------------assign---------\n";
		std::cout << assign << '\n';
		std::cout << "------------copied---------\n";
		std::cout << copy << '\n';
		std::cout << numbers.size() << '\n';
		std::cout << assign.size() << '\n';
		std::cout << copy.size() << '\n';
	}
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;
		return 0;
	}
}
