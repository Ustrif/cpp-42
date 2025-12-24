#include "Ice.hpp"

Ice::Ice() : AMateria()
{
	this->type = "ice";
}

Ice::~Ice() {}

Ice::Ice( const Ice& other) : AMateria()
{
	this->type = other.getType();
}

Ice &Ice::operator = (const Ice& other) {}

AMateria* Ice::clone() const
{
	Ice *ice = new Ice();
	return (ice);
}
