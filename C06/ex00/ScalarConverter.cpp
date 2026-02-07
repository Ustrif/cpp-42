#include "ScalarConverter.hpp"
#include <iostream>

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
	std::cout << "Scalar Converter Class Copy Constructor!" << std::endl;
}

ScalarConverter ScalarConverter::operator = (const ScalarConverter& other)
{
	std::cout << "Scalar Converter Class Copy Assigment Operator!" << std::endl;
	return (*this);
}

void	ScalarConverter::convert(const std::string param)
{
	//static_cast<int>(param.c_str());
}
