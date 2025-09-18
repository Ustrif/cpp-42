#ifndef __BURE__
#define __BURE__

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	name;
		size_t		grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		size_t	getGrade() const;
		std::string getName() const;
		void	setGrade(size_t grade);
		void	gradeIncrement();
		void	gradeDecrement();
		void	signForm(Form& form);
		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(){}
				const char* what() const noexcept;
		};
		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException() {}
				const char* what() const noexcept;
		};
};

std::ostream& operator << (std::ostream& os, const Bureaucrat& b);

#endif // __BURE__