#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main( void )
{
	const Animal* animals[4];
	for (int i = 0; i < 2; i++)
	{
		animals[i] = new Dog();
	}
	for (int i = 2; i < 4; i++)
	{
		animals[i] = new Cat();
	}
	for (int i = 0; i < 4; i++)
	{
		animals[i]->makeSound();
	}
	for (int i = 0; i < 4; i++)
	{
		delete (animals[i]);
	}

	std::cout << "----------" << std::endl;

	const Dog *dog = new Dog();
	Brain *brain = dog->getBrainAddress();
	brain->setIdea(0, "first");
	brain->setIdea(1, "second");
	brain->displayIdeas();

	const Dog *dog2 = new Dog(*dog);
	Brain *brain1 = dog2->getBrainAddress();
	brain1->displayIdeas();

	delete(dog);
	delete(dog2);

	std::cout << "----------" << std::endl;

	const Cat *cat = new Cat();
	Brain *brainx = cat->getBrainAddress();
	brainx->setIdea(0, "first");
	brainx->setIdea(1, "second");
	brainx->displayIdeas();

	const Cat *cat2 = new Cat(*cat);
	Brain *brainy = cat2->getBrainAddress();
	brainy->displayIdeas();

	delete(cat);
	delete(cat2);
	return 0;
}
