#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{
	std::cout << "Presidential Pardon form constructor\n" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon form destructor\n" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
: AForm(other.getName(), other.getGradeSign(), other.getGradeExecute())
{
	std::cout << "Presidential Pardon form copy constructor\n" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm& other)
{
	if (this != &other)
		AForm::operator=(other);

	std::cout << "Presidential Pardon form copy assigment operator\n" << std::endl;
	return (*this);
}

void PresidentialPardonForm::executeAction() const
{
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
