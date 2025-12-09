#include <iostream>
#include "ScavTrap.hpp"
#include <string>

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor.\n";
}


ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap cp.\n";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assigment operator" << std::endl;
	if (&other != this)
	{
		ClapTrap::operator=(other);
	}
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	return (*this);
}

void ScavTrap::guardGate()
{
	std::cout << "GateKeeper mode on.\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (this->energyPoints > 0 && this->hitPoints != 0)
	{
		this->energyPoints -= 1;
	}
	else
	{
		std::cout << "No energy points.\n";
		return ;
	}
	std::cout	<< "ScavTrap "
				<< this->name
				<< " attacks " 
				<< target
				<< ", causing "
				<< this->attackDamage
				<< " points of damage!"
				<< std::endl;
}
