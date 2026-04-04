#include "B.hpp"

B::B() : type('B') {}

B::~B() {}

char B::getType (void) const
{
	return (this->type);
}
