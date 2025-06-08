#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

void testCase(const std::string& testName, const std::string& input)
{
	std::cout << "\n=== Testing: " << testName << " (" << input << ") ===" << std::endl;
	ScalarConverter::convert(input);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::string input = argv[1];
		std::cout << "Testing input: " << input << std::endl;
		ScalarConverter::convert(input);
		return 0;
	}

	std::cout << "\n--- CHAR LITERAL TESTS ---" << std::endl;
	testCase("Printable char", "'a'");
	testCase("Digit char", "'9'");
	testCase("Space char", "' '");
	testCase("Special char", "'*'");

	std::cout << "\n--- INT LITERAL TESTS ---" << std::endl;
	testCase("Zero", "0");
	testCase("Positive int", "42");
	testCase("Negative int", "-42");
	testCase("ASCII value (displayable)", "65");  // 'A'
	testCase("ASCII value (non-displayable)", "10");  // newline
	testCase("Large positive", "2147483647");  // INT_MAX
	testCase("Large negative", "-2147483648"); // INT_MIN
	testCase("Out of int range", "2147483648"); // INT_MAX + 1

	std::cout << "\n--- FLOAT LITERAL TESTS ---" << std::endl;
	testCase("Zero float", "0.0f");
	testCase("Positive float", "42.5f");
	testCase("Negative float", "-42.5f");
	testCase("Float with int value", "42.0f");
	testCase("Small decimal", "0.1f");
	testCase("Large float", "3.4e38f");

	std::cout << "\n--- DOUBLE LITERAL TESTS ---" << std::endl;
	testCase("Zero double", "0.0");
	testCase("Positive double", "42.5");
	testCase("Negative double", "-42.5");
	testCase("Double with int value", "42.0");
	testCase("Scientific notation", "1.23e-4");
	testCase("Large double", "1.7e308");

	std::cout << "\n--- PSEUDO-LITERAL TESTS ---" << std::endl;
	testCase("NaN float", "nanf");
	testCase("NaN double", "nan");
	testCase("Positive infinity float", "+inff");
	testCase("Positive infinity double", "+inf");
	testCase("Negative infinity float", "-inff");
	testCase("Negative infinity double", "-inf");
	
	std::cout << "\n--- EDGE CASES AND ERROR TESTS ---" << std::endl;
	testCase("Empty string", "");
	testCase("Invalid char format", "'ab'");
	testCase("Invalid float", "42.5.3f");
	testCase("Just 'f'", "f");
	testCase("Letters", "hello");
	testCase("Mixed invalid", "42abc");
	testCase("Double dot", "42..5");
	testCase("No closing quote", "'a");
	
	std::cout << "\n--- BOUNDARY TESTS ---" << std::endl;
	testCase("Char boundary (127)", "127");
	testCase("Char boundary (128)", "128");
	testCase("Char boundary (-1)", "-1");
	testCase("ASCII 0", "0");
	testCase("ASCII 31 (non-printable)", "31");
	testCase("ASCII 32 (space)", "32");
	testCase("ASCII 126 (~)", "126");
	testCase("ASCII 127 (DEL)", "127");
	
	return 0;
}