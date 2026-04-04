#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

Base*	generate(void)
{
	Base	*result;
	int		random;

	std::srand(time(0));
	random = std::rand() % 3;

	if (!random)
		result = new A();
	else if (random == 1)
		result = new B();
	else
		result = new C();
	return (result);
}

void	identify(Base* p)
{
	A*	aPtr = NULL;
	B*	bPtr = NULL;
	C*	cPtr = NULL;

	aPtr = dynamic_cast<A*>(p);
	if (aPtr != NULL)
	{
		std::cout << "Type: " << aPtr->getType() << std::endl;
		return ;
	}

	bPtr = dynamic_cast<B*>(p);
	if (bPtr != NULL)
	{
		std::cout << "Type: " << bPtr->getType() << std::endl;
		return ;
	}

	cPtr = dynamic_cast<C*>(p);
	if (cPtr != NULL)
		std::cout << "Type: " << cPtr->getType() << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A& aPtr = dynamic_cast<A&>(p);
		std::cout << "Type: " << aPtr.getType() << std::endl;
		return ;
	}
	catch (std::exception& e) {}

	try
	{
		B& bPtr = dynamic_cast<B&>(p);
		std::cout << "Type: " << bPtr.getType() << std::endl;
		return ;
	}
	catch (std::exception& e) {}

	try
	{
		C& cPtr = dynamic_cast<C&>(p);
		std::cout << "Type: " << cPtr.getType() << std::endl;
	}
	catch (std::exception& e) {}
}

int	main (void)
{
	Base* object = generate();

	std::cout << "Pointer Result:" << std::endl;
	identify(object);

	std::cout << "Reference Result:" << std::endl;
	identify(*object);

	delete (object);
	
	return (0);
}
