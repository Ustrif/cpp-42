#include <iostream>
#include <string>

int	main( void )
{
	std::string	phrase = "HI THIS IS BRAIN";
	std::string	*stringPTR = &phrase;
	std::string	&stringREF = phrase;

	std::cout << "The memory address of the string variable: " << &phrase << std::endl;
	std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;
	std::cout << "-----------------------------------------------------------\n";
	std::cout << "The value of the string variable: " << phrase << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;

	return (0);
}
