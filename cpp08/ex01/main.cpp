#include <iostream>
#include "Span.hpp"

int main()
{
	Span sp(6);
	std::vector<int> v1(4);
	//int arr[4] = {1, 2, 3, 4};
	try {
		//sp.longestSpan();
		v1[0] = 1;
		v1[2] = 3;
		//sp.addNumber(arr, (arr + 4));
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