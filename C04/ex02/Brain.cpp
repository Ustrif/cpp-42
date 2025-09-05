#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Default constructor for Brain class.\n";
}

Brain::~Brain()
{
	std::cout << "Destructor for Brain class.\n";
}

Brain::Brain(const Brain &other)
{
	std::cout << "Copy contructor for Brain.\n";
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Copy assigment operator for Brain.\n";
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
	return (*this);
}
