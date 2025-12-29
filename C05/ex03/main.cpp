#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void	test_cpp(Intern& intern, std::string formName, std::string formTarget)
{
	AForm* rrf;

	try
	{
		rrf = intern.makeForm(formName, formTarget);
		std::cout << *rrf << std::endl;
		delete (rrf);
	}
	catch (std::exception& e)
	{
		std::cout << "Intern couldn't create a Form because " << e.what() << std::endl;
	}

	std::cout << "***" << std::endl;
}

int	main ( void )
{
	Intern someRandomIntern;

	test_cpp(someRandomIntern, "robotomy request", "Bender");
	test_cpp(someRandomIntern, "presidential", "X");
	test_cpp(someRandomIntern, "ShrubberyCreationForm", "Y");
	test_cpp(someRandomIntern, "", "");
	test_cpp(someRandomIntern, "ax", "ax");

	return (0);
}
