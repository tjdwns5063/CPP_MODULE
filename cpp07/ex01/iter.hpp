#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void	iter(T* arr, int len, void (*func)(const T& t)) {
	for (int idx = 0; idx < len; idx++) {
		func(arr[idx]);
	}
}

# endif