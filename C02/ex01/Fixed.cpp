#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->fpVal = 0;
}

Fixed::Fixed(int number)
{
	this->fpVal = number;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called\n";
	this->fpVal = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this == &other)
	{
		std::cout << "No copy to self.\n";
		return (*this);
	}
	std::cout << "Copy assignment operator called\n";
	this->fpVal = other.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return (this->fpVal);
}

void	Fixed::setRawBits( int const raw )
{
	this->fpVal = raw;
}
