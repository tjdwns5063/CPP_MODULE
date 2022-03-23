#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap(T& t1, T& t2) {
	T temp = t1;

	t1 = t2;
	t2 = temp;
}

template<typename T>
T	min(T& t1, T& t2) {
	if (t1 > t2) {
		return (t2);
	} else {
		return (t1);
	}
}

template<typename T>
T	max(T& t1, T& t2) {
	if (t1 > t2) {
		return (t1);
	} else {
		return (t2);
	}
}


# endif