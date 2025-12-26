#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include "AForm.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooHighException());
	if (grade < 1)
		throw (Bureaucrat::GradeTooLowException());

	this->grade = grade;
	std::cout << "Constructor with param for Bureaucrat\n";
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor for Bureaucrat\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.getName()), grade(other.getGrade())
{
	std::cout << "Copy Constructor for Bureaucrat\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Copy Assigment Operator for Bureaucrat\n";

	if (this != &other)
		this->grade = other.grade;

	return (*this);
}

size_t	Bureaucrat::getGrade() const
{
	return (this->grade);
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

std::ostream& operator << (std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";

	return (os);
}

void	Bureaucrat::gradeIncrement()
{
	if (grade + 1 > 150)
		throw (Bureaucrat::GradeTooHighException());
	if (grade + 1 < 1)
		throw (Bureaucrat::GradeTooLowException());

	grade++;
}

void	Bureaucrat::gradeDecrement()
{
	if (grade - 1 > 150)
		throw (Bureaucrat::GradeTooHighException());
	if (grade - 1 < 1)
		throw (Bureaucrat::GradeTooLowException());

	grade--;
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn’t sign " 
		<< form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn’t execute " 
		<< form.getName() << " because " << e.what() << std::endl;
	}
}
