#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog() : Animal()
{
	std::cout << "Default constructor for Dog.\n";
	this->setType("Dog");
}

Dog::~Dog()
{
	std::cout << "Destructor for Dog\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
	this->setType(other.getType());
	std::cout << "Dog copy constructor\n";
}

Dog &Dog::operator=(const Dog &other)
{
	if (this == &other)
	{
		std::cout << "No self assigment.\n";
    	return (*this);
	}
	this->setType(other.getType());
	std::cout << "Dog assigment operator\n";
	return (*this);
}

void Dog::makeSound( void ) const
{
	std::cout << "Hav, Hav!\n";
}
