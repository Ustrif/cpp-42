#include <iostream>
#include "HumanA.hpp"
#include <string>

void	HumanA::attack()
{
	std::cout	<< this->name
				<< " attacks with their "
				<< weapon.getType()
				<< std::endl;
}

HumanA::HumanA(Weapon &weapon) : weapon(weapon) {}

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon) 
{
	this->name = name;
}

HumanA::~HumanA() {}

void	HumanA::setWeapon(Weapon &weapon)
{
	this->weapon = weapon;
}
