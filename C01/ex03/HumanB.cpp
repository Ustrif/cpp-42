#include <string>
#include <iostream>
#include "HumanB.hpp"

void	HumanB::attack()
{
	std::cout	<< this->name
				<< " attacks with their "
				<< this->weapon->getType()
				<< std::endl;
}

HumanB::HumanB(Weapon *weapon)
{
	this->weapon = weapon;
}

HumanB::~HumanB() {}

HumanB::HumanB(std::string name)
{
	this->name = name;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
