#ifndef __INTERN__
#define __INTERN__

#define FORM_NUM 3

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		AForm *CreateShrubberyCreation(std::string& target);
		AForm *CreateRobotomyRequest(std::string& target);
		AForm *CreatePresidentialPardon(std::string& target);
	public:
		Intern();
		~Intern();
		Intern(const Intern& other);
		Intern &operator = (const Intern& other);

		AForm* makeForm(std::string formName, std::string formTarget);

		class NoNameError : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class UndefinedNameError : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};

#endif // __INTERN__
