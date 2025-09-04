#include <iostream>
#include "ScavTrap.hpp"
#include <string>

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor" << std::endl;
	setAttackDamage(20);
	setHitPoints(100);
	setEnergyPoints(50);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor" << std::endl;
	setAttackDamage(20);
	setHitPoints(100);
	setEnergyPoints(50);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor.\n";
}


ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap cp.\n";
	setAttackDamage(20);
	setHitPoints(100);
	setEnergyPoints(50);
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (&other != this)
	{
		ClapTrap::operator=(other);
	}
	setAttackDamage(20);
	setHitPoints(100);
	setEnergyPoints(50);
	return (*this);
}

void ScavTrap::guardGate()
{
	std::cout << "GateKeeper mode on.\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (getEnergyPoints() > 0 && getHitPoints() != 0)
	{
		setEnergyPoints(getEnergyPoints() - 1);
	}
	else
	{
		std::cout << "No energy points.\n";
		return ;
	}
	std::cout	<< "ScavTrap "
				<< getName()
				<< " attacks " 
				<< target
				<< ", causing "
				<< getAttackDamage()
				<< " points of damage!"
				<< std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (getHitPoints() < amount)
	{
		setHitPoints(0);
		std::cout << "ScavTrap is dead.\n";
	}
	else
	{
		setHitPoints(getHitPoints() - amount);
		std::cout << "ScavTrap took damage. Health: " << getHitPoints() << std::endl;
	}
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (getEnergyPoints() > 0)
	{
		setHitPoints(getHitPoints() + amount);
		setEnergyPoints(getEnergyPoints() - 1);
	}
	else
	{
		std::cout << "No energy points.\n";
		return ;
	}
	std::cout	<< "ScavTrap "
				<< getName()
				<< " is reapired: "
				<< amount
				<< ".\n";
}
