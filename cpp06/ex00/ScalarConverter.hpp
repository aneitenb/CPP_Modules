#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <climits>
#include <cfloat>

class ScalarConverter
{
private:
	//private constructor to prevent instantiation
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	static bool isChar(const std::string& str);
	static bool isInt(const std::string& str);
	static bool isFloat(const std::string& str);
	static bool isDouble(const std::string& str);
	static bool isPseudoLiteral(const std::string& str);
	static bool isDisplayable(int c);
	
	static void convertChar(char c);
	static void convertInt(int value);
	static void convertFloat(float value);
	static void convertDouble(double value);
	static void handlePseudoLiteral(const std::string& str);
	
public:
	static void convert(const std::string& str);
};

#endif