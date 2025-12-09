#include <iostream>
#include <string>
#include "DiamondTrap.hpp"

int main( void )
{
	DiamondTrap	*diamondTrap = new DiamondTrap("r");

	diamondTrap->showStatics();
	diamondTrap->attack("other one diamond trap");
	diamondTrap->highFivesGuys();
	diamondTrap->guardGate();
	diamondTrap->beRepaired(100);
	diamondTrap->takeDamage(35);
	diamondTrap->showStatics();
	diamondTrap->whoAmI();

	delete (diamondTrap);
	return (0);
}
