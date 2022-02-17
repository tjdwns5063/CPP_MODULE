#include "Karen.hpp"

int	main(int argc, char **argv) {
	Karen	myKaren;
	try {
		if (argc < 2)
			throw 0;
		myKaren.setFilter(argv[1]);
	} catch (int except) {
		std::cout << "Filter is not apllied\n";
	}
}