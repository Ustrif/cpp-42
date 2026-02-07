#ifndef __SCONVERTER__
#define __SCONVERTER__

#include <string>
#include <cctype>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter operator = (const ScalarConverter& other);
	public:
		static void	convert(const std::string param);
};

#endif // __SCONVERTER__