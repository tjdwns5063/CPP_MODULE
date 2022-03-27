#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array {
private:
	T*	arr;
	const unsigned long _size;
	bool _fail;
public:
	Array( void ): _size(0) {
		arr = 0;
		_fail = false;
	}

	Array( unsigned long n ): _size(n) {
		try {
			arr = new T[n]();
		} catch (std::exception& err) {
			arr = 0;
			_fail = true;
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
		} catch (std::bad_alloc& err) {
			arr = 0;
			_fail = true;
			std::cout << "Allocate Error!\n";
		}
		return (*this);
	}

	Array( const Array& ref ): _size(ref._size) {
		arr = 0;
		*this = ref;
	}

	T& operator[]( unsigned long idx ) const {
		if (idx >= _size) throw std::out_of_range("this idx is out of range");
		return (arr[idx]);
	}

	unsigned int size( void ) const {
		return (_size);
	}

	bool	fail( void ) const {
		return (_fail);
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