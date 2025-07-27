#include <iostream>
#include <string>
#include "Zombie.hpp"

int	main(void)
{
	Zombie	*heap;
	heap = new Zombie("heap");
	heap->announce();
	delete (heap);
	Zombie	stack("stack");
	stack.randomChump("random");
	return (0);
}
