#ifndef __HUMAN_A_HPP
#define __HUMAN_A_HPP

#include <iostream>
#include "Weapon.hpp"
#include <string>

class HumanA 
{
	private:
		Weapon	&weapon;
		std::string	name;
	public:
		void	attack();
		HumanA(Weapon &weapon);
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void	setWeapon(Weapon &weapon);
};

#endif // __HUMAN_A_HPP
