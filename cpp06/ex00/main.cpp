#include <iostream>
#include <sstream>
#include <iomanip>
#include "Convert.hpp"

int main(int ac, char** av) {
	if (ac != 2) {
		std::cout << "Please input one argument!\n";
		return (EXIT_FAILURE);
	}
	Convert c(av[1]);
	std::cout << c;
}