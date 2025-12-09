#include <iostream>
#include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	FragTrap *ft = new FragTrap();

	ft->attack("sen");
	ft->beRepaired(91);
	ft->highFivesGuys();
	ft->takeDamage(1);

	delete (ft);

	return (0);
}
