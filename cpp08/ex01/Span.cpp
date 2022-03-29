#include <algorithm>
#include <limits>
#include <iostream>
#include "Span.hpp"

Span::Span( unsigned int _capacity ) {
	data.reserve(_capacity);
}

Span::~Span( void ) {

}

Span::Span( const Span& ref ) {
	*this = ref;
}

Span& Span::operator=( const Span& ref ) {
	data.reserve(ref.data.capacity());
	std::copy(ref.data.begin(), ref.data.end(), std::back_inserter(data));
	return (*this);
}

std::vector<long long> Span::getData( void ) const {
	return (data);
}

void Span::addNumber( long long num ) {
	if (data.capacity() > data.size()) {
		data.push_back(num);
	} else
		throw std::runtime_error("storage is already full");
}

unsigned long Span::longestSpan( void ) const {
	long long largestNum = data[0];
	long long smallestNum = data[0];
	unsigned long span = 0;

	if (data.size() < 2)
		throw std::runtime_error("item is not enough");

	for (unsigned int idx = 0; idx < data.size(); idx++) {
		largestNum = std::max(largestNum, data[idx]);
		smallestNum = std::min(smallestNum, data[idx]);
	}
	span = largestNum - smallestNum;
	return (span);
}

unsigned long Span::shortestSpan( void ) const {
	std::vector<long long> temp = data;
	unsigned long long span = std::numeric_limits<unsigned long long>::max();
	unsigned long long compare = 0;

	std::sort(temp.begin(), temp.end());
	for (unsigned long leftIdx = 0; leftIdx < temp.size() - 1; leftIdx++) {
		unsigned long rightIdx = leftIdx + 1;

		compare = temp[rightIdx] - temp[leftIdx];
		span = std::min(span, compare);
	}
	return (span);
}

std::ostream& operator<<( std::ostream& os, const Span& span ) {
	std::vector<long long> temp = span.getData();

	std::cout << "[";
	for (std::vector<long long>::iterator it = temp.begin(); it != temp.end(); it++) {
		if (it + 1 !=  temp.end())
			std::cout << *it << ", ";
		else
			std::cout << *it;
	}
	std::cout << "]";
	return (os);
}