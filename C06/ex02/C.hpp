#ifndef __C__
#define __C__

#include "Base.hpp"

class C : public Base
{
	private:
		const char	type;

	public:
		C();
		~C();
		char getType (void) const;
};

#endif // __C__