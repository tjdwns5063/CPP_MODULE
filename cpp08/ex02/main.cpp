#include <iostream>
#include "MutantStack.hpp"
#include "temp.hpp"

int main(void) {
	{
		Child<int> c;

		c.begin();
	}
	{
		std::cout << "------------test1-----------\n\n";
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		MutantStack<int> s(mstack);
		s.push(1000);
		std::cout << s << '\n';
		std::cout << mstack << '\n';
	}
	{
		std::cout << "\n--------------test2-----------\n\n";
		MutantStack<int> ms;

		ms.push(5);
		ms.push(10);
		ms.push(13);
		ms.push(1);

		std::cout << "------using iterator------\n\n";
		for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); it++) {
			std::cout << *it << '\n';
		}
		std::cout << "\n------using const_iterator------\n\n";
		std::cout << *ms.cbegin() << '\n';
		std::cout << *(ms.cend() - 1) << '\n';

		std::cout << "\n------using reverse_iterator------\n\n";
		for (MutantStack<int>::reverse_iterator rit = ms.rbegin(); rit != ms.rend(); rit++) {
			std::cout << *rit << '\n';
		}

		std::cout << "------using const_reverse_iterator------\n\n";
		std::cout << *ms.crbegin() << '\n';
		std::cout << *(ms.crend() - 1) << '\n';
	}
}