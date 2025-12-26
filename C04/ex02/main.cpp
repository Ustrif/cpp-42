#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main( void )
{
	Animal *animal = new Cat(); // new Animal();
	animal->makeSound();
	delete(animal);
	return 0;
}
