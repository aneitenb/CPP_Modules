#include "ScalarConverter.hpp"
#include <sstream>
#include <cstdlib>

// Private constructor to prevent instantiation
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& str)
{
	if (str.empty())
	{
		std::cout << "Error: Empty string" << std::endl;
		return;
	}

	if (isPseudoLiteral(str))
	{
		handlePseudoLiteral(str);
		return;
	}
	if (isChar(str))
	{
		char c = str[1];
		convertChar(c);
		return;
	}
	if (isFloat(str))
	{
		std::string withoutF = str.substr(0, str.length() - 1);
		float value = static_cast<float>(std::atof(withoutF.c_str()));
		convertFloat(value);
		return;
	}
	if (isDouble(str))
	{
		double value = std::atof(str.c_str());
		convertDouble(value);
		return;
	}
	if (isInt(str))
	{
		long long temp = std::atoll(str.c_str());
		if (temp > INT_MAX || temp < INT_MIN)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
		int value = static_cast<int>(temp);
		convertInt(value);
		return;
	}

	std::cout << "Error: Invalid input format" << std::endl;
}

bool ScalarConverter::isChar(const std::string& str)
{
	return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}

bool ScalarConverter::isInt(const std::string& str)
{
	if (str.empty())
		return false;
	
	size_t start = 0;
	if (str[0] == '+' || str[0] == '-')
		start = 1;
	
	if (start >= str.length())
		return false;
		
	for (size_t i = start; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string& str)
{
	if (str == "nanf" || str == "+inff" || str == "-inff")
		return true;
		
	if (str.length() < 2 || str[str.length() - 1] != 'f')
		return false;
		
	std::string withoutF = str.substr(0, str.length() - 1);
	return isDouble(withoutF);
}

bool ScalarConverter::isDouble(const std::string& str)
{
	if (str == "nan" || str == "+inf" || str == "-inf")
		return true;
		
	if (str.empty())
		return false;
		
	size_t start = 0;
	if (str[0] == '+' || str[0] == '-')
		start = 1;
	
	bool hasDot = false;
	bool hasDigit = false;
	
	for (size_t i = start; i < str.length(); i++)
	{
		if (str[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (std::isdigit(str[i]))
		{
			hasDigit = true;
		}
		else
		{
			return false;
		}
	}
	
	return hasDigit && hasDot;
}

bool ScalarConverter::isPseudoLiteral(const std::string& str)
{
	return (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || 
			str == "+inff" || str == "-inff");
}

bool ScalarConverter::isDisplayable(int c)
{
	return (c >= 32 && c <= 126);
}

void ScalarConverter::convertChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertInt(int value)
{
	// Char conversion
	if (value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isDisplayable(value))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	
	// Int conversion
	std::cout << "int: " << value << std::endl;
	
	// Float conversion
	std::cout << "float: " << static_cast<float>(value);
	if (value == static_cast<int>(static_cast<float>(value)))
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;
	
	// Double conversion
	std::cout << "double: " << static_cast<double>(value);
	if (value == static_cast<int>(static_cast<double>(value)))
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

void ScalarConverter::convertFloat(float value)
{
	// Check for special values
	if (std::isnan(value) || std::isinf(value))
	{
		handlePseudoLiteral(std::isnan(value) ? "nanf" : (value > 0 ? "+inff" : "-inff"));
		return;
	}
	
	// Char
	if (value < 0 || value > 127 || value != static_cast<int>(value))
		std::cout << "char: impossible" << std::endl;
	else if (!isDisplayable(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	
	// Int
	if (value > static_cast<float>(INT_MAX) || value < static_cast<float>(INT_MIN) || std::isnan(value) || std::isinf(value))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	
	// Float
	std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
	
	// Double
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertDouble(double value)
{
	if (std::isnan(value) || std::isinf(value))
	{
		handlePseudoLiteral(std::isnan(value) ? "nan" : (value > 0 ? "+inf" : "-inf"));
		return;
	}
	
	// Char
	if (value < 0 || value > 127 || value != static_cast<int>(value))
		std::cout << "char: impossible" << std::endl;
	else if (!isDisplayable(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	
	// Int
	if (value > static_cast<double>(INT_MAX) || value < static_cast<double>(INT_MIN) || std::isnan(value) || std::isinf(value))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	
	// Float
	if (std::abs(value) > static_cast<double>(FLT_MAX))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	
	// Double
	std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

void ScalarConverter::handlePseudoLiteral(const std::string& str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	
	if (str == "nan")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

