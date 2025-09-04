#include <iostream>
#include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	ScavTrap *st = new ScavTrap("ScavHeap");

	st->attack("ben");
	st->beRepaired(30);
	st->guardGate();
	st->takeDamage(10000);
	delete (st);

	std::cout << "---\n";

	FragTrap *ft = new FragTrap();
	ft->attack("sen");
	ft->beRepaired(91);
	ft->highFivesGuys();
	ft->takeDamage(1);
	delete (ft);

	return (0);
}
