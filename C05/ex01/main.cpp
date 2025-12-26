#include "Bureaucrat.hpp"
#include <iostream>
#include "Form.hpp"
#include <string>

void	tester(std::string str, int sing, int exec, Bureaucrat *br)
{
	Form	*form;
	
	std::cout << "---" << std::endl;
	try
	{
		form = new Form(str, sing, exec);
	}
	catch(const std::exception& e)
	{
		std::cout << "ERROR TO CREATE FORM: ";
		std::cout << e.what() << std::endl;
		std::cout << "---" << std::endl;
		return ;
	}
	try
	{
		std::cout << *form << std::endl;
		br->signForm(*form);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << *form << std::endl;
	delete(form);
	std::cout << "---" << std::endl;	
}

int	main ( void )
{
	Bureaucrat *br = new Bureaucrat("20LVL", 20);
	tester("FORM1", 20, 20, br);
	tester("FORM2", 5, 5, br);
	tester("FORM3", 100, 100, br);
	tester("FORMUP", 200, 200, br);
	tester("FORMDOWN", -1, -1, br);
	delete(br);
	return (0);
}
