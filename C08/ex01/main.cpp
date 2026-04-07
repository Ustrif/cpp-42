#include "Span.hpp"
#include <iostream>

int main( void )
{
	std::vector<int> vec;

	for (int i = 0; i < 10001; i++)
		vec.push_back(i * i);

	Span span = Span(vec.size());

	std::cout << "TEST 1" << std::endl;

	try
	{
		std::cout << "Longest: " << span.longestSpan() << std::endl;
		std::cout << "Shortest: " << span.shortestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "TEST 2" << std::endl;

	try
	{
		span.addNumbers(vec.begin(), vec.end());
		std::cout << "Longest: " << span.longestSpan() << std::endl;
		std::cout << "Shortest: " << span.shortestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "TEST 3" << std::endl;

	try
	{
		span.addNumber(5);
		std::cout << "Longest: " << span.longestSpan() << std::endl;
		std::cout << "Shortest: " << span.shortestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "TEST 4" << std::endl;
	std::list<int> list;

	for (int i = 0; i < 10001; i++)
		list.push_back(i * i);

	Span otherSpan(list.size());

	try
	{
		otherSpan.addNumbers(list.begin(), list.end());
		std::cout << "Longest: " << span.longestSpan() << std::endl;
		std::cout << "Shortest: " << span.shortestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "END OF PROGRAM" << std::endl;
    return (0);
}
