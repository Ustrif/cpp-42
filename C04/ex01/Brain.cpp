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

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
	{
		ideas[index] = idea;
	}
}

void Brain::displayIdeas() const
{
	for (int i = 0; i < 100; ++i)
	{
		if (!ideas[i].empty())
			std::cout << "idea " << i << ": " << ideas[i] << "\n";
	}
}
