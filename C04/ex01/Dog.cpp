#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog() : Animal()
{
	std::cout << "Default constructor for Dog.\n";
	this->setType("default-dog");
	this->brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Destructor for Dog\n";
	delete(this->brain);
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Dog constructor with param\n";
	this->setType(type);
	this->brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
	this->setType(other.getType());
	std::cout << "Dog copy constructor\n";
	this->brain = new Brain();
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
