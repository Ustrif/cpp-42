#ifndef __SCONVERTER__
#define __SCONVERTER__

#include <string>
#include <cctype>
#include <climits>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter &operator = (const ScalarConverter& other);

	public:
		static void	convert(const std::string param);
};

int		toInt(const std::string& param);
char	toChar(const std::string& param);
double	toDouble(const std::string& param);
float	toFloat(const std::string& param);
bool	isInf(const std::string& param);
bool	isNan(const std::string& param);
char	findType(const std::string& param);
void	printer(unsigned char c, long i, double f, double d);

#endif // __SCONVERTER__