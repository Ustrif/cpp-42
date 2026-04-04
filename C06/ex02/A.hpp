#ifndef __A__
#define __A__

#include "Base.hpp"

class A : public Base
{
	private:
		const char	type;

	public:
		A();
		~A();
		char getType (void) const;
};

#endif // __A__