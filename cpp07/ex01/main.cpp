#include "iter.hpp"
#include <iostream>

template<typename T>
void print(const T& t) {
	std::cout << t << '\n';
}

int main(void) {
	int arr[5] = {0, 1, 2, 3, 4};
	char arr2[6] = "Hello";

	iter(arr, sizeof(arr) / sizeof(int), print);
	iter(arr2, sizeof(arr2) / sizeof(char), print);
}
