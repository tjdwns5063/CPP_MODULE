#include <iostream>

void	convert_alphabet_upper_case(std::string &str)
{
	int	len;

	len = str.length();
	for (int idx = 0; idx < len; idx++)
		str[idx] = std::toupper(str[idx]);
}

void	print_arg(char **argv)
{
	int			idx;
	std::string	str;

	idx = 1;
	while (argv[idx])
	{
		str = argv[idx];
		convert_alphabet_upper_case(str);
		std::cout << str;
		idx++;
	}
	std::cout << '\n';
}

int	main(int argc, char **argv)
{
	try {
		if (argc < 2) throw 0;
		print_arg(argv);
	}	catch (int except) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
	}
}