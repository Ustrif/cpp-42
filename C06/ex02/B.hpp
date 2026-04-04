#ifndef __B__
#define __B__

#include "Base.hpp"

class B : public Base
{
	private:
		const char	type;

	public:
		B();
		~B();
		char getType (void) const;
};

#endif // __B__