#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <iostream>
#include <string>

class	Zombie
{
	public:
		void	announce( void );
		Zombie*	newZombie( std::string name );
		void	randomChump( std::string name );
		Zombie(std::string name);
		~Zombie();
		std::string	getName( void );
	private:
		std::string	_name;
		Zombie();
};

#endif // __ZOMBIE_HPP__
