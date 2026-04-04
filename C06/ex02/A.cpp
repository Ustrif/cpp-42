#include "A.hpp"

A::A() : type('A') {}

A::~A() {}

char A::getType (void) const
{
	return (this->type);
}
