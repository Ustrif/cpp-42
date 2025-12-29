#ifndef __AForm__
#define __AForm__

#include "Bureaucrat.hpp"
#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool			sign;
		const size_t	gradeSign;
		const size_t	gradeExecute;

	protected:
		virtual void executeAction() const = 0;

	public:
		AForm(std::string name, int gradeSign, int gradeExecute);
		virtual ~AForm();
		AForm(const AForm &other);
		AForm & operator = (const AForm &other);

		std::string getName() const;
		bool		isSigned() const;
		size_t		getGradeSign() const;
		size_t		getGradeExecute() const;

		void		beSigned(Bureaucrat& bureaucrat);

		void		execute(Bureaucrat const & executor) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class UnsignedFormException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator << (std::ostream &os, AForm& AForm);

#endif // __AForm__
