#ifndef __AMateria__
#define __AMateria__

#include <string>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	type;
	public:
		/* OCF */
		AMateria(std::string const & type);
		~AMateria();
		AMateria(const AMateria& other);
		AMateria& operator = (const AMateria& other);
		AMateria();

		/* FUNCS */
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif // __AMateria__