#ifndef __FORM__
#define __FORM__

#include "Bureaucrat.hpp"
#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool			sign;
		const size_t	gradeSign;
		const size_t	gradeExecute;
	public:
		Form();
		Form(std::string name, int gradeSign, int gradeExecute);
		~Form();
		Form(const Form &other);
		Form & operator = (const Form &other);
		std::string getName() const;
		bool		isSigned() const;
		size_t		getGradeSign() const;
		size_t		getGradeExecute() const;
		void		beSigned(Bureaucrat& bureaucrat);
		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(){}
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException() {}
				const char* what() const throw();
		};
};

std::ostream & operator << (std::ostream &os, Form& form);

#endif // __FORM__