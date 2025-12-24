#include "Cure.hpp"

Cure::Cure() : AMateria()
{
	this->type = "cure";
}

Cure::~Cure() {}

Cure::Cure( const Cure& other) : AMateria()
{
	this->type = other.getType();
}

Cure &Cure::operator = (const Cure& other) {}

AMateria* Cure::clone() const
{
	Cure *cure = new Cure();
	return (cure);
}
