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

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other.name), FragTrap(other.name), ScavTrap(other.name)
{
	ClapTrap::name.append("_clap_name");
	DiamondTrap::name = other.name;
	DiamondTrap::attackDamage = other.attackDamage;
	DiamondTrap::hitPoints = other.hitPoints;
	DiamondTrap::energyPoints = other.energyPoints;
	std::cout << "DiamondTrap copy constructor\n";
}

DiamondTrap & DiamondTrap::operator = (const DiamondTrap &other)
{
	ClapTrap::name = other.name;
	ClapTrap::name.append("_clap_name");
	DiamondTrap::name = other.name;
	DiamondTrap::attackDamage = other.attackDamage;
	DiamondTrap::hitPoints = other.hitPoints;
	DiamondTrap::energyPoints = other.energyPoints;
	std::cout << "DiamondTrap copy assigment operator\n";
	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap Name: " << DiamondTrap::name << " ClapTrap Name: " << ClapTrap::name << std::endl;
}

void DiamondTrap::showStatics( void ) const
{
	std::cout << "Statics: "
	<< "Attack Damage: " << this->attackDamage
	<< " Hit Points: " << this->hitPoints
	<< " Energy Points: " << this->energyPoints
	<< std::endl; 
}
