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
		this->hitPoints = 0;
	else
		this->hitPoints -= amount;
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

void ClapTrap::setHitPoints(unsigned int amount)
{
	this->hitPoints = amount;
}

void ClapTrap::setEnergyPoints(unsigned int amount)
{
	this->energyPoints = amount;
}

void ClapTrap::setAttackDamage(unsigned int amount)
{
	this->attackDamage = amount;
}

unsigned int ClapTrap::getHitPoints()
{
	return (this->hitPoints);
}

unsigned int ClapTrap::getEnergyPoints()
{
	return (this->energyPoints);
}

unsigned int ClapTrap::getAttackDamage()
{
	return (this->attackDamage);
}

std::string ClapTrap::getName()
{
	return (this->name);
}

void ClapTrap::setName(std::string name)
{
	this->name = name;
}
