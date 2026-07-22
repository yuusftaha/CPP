#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{ 
    
}
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{ 
    (void)other; 
}
ScalarConverter::~ScalarConverter()
{

}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{ 
    (void)other; return *this; 
}

static void printAll(double val, bool impossible = false) 
{
    if (impossible) 
    {
        std::cout << "char: impossible" << std::endl
        << "int: impossible" << std::endl
        << "float: impossible" << std::endl
        << "double: impossible" << std::endl;
        return;
    }
    
    std::cout << "char: ";
    if (val < 0 || val > 255 || val != val) 
        std::cout << "impossible" << std::endl;
    else if (val < 32 || val == 127) 
        std::cout << "Non displayable" << std::endl;
    else 
        std::cout << "'" << static_cast<char>(val) << "'" << std::endl;

    std::cout << "int: ";
    if (val < INT_MIN || val > INT_MAX|| val != val)
        std::cout << "impossible" << std::endl;
    else 
        std::cout << static_cast<int>(val) << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(val) << "f\n";
    std::cout << "double: " << val << "\n";
}

void ScalarConverter::convert(std::string str) 
{
    if (str == "nan" || str == "nanf") 
    {
        std::cout << "char: impossible" << std::endl
        << "int: impossible" << std::endl
        << "float: nanf" << std::endl
        << "double: nan" << std::endl;
        return;
    }
    if (str == "+inf" || str == "+inff") 
    {
        std::cout << "char: impossible"  << std::endl
        << "int: impossible" << std::endl 
        << "float: +inff" << std::endl 
        << "double: +inf" << std::endl;
        return;
    }
    if (str == "-inf" || str == "-inff") 
    {
        std::cout << "char: impossible" << std::endl
        << "int: impossible" << std::endl
        << "float: -inff" << std::endl
        << "double: -inf" << std::endl;
        return;
    }

    double val;
    std::stringstream ss(str);
    if (str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]))
    {
        printAll(static_cast<double>(str[0]));
        return;
    }
    ss >> val;
    if (ss.fail()) 
    {
        printAll(0, true);
        return;
    } 
    std::string leftover;
    ss >> leftover; 
    if (!leftover.empty() && leftover != "f")
        printAll(0, true);
    else
        printAll(val);
}