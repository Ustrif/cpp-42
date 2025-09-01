#include "Fixed.hpp"
#include "Point.hpp"

static Fixed calculateArea(Point a, Point b, Point c)
{
	Fixed	area = Fixed(0);

	area = area + ((a.getX() * b.getY()));
	area = area + ((b.getX() * c.getY()));
	area = area + ((c.getX() * a.getY()));
	area = area - ((b.getX() * a.getY()));
	area = area - ((c.getX() * b.getY()));
	area = area - ((a.getX() * c.getY()));
	area = area / Fixed(2);

	if (area < 0)
		area = area * Fixed(-1);
	return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	area1;
	Fixed	area2;
	Fixed	area3;
	Fixed	totalArea;

	area1 = calculateArea(a, b, point);
	area2 = calculateArea(a, c, point);
	area3 = calculateArea(point, b, c);

	if (area1 == 0 || area2 == 0 || area3 == 0)
		return (false);
	totalArea = calculateArea(a, b, c);
	totalArea = totalArea - area1 - area2 - area3;
	if (totalArea == 0)
		return (true);
	return (false);
}
