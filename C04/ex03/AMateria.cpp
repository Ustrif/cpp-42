#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
	this->type = type;
}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria& other)
{
	this->type = other.getType();
}

AMateria& AMateria::operator = (const AMateria& other)
{
	this->type = other.getType();
	return (*this);
}

AMateria::AMateria()
{
	this->type = "DefaultType";
}

/* İNCELE. */
std::string const & getType()
{
	return (type);
}
