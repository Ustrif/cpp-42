#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class	Contact
{
	private:
		int			_id;
		std::string	_name;
		std::string	_sname;
		std::string	_phone;
		std::string	_nick;
		std::string	_secret;
	public:
		void	setId(int id);
		int		getId(void) const;
		void	setName(std::string name);
		void	setSname(std::string sname);
		void	setPhone(std::string phone);
		void	setNick(std::string nick);
		void	setSecret(std::string secret);
		std::string	getName(void) const;
		std::string	getSname(void) const;
		std::string	getPhone(void) const;
		std::string	getNick(void) const;
		std::string	getSecret(void) const;
};

#endif
