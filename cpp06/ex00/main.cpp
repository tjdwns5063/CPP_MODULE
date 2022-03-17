#include <iostream>
#include <sstream>
#include <iomanip>
#include "Convert.hpp"

int main(int ac, char** av) {
	std::stringstream ss(av[1]);

	// double value;

	// std::cout << "atoi : " << atoi(av[1]) << '\n';
	(void)ac;
	//std::cout << std::stod(av[1]) << '\n';
	// ss >> value;
	// std::cout << ss.fail() << '\n';
	// std::cout << value << '\n';
	Convert c(av[1]);

	try {
		std::cout << c;

	} catch (std::exception& err) {
		std::cout << err.what() << '\n';
	}
}