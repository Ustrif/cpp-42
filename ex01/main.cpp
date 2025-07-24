#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>
#include <cctype>

void	add(PhoneBook& book)
{
	std::string	name;
	std::string	sname;
	std::string	nick;
	std::string	phone;
	std::string	secret;

	std::cout << "What is your name?: ";
	std::cin >> name;
	std::cout << "What is your surname?: ";
	std::cin >> sname;
	std::cout << "What is your nick?: ";
	std::cin >> nick;
	std::cout << "What is your phone number?: ";
	std::cin >> phone;
	std::cout << "What is your dark secret?: ";
	std::cin >> secret;
	if (name.empty() || sname.empty() || nick.empty() || phone.empty() || secret.empty())
	{
		std::cerr << "It can't add some empty infos." << std::endl;
		return ;
	}
	for (size_t i = 0; i < phone.length(); i++)
	{
		if (!isdigit(phone[i]))
		{
			std::cerr << "Phone number must only contain numbers." << std::endl;
			return ;
		}
	}
	book.addContact(book.getCapacity(), name, sname, phone, nick, secret);
	std::cout << "It added new contact: " << name << " ." << std::endl;
}

void	search(PhoneBook& book)
{
	Contact	contact;
	int		index;

	if (book.getCapacity() == 0)
	{
		std::cerr << "No one find." << std::endl;
		return ;
	}
	std::cout << "| index | " << "first name | " << "last name | " << "nickname |" << std::endl;
	for (int i = 0; i < book.getCapacity(); i++)
	{
		contact = book.getContact(i);
		std::cout << "|";
		std::cout << contact.getId();
		std::cout << "|";
		std::cout << contact.getName();
		std::cout << "|";
		std::cout << contact.getSname();
		std::cout << "|";
		std::cout << contact.getNick();
		std::cout << "|";
		std::cout << std::endl;
	}
	std::cout << "Type index which you want to see.: ";
	std::cin >> index;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cerr << "Invalid input." << std::endl;
		return ;
	}
	else if (index < 0 || index >= book.getCapacity())
	{
		std::cerr << "Invalid index!" << std::endl;
		return ;
	}
	contact = book.getContact(index);
	std::cout << "|";
	std::cout << contact.getId();
	std::cout << "|";
	std::cout << contact.getName();
	std::cout << "|";
	std::cout << contact.getSname();
	std::cout << "|";
	std::cout << contact.getNick();
	std::cout << "|";
	std::cout << std::endl;
}

int	main(void)
{
	std::string	input;
	PhoneBook	book;

	while (1)
	{
		std::cout << "PHONE: ";
		std::cin >> input;
		if (input.compare("EXIT") == 0)
			break ;
		else if (input.compare("ADD") == 0)
			add(book);
		else if (input.compare("SEARCH") == 0)
			search(book);
	}
	std::cout << "exit" << std::endl;
	return (0);
}
