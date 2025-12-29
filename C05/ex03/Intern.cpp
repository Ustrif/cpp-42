#include "Intern.hpp"

Intern::Intern()
{
	number = 0;
	std::cout << "Default Constructor for Intern" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Destructor for Intern" << std::endl;
}

Intern::Intern(const Intern& other)
{
	this->number = other.getNumber();
	std::cout << "Copy Constructor for Intern" << std::endl;
}

Intern &Intern::operator = (const Intern& other)
{
	this->setNumber(other.getNumber());
	std::cout << "Copy Assigment Operator for Intern" << std::endl;

	return (*this);
}

int	Intern::getNumber( void ) const 
{
	return (this->number);
}

void	Intern::setNumber( int num )
{
	this->number = num;
}

const char* Intern::NoNameError::what() const throw()
{
	return ("No name given.");
}

const char* Intern::UndefinedNameError::what() const throw()
{
	return ("Given name is undefined.");
}

static std::string	getLower(std::string sentence)
{
	std::string x;
	char		character[2];

	for (std::size_t i = 0; i < sentence.size(); i++)
	{
		character[0] =  std::tolower(sentence.at(i));
		character[1] = '\0';
		x.append(character);
	}
	return (x);
}

AForm* Intern::makeForm(std::string formName, std::string formTarget)
{
	const std::string forms[FORM_NUM] = {
								"PresidentialPardonForm",
								"RobotomyRequestForm",
								"ShrubberyCreationForm"
								};

	if (formName.empty() || formTarget.empty())
		throw Intern::NoNameError();

	std::string	lowerFormName = getLower(formName);
	for (int i = 0; i < FORM_NUM; i++)
	{
		std::string lowerForms = getLower(forms[i]);
		if (!lowerFormName.compare(0, 5, lowerForms, 0, 5))
		{
			std::cout << "Intern creates " << forms[i] << std::endl;
			switch (i)
			{
				case 0:
					return (new PresidentialPardonForm(formTarget));
					break;
				case 1:
					return (new RobotomyRequestForm(formTarget));
					break;
				case 2:
					return (new ShrubberyCreationForm(formTarget));
					break;
				default:
					break;
			}
		}
	}

	throw Intern::UndefinedNameError();

}
