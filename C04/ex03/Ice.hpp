#ifndef __ICE__
#define __ICE__

#include "AMateria.hpp"
#include <string>

class Ice : public AMateria
{
	public:
		Ice();
		~Ice();
		Ice( const Ice& other);
		Ice &operator = (const Ice& other);
		AMateria* clone() const;
};

#endif // __ICE__