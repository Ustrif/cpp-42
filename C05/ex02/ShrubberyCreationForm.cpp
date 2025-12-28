#include "ShrubberyCreationForm.hpp"
#include <string>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137)
{
	std::cout << "Shrubbery Creation form constructor\n" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation form destructor\n" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
: AForm(other.getName(), other.getGradeSign(), other.getGradeExecute())
{
	std::cout << "Shrubbery Creation form copy constructor\n" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm& other)
{
	if (this != &other)
		AForm::operator=(other);

	std::cout << "Shrubbery Creation form copy assigment operator\n" << std::endl;
	return (*this);
}

const char* ShrubberyCreationForm::FileError::what() const throw()
{
	return ("File open error.");
}

void ShrubberyCreationForm::executeAction() const
{
	std::string outputname = this->getName();
	outputname.append("_shrubbery");

	std::string ascii_three1 =  "       _-_\n"
								"    /~~   ~~\\ \n"
								" /~~         ~~\\\n"
								"{               }\n"
								" \\  _-     -_  /\n"
								"   ~  \\\\ //  ~\n"
								"_- -   | | _- _\n"
								"  _ -  | |   -_\n"
								"      // \\\\\n";

	std::ofstream outFile(outputname.c_str());

	if (!outFile.is_open())
		throw ShrubberyCreationForm::FileError();

	outFile << ascii_three1 << "\n\n *** \n\n" << std::endl;
	outFile << ascii_three1 << "\n\n *** \n\n" << std::endl;

	outFile.close();
}
