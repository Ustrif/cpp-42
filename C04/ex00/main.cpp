#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete (meta);
	delete (j);
	delete (i);

	std::cout << "\n-----\n\n";

	const Animal* cat = new Cat("kedy");
	std::cout << "type of cat " << cat->getType() << " .\n";
	cat->makeSound();
	delete (cat);

	return 0;
}
