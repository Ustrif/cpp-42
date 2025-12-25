#ifndef __ANIMAL__
#define __ANIMAL__

#include <string>

class Animal
{
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		void setType(std::string type);
		std::string getType( void ) const;
		virtual void makeSound( void ) const;
	protected:
		std::string type;
};

#endif // __ANIMAL__