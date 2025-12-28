#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{
	std::cout << "Robotomy Request form constructor\n" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request form destructor\n" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
: AForm(other.getName(), other.getGradeSign(), other.getGradeExecute())
{
	std::cout << "Robotomy Request form copy constructor\n" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm& other)
{
	if (this != &other)
		AForm::operator=(other);

	std::cout << "Robotomy Request form copy assigment operator\n" << std::endl;
	return (*this);
}

void RobotomyRequestForm::executeAction() const
{
	std::srand(time(0));

	std::cout << "Drilling noises, go brr, hrrr, noisessssss *." << std::endl;

	if (std::rand() % 2)
	{
		std::cout << this->getName() << " has been robotomized successfully." << std::endl;
	}
	else
	{
		std::cout << this->getName() << " has not been robotomized." << std::endl;
	}
}
