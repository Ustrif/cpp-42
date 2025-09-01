#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

void	test1()
{
	Point	a(0, 0);
	Point	b(0, 4);
	Point	c(3, 0);
	Point	point(1, 1);
	bool	res;

	res = bsp(a, b, c, point);
	std::cout << "0,0; 0,4; 3,0 are points.\nCheck point is 1,1.\nResult: " << res << std::endl;
}

void	test2()
{
	Point	a(0, 0);
	Point	b(0, 4);
	Point	c(3, 0);
	Point	point(0, 2);
	bool	res;

	res = bsp(a, b, c, point);
	std::cout << "0,0; 0,4; 3,0 are points.\nCheck point is 0,2.\nResult: " << res << std::endl;
}

void	test3()
{
	Point	a(0, 0);
	Point	b(0, 4);
	Point	c(3, 0);
	Point	point(5, 5);
	bool	res;

	res = bsp(a, b, c, point);
	std::cout << "0,0; 0,4; 3,0 are points.\nCheck point is 5,5.\nResult: " << res << std::endl;
}

void	test4()
{
	Point	a(-10, 0);
	Point	b(10, 0);
	Point	c(0, 10);
	Point	point1(1,1);
	Point	point2(10, 0);
	Point	point3(-2, -2);
	bool	res;

	res = bsp(a, b, c, point1);
	std::cout << "-10,0; 10,0; 0,10 are points.\nCheck point is 1,1.\nResult: " << res << std::endl;
	res = bsp(a, b, c, point2);
	std::cout << "-10,0; 10,0; 0,10 are points.\nCheck point is 10,0.\nResult: " << res << std::endl;
	res = bsp(a, b, c, point3);
	std::cout << "-10,0; 10,0; 0,10 are points.\nCheck point is -2,-2.\nResult: " << res << std::endl;
}


int main( void )
{
	test1();
	std::cout << std::endl;
	test2();
	std::cout << std::endl;
	test3();
	std::cout << std::endl;
	test4();
	return 0;
}

