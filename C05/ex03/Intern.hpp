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
		int	number;
	public:
		Intern();
		~Intern();
		Intern(const Intern& other);
		Intern &operator = (const Intern& other);

		int		getNumber( void ) const;
		void	setNumber( int num );

		AForm* makeForm(std::string formName, std::string formTarget);

		class NoNameError : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class UndefinedNameError : public std::exception
		{
			public:
				const char* what() const throw();
		};

};

#endif // __INTERN__
