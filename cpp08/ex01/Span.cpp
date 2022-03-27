#include <algorithm>
#include <limits>
#include "Span.hpp"

Span::Span( unsigned int _capacity ) {
	data.reserve(_capacity);
	size = 0;
}

Span::~Span( void ) {

}

Span::Span( const Span& ref ) {
	*this = ref;
}

Span& Span::operator=( const Span& ref ) {
	data.reserve(ref.data.capacity());
	std::copy(ref.data.begin(), ref.data.end(), std::back_inserter(data));
	size = ref.size;
	return (*this);
}

std::vector<int> Span::getData( void ) const {
	return (data);
}

void Span::addNumber( int num ) {
	if (data.capacity() > data.size()) {
		data.push_back(num);
		size++;
	} else
		throw std::runtime_error("storage is already full");
}

unsigned long Span::longestSpan( void ) const {
	int largestNum = data[0];
	int smallestNum = data[0];
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
	std::vector<int> temp = data;
	unsigned long span = std::numeric_limits<unsigned long>::max();
	unsigned long compare = 0;

	std::sort(temp.begin(), temp.end());
	for (unsigned long leftIdx = 0; leftIdx < temp.size() - 1; leftIdx++) {
		unsigned long rightIdx = leftIdx + 1;

		compare = temp[rightIdx] - temp[leftIdx];
		span = std::min(span, compare);
	}
	return (span);
}

std::ostream& operator<<( std::ostream& os, const Span& span ) {
	std::vector<int> temp = span.getData();

	for (std::vector<int>::iterator it = temp.begin(); it != temp.end(); it++) {
		std::cout << *it << ' ';
	}
	return (os);
}