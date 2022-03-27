#ifndef TEMP_HPP
# define TEMP_HPP

#include <deque>

template<typename T>
class Temp {
protected:
	std::deque<T> c;
	int num;
public:
	Temp() {num = 3;}
	~Temp() {}
};

template<typename T>
class Child: Temp<T> {
public:
	typedef typename std::deque<T>::iterator
		iterator;
	
	iterator begin( void ) {
		std::cout << "abc\n";
		std::cout << this->num << '\n';
		return (this->c.begin());
	}
};

# endif