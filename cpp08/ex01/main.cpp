#include <iostream>
#include <typeinfo>
#include "Span.hpp"

int main()
{
	Span sp(8);

	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(12);

		std::cout << sp << '\n';
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception& err) {
		std::cerr << err.what() << '\n';
	}
	return 0;
}