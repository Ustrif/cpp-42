#include <iostream>
#include <string>
#include "Harl.hpp"

int	main( void )
{
	std::string	line;
	Harl	harl = Harl();

	while (1)
	{
		std::cout << "Enter Harl Level!:\n";
		std::getline(std::cin, line);
		harl.complain(line);
		if (line.size() <= 0)
			break;
	}
	return (0);
}
