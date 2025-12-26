#include <string>
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int gradeSign, int gradeExecute) : name(name), gradeSign(gradeSign), gradeExecute(gradeExecute)
{
	if (gradeSign > 150 || gradeExecute > 150)
		throw AForm::GradeTooHighException();
	if (gradeSign < 1 || gradeExecute < 1)
		throw AForm::GradeTooLowException();

	std::cout << "Constructor for AForm\n";
	this->sign = false;
}

AForm::~AForm()
{
	std::cout << "Default destructor for AForm\n";
}

AForm::AForm(const AForm &other) : name(other.getName()), gradeSign(other.getGradeSign()), gradeExecute(other.getGradeExecute())
{
	std::cout << "Copy Constructor for AForm\n";

	this->sign = other.isSigned();
}

AForm & AForm::operator = (const AForm &other)
{
	std::cout << "Copy Assigment Operator for AForm\n";

	this->sign = other.isSigned();
	return (*this);
}

std::string AForm::getName() const
{
	return (this->name);
}

bool		AForm::isSigned() const
{
	return (this->sign);
}

size_t		AForm::getGradeSign() const
{
	return (this->gradeSign);
}

size_t		AForm::getGradeExecute() const
{
	return (this->gradeExecute);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

std::ostream & operator << (std::ostream &os, AForm& AForm)
{
	os	<< "AForm name: " << AForm.getName() << ", "
		<< "grade sign: " << AForm.getGradeSign()
		<< ", execute sign: " << AForm.getGradeExecute()
		<< ", signed status: " << AForm.isSigned() << ".";
	return os;
}

void		AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeSign())
	{
		this->sign = true;
	}
	else
	{
		throw AForm::GradeTooLowException();
	}
}

const char* AForm::UnsignedFormException::what() const throw()
{
	return ("This form is unsigned.");
}

void		AForm::execute(Bureaucrat const & executor) const
{
	if (!this->isSigned())
	{
		throw AForm::UnsignedFormException();
	}
	else if (this->getGradeExecute() < executor.getGrade())
	{
		throw AForm::GradeTooLowException();
	}
	else
	{
		this->executeAction();
	}
}
