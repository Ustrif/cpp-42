#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Default Constructor for Intern" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Destructor for Intern" << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void) other;
	std::cout << "Copy Constructor for Intern" << std::endl;
}

Intern &Intern::operator = (const Intern& other)
{
	(void) other;
	std::cout << "Copy Assigment Operator for Intern" << std::endl;

	return (*this);
}

const char* Intern::NoNameError::what() const throw()
{
	return ("No name given.");
}

const char* Intern::UndefinedNameError::what() const throw()
{
	return ("Given name is undefined.");
}

AForm* Intern::CreateShrubberyCreation(std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::CreateRobotomyRequest(std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::CreatePresidentialPardon(std::string& target)
{
	return (new PresidentialPardonForm(target));
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

	AForm* (Intern::*ptrMember[3])(std::string&) =
	{
		&Intern::CreateShrubberyCreation,
		&Intern::CreateRobotomyRequest,
		&Intern::CreatePresidentialPardon
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
			AForm* form = (this->*ptrMember[i])(formTarget);
			return (form);
		}
	}

	throw Intern::UndefinedNameError();

}
