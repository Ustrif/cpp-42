#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat() : Animal()
{
	std::cout << "Default constructor for Cat.\n";
	this->setType("default-Cat");
}

Cat::~Cat()
{
	std::cout << "Destructor for Cat\n";
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat constructor with param\n";
	this->setType(type);
}

Cat::Cat(const Cat &other) : Animal(other)
{
	this->setType(other.getType());
	std::cout << "Cat copy constructor\n";
}

Cat &Cat::operator=(const Cat &other)
{
	if (this == &other)
	{
		std::cout << "No self assigment.\n";
    	return (*this);
	}
	this->setType(other.getType());
	std::cout << "Cat assigment operator\n";
	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << "Miav, Miyav!\n";
}
