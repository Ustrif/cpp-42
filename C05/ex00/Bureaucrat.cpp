#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

Bureaucrat::Bureaucrat()
{
	std::cout << "Defualt constructor for Bureaucrat\n";
	this->setName("name");
	this->setGrade(150);
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooHighException());
	if (grade < 1)
		throw (Bureaucrat::GradeTooLowException());
	std::cout << "Constructor with param for Bureaucrat\n";
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor for Bureaucrat\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	std::cout << "Copy Constructor for Bureaucrat\n";
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Copy Assigment Operator for Bureaucrat\n";
	this->setName(other.getName());
	this->setGrade(other.getGrade());
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

void	Bureaucrat::setName(std::string name)
{
	this->name = name;
}

void	Bureaucrat::setGrade(size_t grade)
{
	this->grade = grade;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Grade too low!");
}

std::ostream& operator << (std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

void	Bureaucrat::gradeIncrement()
{
	size_t	lGrade = grade;
	lGrade++;
	if (lGrade > 150)
		throw (Bureaucrat::GradeTooHighException());
	if (lGrade < 1)
		throw (Bureaucrat::GradeTooLowException());
	grade++;
}

void	Bureaucrat::gradeDecrement()
{
	size_t	lGrade = grade;
	lGrade--;
	if (lGrade > 150)
		throw (Bureaucrat::GradeTooHighException());
	if (lGrade < 1)
		throw (Bureaucrat::GradeTooLowException());
	grade--;
}
