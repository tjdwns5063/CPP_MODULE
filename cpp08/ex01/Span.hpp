#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

class Span {
private:
	std::vector<int> data;
	unsigned long size;
	Span( void );

public:
	Span( unsigned int _capacity );
	Span( const Span& ref );
	Span& operator=( const Span& ref );
	~Span( void );
	template <typename T>
	void addNumber( const T begin, const T end ) {
		for (T it = begin; it != end; it++) {
			if (data.size() < data.capacity()) {
				data.push_back(*it);
			} else {
				throw std::runtime_error("storage is already full");
			}
		}
	}
	void addNumber( int num );
	std::vector<int> getData( void ) const;
	unsigned long longestSpan( void ) const;
	unsigned long shortestSpan( void ) const;
};

std::ostream& operator<<( std::ostream& os, const Span& span );

# endif