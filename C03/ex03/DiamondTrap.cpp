#include <iostream>
#include <string>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	ClapTrap::name.append("default_clap_name");
	DiamondTrap::name = "default";
	DiamondTrap::attackDamage = 30;
	DiamondTrap::hitPoints = 100;
	DiamondTrap::energyPoints = 50;
	std::cout << "DiamondTrap default constructor\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	ClapTrap::name.append("_clap_name");
	DiamondTrap::name = name;
	DiamondTrap::attackDamage = 30;
	DiamondTrap::hitPoints = 100;
	DiamondTrap::energyPoints = 50;
	std::cout << "DiamondTrap constructor with param \n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other.getName()), FragTrap(other.getName()), ScavTrap(other.getName())
{
	ClapTrap::name.append("_clap_name");
	DiamondTrap::name = other.getName();
	DiamondTrap::attackDamage = other.getAttackDamage();
	DiamondTrap::hitPoints = other.getHitPoints();
	DiamondTrap::energyPoints = other.getEnergyPoints();
	std::cout << "DiamondTrap copy constructor\n";
}

DiamondTrap & DiamondTrap::operator = (const DiamondTrap &other)
{
	ClapTrap::name = other.getName();
	ClapTrap::name.append("_clap_name");
	DiamondTrap::name = other.getName();
	DiamondTrap::attackDamage = other.getAttackDamage();
	DiamondTrap::hitPoints = other.getHitPoints();
	DiamondTrap::energyPoints = other.getEnergyPoints();
	std::cout << "DiamondTrap copy assigment operator\n";
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
	std::cout << "DiamondTrap " << DiamondTrap::name << " attack with ScavTrap side\n";
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints < amount)
	{
		this->hitPoints = 0;
		std::cout << "DiamondTrap " << DiamondTrap::name << " died.\n";
	}
	else
	{
		this->hitPoints -= amount;
		std::cout << "DiamondTrap " << DiamondTrap::name << " took damage " << amount << " points.\n";
	}
}

void	DiamondTrap::beRepaired(unsigned int amount)
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
	std::cout	<< "DiamondTrap "
				<< this->name
				<< " is reapired: "
				<< amount
				<< ".\n";
}

std::string	DiamondTrap::getName( void ) const
{
	return (DiamondTrap::name);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap Name: " << DiamondTrap::name << " ClapTrap Name: " << ClapTrap::name << std::endl;
}

void DiamondTrap::setHitPoints(unsigned int amount)
{
	this->hitPoints = amount;
}

void DiamondTrap::setEnergyPoints(unsigned int amount)
{
	this->energyPoints = amount;
}

void DiamondTrap::setAttackDamage(unsigned int amount)
{
	this->attackDamage = amount;
}

unsigned int DiamondTrap::getHitPoints() const
{
	return (this->hitPoints);
}

unsigned int DiamondTrap::getEnergyPoints() const
{
	return (this->energyPoints);
}

unsigned int DiamondTrap::getAttackDamage() const
{
	return (this->attackDamage);
}

void DiamondTrap::setName(std::string name)
{
	this->name = name;
}

void DiamondTrap::showStatics( void ) const
{
	std::cout << "Statics: "
	<< "Attack Damage: " << this->getAttackDamage()
	<< " Hit Points: " << this->getHitPoints()
	<< " Energy Points: " << this->getEnergyPoints()
	<< std::endl; 
}
