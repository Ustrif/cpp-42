#ifndef __ROBOTOMY__
#define __ROBOTOMY__

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm &operator = (const RobotomyRequestForm& other);

};

#endif // __ROBOTOMY__