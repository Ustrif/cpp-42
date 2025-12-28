#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	tester(std::string str, Bureaucrat *br, int formtype)
{
	AForm	*form;

	std::cout << "---" << std::endl;
	try
	{
		switch (formtype)
		{
		case 1:
			form = new PresidentialPardonForm(str);
			break;
		case 2:
			form = new RobotomyRequestForm(str);
			break;
		default:
			form = new ShrubberyCreationForm(str);
			break;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << "ERROR TO CREATE FORM: ";
		std::cout << e.what();
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
	try
	{
		std::cout << "\n<<<>>>\n" << std::endl;
		br->executeForm(*form);
		std::cout << "\n<<<>>>\n" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << *form << std::endl;
	delete(form);
	std::cout << "---" << std::endl;
}

void	file_test( void )
{
	std::cout << std::endl << "FILE TEST BEGIN" << std::endl;

	AForm* f;
	try
	{
		Bureaucrat a("1LVL", 1);
		f = new ShrubberyCreationForm("/root/forbidden_file");
		f->beSigned(a);
		f->execute(a);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	delete(f);
	std::cout << std::endl << "FILE TEST END" << std::endl;
}

int	main ( void )
{
	Bureaucrat *br = new Bureaucrat("20LVL", 20);
	tester("20 - FORM1", br, 1);
	tester("20 - FORM2", br, 2);
	tester("20 - FORM3", br, 3);
	delete(br);

	std::cout << "\n***\n";

	br = new Bureaucrat("150LVL", 150);
	tester("150 - FORM1", br, 1);
	tester("150 - FORM2", br, 2);
	tester("150 - FORM3", br, 3);
	delete(br);

	std::cout << "\n***\n";

	br = new Bureaucrat("1LVL", 1);
	tester("1 - FORM1", br, 1);
	tester("1 - FORM2", br, 2);
	tester("1 - FORM3", br, 3);
	delete(br);

	file_test();

	return (0);
}
