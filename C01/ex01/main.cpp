#include <iostream>
#include <string>
#include "Zombie.hpp"

int	main( void )
{
	Zombie	*zombies;
	int		size;
	
	size = 5;
	try
		{zombies = zombieHorde(size, "resuls");}
	catch(const std::bad_alloc& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << i + 1 << ": ";
		zombies[i].announce();
	}
	delete[] (zombies);
	return (0);
}
