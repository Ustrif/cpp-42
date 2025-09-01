#ifndef __POINT__
#define __POINT__

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const float num1, const float num2);
		~Point();
		Point(const Point &cpy);
		Point &operator=(const Point &cpy);
		const Fixed getX() const;
		const Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif //__POINT__