#include <iostream>
#include <sstream>
#include <iomanip>
#include "Convert.hpp"

int main(int ac, char** av) {
	static_cast<void>(ac);
	try {
		Convert c(av[1]);
		std::cout << c;

	} catch (std::exception& err) {
		std::cout << err.what() << '\n';
	}
}