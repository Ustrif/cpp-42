#include <iostream>
#include <string>
#include "Zombie.hpp"

void	Zombie::randomChump( std::string name )
{
	Zombie	*zombie;
	zombie = new Zombie(name);
	zombie->announce();
	delete (zombie);
}
