#include <iostream>
#include <string>
#include "Zombie.hpp"

void	Zombie::announce( void )
{
	std::cout << getName() << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
	_name = name;
}

std::string	Zombie::getName( void )
{
	return (_name);
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << getName() << " is deleted." << std::endl;
}
