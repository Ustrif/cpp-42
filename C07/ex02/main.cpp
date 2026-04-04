#include <iostream>
#include "Array.hpp"

int main()
{
	Array<int> arr(2);

	arr[0] = 20;
	arr[1] = 40;

	std::cout << "TEST 1" << std::endl;
	try
	{
		std::cout << arr[0];
		std::cout << " " << arr[1] << " size: " << arr.size() << std::endl;
		std::cout << arr[2];
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "TEST 2" << std::endl;
	Array<int> original(arr);

	original[1] = 100;
	std::cout << "Arr 1: " << arr[1] << " original 1: " << original[1] << std::endl;

	std::cout << "TEST 3" << std::endl;
	Array<std::string> array(2);

	array[0] = "hello";
	array[1] = " world!";
	std::cout << array[0] << array[1] << std::endl;

	std::cout << "TEST 4 - initialized" << std::endl;
	Array<int> number(1);
	Array<char> character(1);
	Array<std::string> string(1);

	std::cout	<< number[0] << " "
				<< character[0] << " "
				<< string[0] << std::endl;

	return 0;
}
