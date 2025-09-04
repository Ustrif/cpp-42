#include <iostream>
#include "FragTrap.hpp"
#include <string>

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor" << std::endl;
	setAttackDamage(30);
	setHitPoints(100);
	setEnergyPoints(100);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor" << std::endl;
	setAttackDamage(30);
	setHitPoints(100);
	setEnergyPoints(100);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor.\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap cp.\n";
	setAttackDamage(30);
	setHitPoints(100);
	setEnergyPoints(100);
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (&other != this)
	{
		FragTrap::operator=(other);
	}
	setAttackDamage(30);
	setHitPoints(100);
	setEnergyPoints(100);
	return (*this);
}

void FragTrap::attack(const std::string& target)
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
	std::cout	<< "FragTrap "
				<< getName()
				<< " attacks " 
				<< target
				<< ", causing "
				<< getAttackDamage()
				<< " points of damage!"
				<< std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (getHitPoints() < amount)
	{
		setHitPoints(0);
		std::cout << "FragTrap is dead.\n";
	}
	else
	{
		setHitPoints(getHitPoints() - amount);
		std::cout << "FragTrap took damage. Health: " << getHitPoints() << std::endl;
	}
}

void FragTrap::beRepaired(unsigned int amount)
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
	std::cout	<< "FragTrap "
				<< getName()
				<< " is reapired: "
				<< amount
				<< ".\n";
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "A nice high - Five request !" << std::endl;
}
