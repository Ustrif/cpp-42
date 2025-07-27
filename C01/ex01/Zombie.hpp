#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <iostream>
#include <string>

class	Zombie;

Zombie*	zombieHorde( int N, std::string name );

class	Zombie
{
	public:
		void	announce( void );
		Zombie*	newZombie( std::string name );
		void	randomChump( std::string name );
		Zombie(std::string name);
		Zombie() {}
		~Zombie();
		std::string	getName( void );
		void	setName(std::string name);
	private:
		std::string	_name;
};

#endif // __ZOMBIE_HPP__
