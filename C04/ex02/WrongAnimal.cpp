#include <string>
#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default constructor for WrongAnimal.\n";
	this->setType("WrongAnimal");
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor for WrongAnimal\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "Copy constructor for WrongAnimal\n";
	this->setType(other.getType());
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "Copy assigment constructor for WrongAnimal\n";
	this->setType(other.getType());
	return (*this);
}

void WrongAnimal::setType(std::string type)
{
	this->type = type;
}

std::string WrongAnimal::getType( void ) const
{
	return (this->type);
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "You can hear a " << this->getType() << " sound, now.\n";
}
