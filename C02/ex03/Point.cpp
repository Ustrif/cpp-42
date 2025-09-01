#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

Point::Point() : x(0), y(0) {}

Point::Point(const float num1, const float num2) : x(num1), y(num2) {}

Point::~Point() {}

const Fixed Point::getX() const
{
	return (this->x);
}

const Fixed Point::getY() const
{
	return (this->y);
}

Point::Point(const Point &cpy) : x(cpy.getX()), y(cpy.getY()) {}

Point &Point::operator=(const Point &other)
{
	(void) other;
	return *this;
}
