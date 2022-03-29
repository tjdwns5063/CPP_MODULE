#include <iostream>
#include <typeinfo>
#include "Span.hpp"

int main()
{
	Span sp(8);
	long long a = std::numeric_limits<long long>::max();
	long long b = std::numeric_limits<long long>::min();
	// std::cout << std::numeric_limits<long long>::max() << '\n';
	// std::cout << std::numeric_limits<long>::max() << '\n';
	int a2 = std::numeric_limits<int>::max();
	int b2 = std::numeric_limits<int>::min();
	unsigned long long c = a - b;
	unsigned int c2 = a2 - b2;
	long long d = a - b;
	std::cout << typeid(a2 - b2).name() << '\n';
	std::cout << typeid(int).name() << '\n';
	std::cout << typeid(std::type_info).name() << '\n';
	std::cout << "c : " << c << '\n';
	std::cout << "d : " << d << '\n';
	std::cout << "c2 : " << c2 << '\n';
	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(12);
		sp.addNumber(std::numeric_limits<long long>::max());
		sp.addNumber(std::numeric_limits<long long>::min());
		std::cout << sp << '\n';
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception& err) {
		std::cerr << err.what() << '\n';
	}
	return 0;
}