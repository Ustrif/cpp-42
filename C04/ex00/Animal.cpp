#include <string>
#include <iostream>
#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default constructor for Animal.\n";
	this->setType("Animal");
}

Animal::Animal(std::string type)
{
	std::cout << "Constructor with param for Animal\n";
	this->setType(type);
}

Animal::~Animal()
{
	std::cout << "Destructor for Animal\n";
}

Animal::Animal(const Animal &other)
{
	std::cout << "Copy constructor for Animal\n";
	this->setType(other.getType());
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Copy assigment constructor for Animal\n";
	this->setType(other.getType());
	return (*this);
}

void Animal::setType(std::string type)
{
	this->type = type;
}

std::string Animal::getType( void ) const
{
	return (this->type);
}

void Animal::makeSound( void ) const
{
	std::cout << "You can hear a " << this->getType() << " sound, now.\n";
}
