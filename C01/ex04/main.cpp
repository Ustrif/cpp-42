#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	if (argc != 4 || !argv)
	{
		std::cout << "Invalid arguments.\n";
		return (1);
	}
	return 0;
}
