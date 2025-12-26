#ifndef __BURE__
#define __BURE__

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	name;
		size_t				grade;
	public:
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);

		size_t	getGrade() const;
		std::string getName() const;

		void	gradeIncrement();
		void	gradeDecrement();

		void	signForm(AForm& form);

		void	executeForm(AForm const & form) const;

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator << (std::ostream& os, const Bureaucrat& b);

#endif // __BURE__