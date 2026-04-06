#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>

ScalarConverter::ScalarConverter()
{
	std::cout << "Scalar Converter Class Constructor!" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Scalar Converter Class Destructor!" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void) other;
	std::cout << "Scalar Converter Class Copy Constructor!" << std::endl;
}

ScalarConverter &ScalarConverter::operator = (const ScalarConverter& other)
{
	(void) other;
	std::cout << "Scalar Converter Class Copy Assigment Operator!" << std::endl;
	return (*this);
}

void	ScalarConverter::convert(const std::string arg)
{
	const char	type = findType(arg);

	switch (type)
	{
		case 'n':
			printer(255, LONG_MAX, std::numeric_limits<float>::quiet_NaN(), std::numeric_limits<float>::quiet_NaN());
			break ;
		
		case 'l':
			printer(255, LONG_MAX, std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity());
			break ;

		case 'c':
		{
			try
			{
				const char c = toChar(arg);
				printer(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c));
			}
			catch (std::exception& e)
			{
				std::cout << "Convertation error!" << std::endl;
			}
			break ;
		}

		case 'i':
		{
			try
			{
				const int i = toInt(arg);
				if (i >= 128 || i < 0)
					printer(255, i, static_cast<float>(i), static_cast<double>(i));
				else
					printer(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i));
			}
			catch (std::exception& e)
			{
				std::cout << "Convertation error!" << std::endl;
			}
			break ;
		}

		case 'f':
		{
			try
			{
				const float f = toFloat(arg);
				if (f >= std::numeric_limits<int>::max()
					|| f <= -std::numeric_limits<int>::max())
					printer(255, LONG_MAX, f, static_cast<double>(f));
				else if (f >= 128 || f < 0)
					printer(255, static_cast<int>(f), f, static_cast<double>(f));
				else
					printer(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f));
			}
			catch (std::exception& e)
			{
				std::cout << "Convertation error!" << std::endl;
			}
			break ;
		}

		case 'd':
		{
			try
			{
				const double d = toDouble(arg);
				if (d >= std::numeric_limits<float>::max()
					|| d <= -std::numeric_limits<float>::max())
					printer(255, LONG_MAX, std::numeric_limits<double>::max(), d);
				else if (d >= std::numeric_limits<int>::max()
					|| d <= -std::numeric_limits<int>::max())
					printer(255, LONG_MAX, static_cast<float>(d), d);
				else if (d >= 128 || d < 0)
					printer(255, static_cast<int>(d), static_cast<float>(d), d);
				else
					printer(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d);
			}
			catch (std::exception& e)
			{
				std::cout << "Convertation error!" << std::endl;
			}
			break ;
		}

		default:
			std::cout << "Looks like some kind of input error occurs." << std::endl;
			break ;
	}
}
