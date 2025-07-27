#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>
#include <cctype>
#include <sstream>

void	add(PhoneBook& book)
{
	std::string	name;
	std::string	sname;
	std::string	nick;
	std::string	phone;
	std::string	secret;

	std::cout << "What is your name?: ";
	std::getline(std::cin, name);
	std::cout << "What is your surname?: ";
	std::getline(std::cin, sname);
	std::cout << "What is your nick?: ";
	std::getline(std::cin, nick);
	std::cout << "What is your phone number?: ";
	std::getline(std::cin, phone);
	std::cout << "What is your dark secret?: ";
	std::getline(std::cin, secret);
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

void	print(std::string s)
{
	if (s.length() == 10)
	{
		std::cout << s << "|";
		return ;
	}
	else if (s.length() > 10)
	{
		for (size_t i = 0; s[i] && i < 9 ; i++)
			std::cout << s[i];
		std::cout << "." << "|";
		return ;
	}
	else
	{
		size_t	size;

		size = 10 - s.length();
		for(size_t i = 0; i < size; i++)
			std::cout << " ";
		std::cout << s << "|";
		return ;
	}
}

std::string	ft_itoa(int number)
{
	std::stringstream ss;
	ss << number;
	return ss.str();
}

void	search(PhoneBook& book)
{
	Contact	contact;
	std::string	sindex;
	int			index;

	if (book.getCapacity() == 0)
	{
		std::cerr << "No one find." << std::endl;
		return ;
	}
	std::cout << "|";
	print("index");
	print("first name");
	print("last name");
	print("nickname");
	std::cout << "\n";
	for (int i = 0; i < book.getCapacity(); i++)
	{
		contact = book.getContact(i);
		std::cout << "|";
		print(ft_itoa(contact.getId()));
		print(contact.getName());
		print(contact.getSname());
		print(contact.getNick());
		std::cout << std::endl;
	}
	std::cout << "Type index which you want to see.: ";
	std::getline(std::cin, sindex);
	std::stringstream ss(sindex);
	ss >> index;
	if (ss.fail())
	{
		std::cout << "Invalid index!" << std::endl;
		return;
	}
	contact = book.getContact(index);
	if (contact.getName().empty())
		return ;
	print(ft_itoa(contact.getId()));
	print(contact.getName());
	print(contact.getSname());
	print(contact.getNick());
	print(contact.getPhone());
	print(contact.getSecret());
	std::cout << std::endl;
}

int	main(void)
{
	std::string	input;
	PhoneBook	book;

	while (1)
	{
		std::cout << "PHONE: ";
		std::getline(std::cin, input);
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
