#include <iostream>
#include <string>
#include "Contact.hpp"

void	Contact::setId(int id)
{
	this->_id = id;
}

int	Contact::getId(void) const
{
	return (Contact::_id);
}

void	Contact::setName(std::string name)
{
	this->_name = name;
}

void	Contact::setSname(std::string sname)
{
	this->_sname = sname;
}

void	Contact::setPhone(std::string phone)
{
	this->_phone = phone;
}

void	Contact::setNick(std::string nick)
{
	this->_nick = nick;
}

void	Contact::setSecret(std::string secret)
{
	this->_secret = secret;
}

std::string	Contact::getName(void) const
{
	return (this->_name);
}

std::string	Contact::getSname(void) const
{
	return (this->_sname);
}

std::string	Contact::getPhone(void) const
{
	return (this->_phone);
}

std::string	Contact::getNick(void) const
{
	return (this->_nick);
}

std::string	Contact::getSecret(void) const
{
	return (this->_secret);
}
