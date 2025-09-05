#ifndef __DOG__
#define __DOG__

#include "Animal.hpp"
#include <string>

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(std::string type);
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		void makeSound( void ) const;
};

#endif //__DOG__