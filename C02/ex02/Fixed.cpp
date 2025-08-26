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

Fixed Fixed::operator + (const Fixed &other)
{
	this->fpVal += other.fpVal;
	return (*this);
}

Fixed Fixed::operator * (const Fixed &other)
{
	Fixed result;
    result.setRawBits((this->fpVal * other.getRawBits()) >> 8);
    return result;
}

Fixed Fixed::operator - (const Fixed &other)
{
	this->fpVal -= other.fpVal;
	return (*this);
}

Fixed Fixed::operator / (const Fixed &other)
{
	Fixed result;
	if (other.getRawBits() == 0)
	{
		std::cout << "Zero division err\n" << std::endl;
		return result;
	}
    result.setRawBits((this->fpVal << 8) / other.getRawBits());
    return result;
}

bool Fixed::operator>(const Fixed &other) const
{
	if (this->fpVal > other.fpVal)
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &other) const
{
	if (this->fpVal > other.fpVal)
		return (false);
	return (true);
}

bool Fixed::operator>=(const Fixed &other) const
{
	if (this->fpVal >= other.fpVal)
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &other) const
{
	if (this->fpVal <= other.fpVal)
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &other) const
{
	if (this->fpVal == other.fpVal)
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &other) const
{
	if (this->fpVal == other.fpVal)
		return (false);
	return (true);
}

Fixed Fixed::operator ++ ()
{
	this->fpVal++;
	return (*this);
}

Fixed Fixed::operator ++ (int)
{
	Fixed	temp(*this);
	this->fpVal++;
	return (temp);
}

Fixed Fixed::operator -- ()
{
	this->fpVal--;
	return (*this);
}

Fixed Fixed::operator -- (int)
{
	Fixed	temp(*this);
	this->fpVal--;
	return (temp);
}

Fixed& Fixed::min(Fixed &num1, Fixed &num2)
{
	if (num1 > num2)
		return (num2);
	return (num1);
}

const Fixed& min(const Fixed &num1, const Fixed &num2)
{
	if (num1 > num2)
		return (num2);
	return (num1);
}

Fixed& Fixed::max(Fixed &num1, Fixed &num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

const Fixed& Fixed::max(const Fixed &num1, const Fixed &num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}
