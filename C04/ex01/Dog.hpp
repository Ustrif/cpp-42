#ifndef __DOG__
#define __DOG__

#include "Animal.hpp"
#include <string>
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		~Dog();
		Dog(std::string type);
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		void makeSound( void ) const;
};

#endif //__DOG__