#include "C.hpp"

C::C() : type('C') {}

C::~C() {}

char C::getType (void) const
{
	return (this->type);
}
