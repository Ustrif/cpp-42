#ifndef __CAT__
#define __CAT__

#include "Animal.hpp"
#include <string>

class Cat : public Animal
{
	public:
		Cat();
		virtual ~Cat();
		Cat(std::string type);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		void makeSound( void ) const;
};

#endif //__CAT__