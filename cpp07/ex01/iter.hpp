#ifndef ITER_HPP
# define ITER_HPP

#include "iostream"

template <typename T, int L>
void	iter( T (&arr)[L], int len, void (*func)(const T&) ) {
	for (int idx = 0; idx < len; idx++) {
		if (idx >= L) {
			std::cout << "index is out of range\n";
			return ;
		}
		func(arr[idx]);
	}
}

# endif