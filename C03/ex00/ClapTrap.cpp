#include <iostream>
#include <string>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor" << std::endl;
	this->name = "name";
	this->attackDamage = 0;
	this->energyPoints = 10;
	this->hitPoints = 10;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor" << std::endl;
	this->name = name;
	this->attackDamage = 0;
	this->energyPoints = 10;
	this->hitPoints = 10;
}

ClapTrap::~ClapTrap() 
{
	std::cout << "ClapTrap destructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy" << std::endl;
	this->name = other.name;
	this->name.append("cp");
	this->hitPoints = other.hitPoints;
	this->attackDamage = other.attackDamage;
	this->energyPoints = other.energyPoints;
}

ClapTrap ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap assingment copy" << std::endl;
	this->name = other.name;
	this->name.append("as");
	this->hitPoints = other.hitPoints;
	this->attackDamage = other.attackDamage;
	this->energyPoints = other.energyPoints;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints > 0 || this->hitPoints == 0)
	{
		this->energyPoints--;
	}
	else
	{
		std::cout << "No energy points.\n";
		return ;
	}
	std::cout	<< "ClapTrap "
				<< this->name
				<< " attacks " 
				<< target
				<< ", causing "
				<< this->attackDamage
				<< " points of damage!"
				<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints < amount)
	{
		std::cout << "ClapTrap " << this->name << " died.\n";
		this->hitPoints = 0;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " took damage: " << amount << ".\n";
		this->hitPoints -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0 || this->hitPoints == 0)
	{
		this->hitPoints += amount;
		this->energyPoints--;
	}
	else
	{
		std::cout << "No energy points.\n";
		return ;
	}
	std::cout	<< "ClapTrap "
				<< this->name
				<< " is reapired: "
				<< amount
				<< ".\n";
}
