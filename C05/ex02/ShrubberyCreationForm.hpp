#ifndef __SHRUBBERY__
#define __SHRUBBERY__

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm &operator = (const ShrubberyCreationForm& other);

		virtual void executeAction() const;

		class FileError : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif // __SHRUBBERY__