#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat() : Animal()
{
	std::cout << "Default constructor for Cat.\n";
	this->setType("Cat");
	this->brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Destructor for Cat\n";
	delete(this->brain);
}

Cat::Cat(const Cat &other) : Animal(other)
{
	this->setType(other.getType());
	std::cout << "Cat copy constructor\n";
	this->brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other)
{
	if (this == &other)
	{
		std::cout << "No self assigment.\n";
    	return (*this);
	}
	this->setType(other.getType());
	delete(this->brain);
	this->brain = new Brain(*other.brain);
	std::cout << "Cat assigment operator\n";
	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << "Miav, Miyav!\n";
}

Brain* Cat::getBrainAddress() const
{
	return (this->brain);
}
