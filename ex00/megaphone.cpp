#include <iostream>

int	main(int argc, char *args[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; args[i]; i++)
		{
			for(int j = 0; args[i][j]; j++)
				std::cout << (char) std::toupper(args[i][j]);
		}
		std::cout << std::endl;
	}
	return (0);
}
