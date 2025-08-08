#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string	type;
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		const std::string	&getType();
		void	setType(std::string newValue);
};

#endif // __WEAPON_HPP__