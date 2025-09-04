#include <iostream>
#include <string>
#include "Animal.hpp"

int	main( void )
{
	Animal *animal = new Animal("dog");
	animal->makeSound();
	delete(animal);

	return (0);
}
