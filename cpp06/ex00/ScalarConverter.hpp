#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <cctype>
#include <cstdlib> // strtol (string to long)
#include <climits> // INT_MAX, INT_MIN

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(const ScalarConverter &assign);
        ~ScalarConverter();
    public:
        static void convert(std::string literal);
};

#endif