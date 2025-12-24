#ifndef __CURE__
#define __CURE__

#include "AMateria.hpp"
#include <string>

class Cure : public AMateria
{
	public:
		Cure();
		~Cure();
		Cure( const Cure& other);
		Cure &operator = (const Cure& other);
		AMateria* clone() const;
};

#endif // __Cure__