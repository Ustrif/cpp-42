#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	capacity = 0;
}

void	PhoneBook::updateCapacity(void)
{
	this->capacity += 1;
}

void	PhoneBook::addContact(int id, std::string name, std::string sname,
		std::string phone, std::string nick, std::string secret)
{
	int	index;

	index = capacity % 8;
	contacts[index].setId(id);
	contacts[index].setName(name);
	contacts[index].setSname(sname);
	contacts[index].setPhone(phone);
	contacts[index].setNick(nick);
	contacts[index].setSecret(secret);
	updateCapacity();
}

Contact	PhoneBook::getContact(int id)
{
	if (id < 0 || id >= 8 || id >= capacity)
	{
		std::cerr << "Invalid index" << std::endl;
		return Contact();
	}
	return (contacts[id]);
}

int	PhoneBook::getCapacity(void) const
{
	return (this->capacity);
}

