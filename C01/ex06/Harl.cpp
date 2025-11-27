#include <iostream>
#include <string>
#include "Harl.hpp"

Harl::Harl() 
{
	std::cout << "Here we go again. -Harl\n";
}

Harl::~Harl() 
{
	std::cout << "It's time to go. -Harl\n";
}

void	Harl::debug( void )
{
	std::string	str;
	str = "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
	std::cout << str << std::endl;
}

void	Harl::info( void )
{
	std::string	str;
	str = "[ INFO ]\nI cannot believe adding extra bacon costs more money.";
	str.append("You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!");
	std::cout << str << std::endl;
}

void	Harl::warning( void )
{
	std::string	str;
	str = "[ WARNING ]\nI think I deserve to have some extra bacon for free.";
	str.append("I’ve been coming for years, whereas you started working here just last month.");
	std::cout << str << std::endl;
}

void	Harl::error( void )
{
	std::string	str;
	str = "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.";
	std::cout << str << std::endl;
}

void	Harl::complain(std::string level)
{
	int	i;

	i = 0;
	std::string	levelList[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*adressList[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	while (i < 4)
	{
		if (levelList[i] == level)
		{
			(this->*adressList[i])();
			break;
		}
		i++;
	}
}
