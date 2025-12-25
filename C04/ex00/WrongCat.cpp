#include "WrongCat.hpp"
#include <iostream>
#include <string>

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "Default constructor for WrongCat.\n";
	this->setType("WrongCat");
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor for WrongCat\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	this->setType(other.getType());
	std::cout << "WrongCat copy constructor\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this == &other)
	{
		std::cout << "No self assigment.\n";
    	return (*this);
	}
	this->setType(other.getType());
	std::cout << "WrongCat assigment operator\n";
	return (*this);
}

void WrongCat::makeSound( void ) const
{
	std::cout << "Miav, Miyav!\n";
}
