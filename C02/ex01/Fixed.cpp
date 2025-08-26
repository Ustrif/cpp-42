#include "Fixed.hpp"
#include <iostream>
#include <limits>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->fpVal = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &other)
	{
		std::cout << "No copy to self.\n";
		return (*this);
	}
	this->fpVal = other.fpVal;
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	return (this->fpVal);
}

void	Fixed::setRawBits( int const raw )
{
	this->fpVal = raw;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	if (number > __INT_MAX__ / 256)
	{
		std::cout << "Number is so big to store. Replaced with 0.\n";
		this->fpVal = 0;
		return ;
	}
	this->fpVal = number * 256;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	this->fpVal = (int) roundf((number * 256));
}

float Fixed::toFloat( void ) const
{
	return ((float) (this->fpVal / 256.0f));
}

int Fixed::toInt( void ) const
{
	return (this->fpVal >> 8);
}

std::ostream& operator<<(std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return (out);
}
