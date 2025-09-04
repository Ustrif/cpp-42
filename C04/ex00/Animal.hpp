#ifndef __ANIMAL__
#define __ANIMAL__

#include <string>

class Animal
{
	public:
		Animal();
		Animal(std::string type);
		~Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		void setType(std::string type);
		std::string getType( void ) const;
		void makeSound( void );
	protected:
		std::string type;
};

#endif // __ANIMAL__