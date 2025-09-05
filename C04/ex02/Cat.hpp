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
		~Cat();
		Cat(std::string type);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		void makeSound( void ) const;
};

#endif //__CAT__