#include <iostream>
#include <string>
#include "Harl.hpp"

void	runHarl( int lvl )
{
	Harl harl = Harl();
	switch (lvl)
		{
			case 0:
				harl.complain("DEBUG");
				/* fall through */
			case 1:
				harl.complain("INFO");
				/* fall through */
			case 2:
				harl.complain("WARNING");
				/* fall through */
			case 3:
				harl.complain("ERROR");
				break ;
		}

	return ;
}

int	main(int argc, char *argv[])
{
	if (!argc || !argv || argc != 2)
	{
		std::cout << "Error\nArgument error!\n";
		return (1);
	}
	std::string	level;
	int			lvl;

	level = argv[1];
	if (level == "DEBUG")
		lvl = 0;
    else if (level == "INFO")
		lvl = 1;
    else if (level == "WARNING")
		lvl = 2;
    else if (level == "ERROR")
		lvl = 3;
    else
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (0);
	}
	runHarl(lvl);
	return (0);
}
