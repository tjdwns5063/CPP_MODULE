#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <exception>

template <typename T>
long long	easyfind(T container, long long num) {
	typename T::iterator ret;

	ret = std::find(container.begin(), container.end(), num);
	if (ret == container.end())
		throw std::runtime_error("cannot find this item");
	return (*ret);
}

# endif