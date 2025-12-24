#ifndef __CHARACTER_
#define __CHARACTER__

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		AMateria amaterias[4];
	public:
		/* OCF */
		Character();
		~Character();
		Character(const Character& other);
		Character &operator = (const Character& other);

		/* FUNCS */
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif // __CHARACTER__