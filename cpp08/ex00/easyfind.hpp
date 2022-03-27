#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>

template<typename T>
typename T::iterator	easyfind(T& container, int num) {
	typename T::iterator begin = container.begin();
	typename T::iterator end = container.end();

	for (; begin != end; begin++) {
		if (*begin == num) {
			return (begin);
		}
	}
	return (end);
}

# endif