#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"

int main(void) {
	std::vector<int> v1;
	std::list<int> l1;
	std::deque<int> dq1;

	for (int i = 0; i < 5; i++) {
		v1.push_back(i + 1);
		l1.push_back(i + 1);
		dq1.push_back(i + 1);
	}
	try {
		std::cout << *easyfind(v1, 3) << '\n';
		std::cout << *easyfind(l1, 2) << '\n';
		std::cout << *easyfind(dq1, 7) << '\n';
	} catch (std::exception& err) {
		std::cout << err.what() << '\n';
	}
}