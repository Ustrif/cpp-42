#include <string>
#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("name"), gradeSign(20), gradeExecute(20)
{
	std::cout << "Default constructor for Form\n";
	this->sign = false;
}

Form::Form(std::string name, int gradeSign, int gradeExecute) : name(name), gradeSign(gradeSign), gradeExecute(gradeExecute)
{
	if (gradeSign > 150 || gradeExecute > 150)
		throw Form::GradeTooHighException();
	if (gradeSign < 1 || gradeExecute < 1)
		throw Form::GradeTooLowException();
	std::cout << "Constructor for Form\n";
	this->sign = false;
}

Form::~Form()
{
	std::cout << "Default destructor for Form\n";
}

Form::Form(const Form &other) : name(other.getName()), gradeSign(other.getGradeSign()), gradeExecute(other.getGradeExecute())
{
	std::cout << "Copy Constructor for Form\n";
	*this = other;
}

Form & Form::operator = (const Form &other)
{
	std::cout << "Copy Assigment Operator for Form\n";
	this->sign = other.isSigned();
	return (*this);
}

std::string Form::getName() const
{
	return (this->name);
}

bool		Form::isSigned() const
{
	return (this->sign);
}

size_t		Form::getGradeSign() const
{
	return (this->gradeSign);
}

size_t		Form::getGradeExecute() const
{
	return (this->gradeExecute);
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return ("Grade is too high.\n");
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low.\n");
}

std::ostream & operator << (std::ostream &os, Form& form)
{
	os	<< "Form name: " << form.getName() << ", "
		<< "grade sign: " << form.getGradeSign()
		<< ", execute sign: " << form.getGradeExecute()
		<< ", signed status: " << form.isSigned() << ".";
	return os;
}

void		Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeSign())
	{
		this->sign = true;
		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
	}
	else
	{
		std::cout << bureaucrat.getName() << " couldn’t sign " << this->getName() << " because ";
		throw Form::GradeTooLowException();
	}
}
