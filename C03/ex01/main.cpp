#include <iostream>
#include <string>
#include "ScavTrap.hpp"

int main( void )
{
	ScavTrap	st("onion");

	st.guardGate();
	st.attack("xx");
	st.takeDamage(38);
	st.beRepaired(20);
	st.takeDamage(1000);
	return 0;
}
