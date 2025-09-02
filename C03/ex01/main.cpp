#include <iostream>
#include <string>
#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap	ct("R");

	ct.attack("Merhaba");
	ct.beRepaired(1);
	ct.takeDamage(3);
	return 0;
}
