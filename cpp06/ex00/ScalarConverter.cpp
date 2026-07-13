#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{

}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &assing)
{

}

void ScalarConverter::convert(std::string literal)
{
    if (literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0])) 
        char c = literal[0]; 


    bool isInt = true;
    size_t i = 0;

    if (literal[i] == '-' || literal[i] == '+')
        i++;

    if (i == literal.length()) 
        isInt = false;

    for (; isInt && i < literal.length(); i++) 
    {
        if (!std::isdigit(literal[i])) 
        {
            isInt = false;
            break;
        }
    }
    if (isInt)
    {
        long value = std::strtol(literal.c_str(), NULL, 10); 
        if (value >= INT_MIN && value <= INT_MAX)
            int intValue = static_cast<int>(value);
        else
            isInt = false; 
    }


    bool isFloat = false;

    if (literal == "nanf" || literal == "+inff" || literal == "-inff") 
        isFloat = true;
    else if (literal.length() > 1 && literal[literal.length() - 1] == 'f') 
    {
        int dotCount = 0;
        bool validChars = true;
        size_t i = 0;

        if (literal[i] == '-' || literal[i] == '+') 
            i++;
        for (; i < literal.length() - 1; i++) 
        {
            if (literal[i] == '.') 
                dotCount++;
            else if (!std::isdigit(literal[i])) 
            {
                validChars = false;
                break;
            }
        }
        if (validChars && dotCount == 1) 
            isFloat = true;
    }

    if (isFloat) 
    {
        double tempValue = std::strtod(literal.c_str(), NULL);
        float floatValue = static_cast<float>(tempValue);
    }


    bool isDouble = false;

    if (literal == "nan" || literal == "+inf" || literal == "-inf") 
        isDouble = true;
    else 
    {
        int dotCount = 0;
        size_t i = 0;
        isDouble = true;

        if (literal[i] == '-' || literal[i] == '+') 
            i++;

        if (i == literal.length()) 
            isDouble = false;

        for (; isDouble && i < literal.length(); i++) 
        {
            if (literal[i] == '.') 
                dotCount++;
            else if (!std::isdigit(literal[i])) 
            {
                isDouble = false; 
                break; 
            }
        }
        if (dotCount != 1) 
            isDouble = false;
    }

    if (isDouble) 
        double doubleValue = std::strtod(literal.c_str(), NULL);
}