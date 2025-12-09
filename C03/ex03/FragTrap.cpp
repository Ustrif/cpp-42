#include <iostream>
#include "FragTrap.hpp"
#include <string>

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor.\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap cp.\n";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap copy assigment operator" << std::endl;
	if (&other != this)
	{
		FragTrap::operator=(other);
	}
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "A nice high - Five request !" << std::endl;
}
