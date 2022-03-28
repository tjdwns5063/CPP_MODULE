#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array {
private:
	T*	arr;
	const unsigned int _size;
public:
	Array( void ): _size(0) {
		arr = 0;
	}

	Array( unsigned int n ): _size(n) {
		try {
			arr = new T[n]();
		} catch (std::exception& err) {
			arr = 0;
			std::cout << "Allocate Error!\n";
		}
	}

	~Array( void ) {
		if (arr)
			delete[] (arr);
	}

	Array& operator=( const Array& ref ) {
		if (this == &ref) {
			return (*this);
		}
		if (arr) {
			delete[] (arr);
		}
		try {
			arr = new T[_size]();
			for (unsigned int idx = 0; idx < _size; idx++) {
				arr[idx] = ref[idx];
			}
		} catch (std::bad_alloc& err) {
			arr = 0;
			std::cout << "Allocate Error!\n";
		}
		return (*this);
	}

	Array( const Array& ref ): _size(ref._size) {
		arr = 0;
		*this = ref;
	}

	const T& operator[]( unsigned int idx ) const {
		if (idx >= _size) throw std::out_of_range("this idx is out of range");
		return (arr[idx]);
	}

	T& operator[]( unsigned int idx ) {
		if (idx >= _size) throw std::out_of_range("this idx is out of range");
		return (arr[idx]);
	}

	unsigned int size( void ) const {
		return (_size);
	}
};

template<typename T>
std::ostream& operator<<( std::ostream& os, const Array<T>& ref ) {
	std::cout << "[";
	for (unsigned int idx = 0; idx < ref.size(); idx++) {
		if (idx < ref.size() - 1)
			std::cout << ref[idx] << ", ";
		else
			std::cout << ref[idx];
	}
	std::cout << "]";
	return (os);
}

# endif