#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <climits>
#include <limits>

int	toInt(const std::string& param)
{
	int	result;

	std::stringstream ss(param);
	ss >> result;

	if (ss.fail())
	{
		throw std::invalid_argument("No number for int!");
	}
	return (result);
}

char	toChar(const std::string& param)
{
	char	result;

	std::stringstream ss(param);
	ss >> result;

	if (ss.fail())
	{
		throw std::invalid_argument("No number for char!");
	}
	return (result);
}

double	toDouble(const std::string& param)
{
	double	result;

	std::istringstream iss(param);
	iss >> result;

	if (iss.fail())
	{
		throw std::invalid_argument("No number for double!");
	}
	return (result);
}

float	toFloat(const std::string& param)
{
	float	result;

	std::stringstream ss(param);
	ss >> result;
	if (ss.fail())
	{
		throw std::invalid_argument("No number for float!");
	}
	return (result);
}

bool	isInf(const std::string& param)
{
	const std::string	infinite = "inf";
	const std::string	infinite1 = "+inf";
	const std::string	infinite2 = "-inf";
	const std::string	infinite3 = "inff";
	const std::string	infinite4 = "+inff";
	const std::string	infinite5 = "-inff";

	if (infinite.compare(param) == 0
		|| infinite1.compare(param) == 0
		|| infinite2.compare(param) == 0
		|| infinite3.compare(param) == 0
		|| infinite4.compare(param) == 0
		|| infinite5.compare(param) == 0)
		return (1);
	return (0);
}

bool	isNan(const std::string& param)
{
	const std::string	nan = "nan";
	const std::string	nanf = "nanf";

	if (nan.compare(param) == 0
		|| nanf.compare(param) == 0)
		return (1);
	return (0);
}

char	findType(const std::string& param)
{
	if (param.empty())
		return ('0');

	if (isNan(param))
		return ('n');
	else if (isInf(param))
		return ('l');
	else if (param.length() == 1 && std::isalpha(param.at(0)))
		return ('c');
	else if (param.at(param.size() - 1) == 'f')
		return ('f');
	else
	{
		for (std::size_t i = 0; i < param.size(); i++)
		{
			if (param.at(i) == '.')
				return ('d');
		}
	}
	if (std::isdigit(param.at(0))
		|| ((param.at(0) == '-' || param.at(0) == '+') 
			&& param.size() >= 2 && std::isdigit(param.at(1))))
		return ('i');
	return ('0');
}

void	printer(unsigned char c, long i, double f, double d)
{
	// Char
	if (std::iscntrl(c))
		std::cout << "char: Non displayable" << std::endl;
	else if (c == UCHAR_MAX)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	
	// Int
	if (i == LONG_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;

	// Float
	if (std::isnan(f))
		std::cout << "float: nanf" << std::endl;
	else if (!std::isfinite(f))
		std::cout << "float: inff" << std::endl;
	else if (f == std::numeric_limits<double>::max())
		std::cout << "float: impossible" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f << "f" << std::endl;
	}

	// Double
	if (std::isnan(d))
		std::cout << "double: nan" << std::endl;
	else if (!std::isfinite(d))
		std::cout << "double: inf" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "double: " << d << std::endl;
	}
}
