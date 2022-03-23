#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array {
private:
	T*	arr;
	const unsigned int _size;
public:
	Array( void ) {
		arr = NULL;
	}

	Array( unsigned int n ): _size(n) {
		arr = new T[n]();
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
			//delete[] (arr);
		}
		arr = new T[_size]();
		return (*this);
	}

	Array( const Array& ref ): _size(ref._size) {
		*this = ref;
	}

	T& operator[]( unsigned int idx ) const {
		if (idx >= _size) throw std::out_of_range("this idx is out of range");
		return (arr[idx]);
	}

	unsigned int size( void ) const {
		return (_size);
	}
};

template<typename T>
std::ostream& operator<<( std::ostream& os, const Array<T>& ref ) {
	for (unsigned int idx = 0; idx < ref.size(); idx++) {
		std::cout << ref[idx] << '\n';
	}
	return (os);
}

# endif