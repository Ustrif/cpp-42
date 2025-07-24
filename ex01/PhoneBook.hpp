#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	contacts[8];
		int		capacity;
	public:
		PhoneBook();
		void	addContact(int id, std::string name, std::string sname, std::string phone, std::string nick, std::string secret);
		Contact	getContact(int id);
		void	updateCapacity(void);
		int		getCapacity(void) const;
};

#endif
