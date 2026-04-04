#include "iter.hpp"
#include <iostream>

static void	printChar(char c)
{
	std::cout << c << " ";
}

static void	printInt(int c)
{
	if (c >= 0)
		std::cout << "-" << c << " ";
	else
		std::cout << "+" << c << " ";
}

static void	printDouble(double d)
{
	if (d >= 5)
		std::cout << "wow " << d << " ";
	else
		std::cout << "oops " << d << " ";
}

static void	upTest( void )
{
	char arr[ARR_SIZE] = {'L', 'E', 'N', '\0'};
	const char arx[ARR_SIZE] = {'C', 'O', 'N', '\0'};

	iter(arr, ARR_SIZE, printChar);
	std::cout << "\n";
	iter(arx, ARR_SIZE, printChar);
	std::cout << "\n";
}

static void	intTest( void )
{
	int arr[ARR_SIZE] = {4, 38, 21, 10};
	const int arx[ARR_SIZE] = {-100, -70, -6, -1001};

	iter(arr, ARR_SIZE, printInt);
	std::cout << "\n";
	iter(arx, ARR_SIZE, printInt);
	std::cout << "\n";
}

static void	doubleTest( void )
{
	double arr[ARR_SIZE] = {4.63, 38.101, 21.76, 10.3};
	const double arx[ARR_SIZE] = {-100.91, -70.6, -6.34, -1001.01};

	iter(arr, ARR_SIZE, printDouble);
	std::cout << "\n";
	iter(arx, ARR_SIZE, printDouble);
	std::cout << "\n";
}

int main( void )
{
	upTest();
	intTest();
	doubleTest();
	return 0;
}
