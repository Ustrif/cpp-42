#ifndef __CAT__
#define __CAT__

#include "Animal.hpp"
#include <string>
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		void makeSound( void ) const;
		Brain* getBrainAddress() const;
};

#endif //__CAT__