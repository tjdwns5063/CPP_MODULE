#include <iostream>

int	main(void) {
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "--------------display memory address of string---------------\n";
	std::cout << "using string var : " << &string << '\n';
	std::cout << "using PTR var : " << stringPTR << '\n';
	std::cout << "using REF var : " << &stringREF << '\n';
	std::cout << "---------------------display string--------------------------\n";
	std::cout << "using string var : " << string << '\n';
	std::cout << "using PTR var : " << *stringPTR << '\n';
	std::cout << "using REF var : " << stringREF << '\n';
}