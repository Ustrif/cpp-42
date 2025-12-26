#ifndef __PRESIDENTAL__
#define __PRESIDENTAL__

#include "AForm.hpp"

class PresidentalPardonForm : public AForm
{
	public:
		PresidentalPardonForm(std::string target);
		~PresidentalPardonForm();
		PresidentalPardonForm(const PresidentalPardonForm& other);
		PresidentalPardonForm &operator = (const PresidentalPardonForm& other);

};

#endif // __PRESIDENTAL__