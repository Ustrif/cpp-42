#include "Bureaucrat.hpp"
#include <iostream>

void	tester(std::string str, int param)
{
	Bureaucrat *br;

	std::cout << "---" << std::endl;
	try
	{
		br = new Bureaucrat(str, param);
		std::cout << *br << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return ;
	}
	try
	{
		br->gradeDecrement();
		std::cout << *br << std::endl;
		br->gradeIncrement();
		br->gradeIncrement();
		std::cout << *br << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << *br << std::endl;
	}
	delete(br);
	std::cout << "---" << std::endl;
}

int	main ( void )
{
	tester("LOW", -1);
	tester("HIGH", 200);
	tester("NO ERR", 50);
	tester("UP LIMIT", 150);
	tester("DOWN LIMIT", 1);
	return (0);
}
