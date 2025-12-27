#ifndef __PRESIDENTIAL__
#define __PRESIDENTIAL__

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm &operator = (const PresidentialPardonForm& other);

		virtual void executeAction() const;

};

#endif // __PRESIDENTIAL__