#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack: public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator
		iterator;
	typedef typename std::stack<T>::container_type::const_iterator
		const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator
		reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator
		const_reverse_iterator;

	iterator begin( void ) {
		return (this->c.begin());
	}

	const_iterator begin( void ) const {
		return (static_cast<const_iterator>(this->c.begin()));
	}

	iterator end( void ) {
		return (this->c.end());
	}

	const_iterator end( void ) const {
		return (static_cast<const_iterator>(this->c.end()));
	}

	reverse_iterator rbegin( void ) {
		return (this->c.rbegin());
	}

	const_reverse_iterator rbegin( void ) const {
		return (static_cast<const_reverse_iterator>(this->c.rbegin()));
	}

	reverse_iterator rend( void ) {
		return (this->c.rend());
	}

	const_reverse_iterator rend( void ) const {
		return (static_cast<const_reverse_iterator>(this->c.rend()));
	}

	MutantStack( void ) {};
	~MutantStack( void ) {};
	MutantStack& operator=( const MutantStack& ref ) {
		this->c = ref.c;
		return (*this);
	}
	MutantStack( const MutantStack& ref ) {
		*this = ref;
	}
};

std::ostream& operator<<( std::ostream& os, MutantStack<int>& ms ) {
	for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); it++) {
		std::cout << *it << ' ';
	}
	return (os);
}

# endif