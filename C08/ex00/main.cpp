#include "easyfind.hpp"
#include <iostream>
#include <vector>

#define VAL 21
#define VAL2 3

int	main (void)
{
	std::vector<int> vector;
	
	vector.push_back(20);
	vector.push_back(3);
	vector.push_back(17);
	vector.push_back(100);
	vector.push_back(80);
	vector.push_back(1);

	std::cout << "Try to find: " << VAL << std::endl;
	std::vector<int>::iterator result = easyfind(vector, VAL);

	if (vector.end() == result)
		std::cout << "There is nothing." << std::endl;

	std::cout << "Try to find: " << VAL2 << std::endl;
	std::vector<int>::iterator results = easyfind(vector, VAL2);

	if (vector.end() == results)
		std::cout << "There is nothing." << std::endl;

	std::cout << "Remains:" << std::endl;
	while (vector.end() != results)
	{
		std::cout << *results << std::endl;
		results++;
	}

	return (0);
}
