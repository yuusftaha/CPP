#include "ScalarConverter.hpp"

// Sadece bir kere tanımlayıp her yerde kullanalım
static void printAll(double val, bool impossible = false) {
    if (impossible) {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
        return;
    }
    // Char
    std::cout << "char: ";
    if (val < 0 || val > 255 || val != val) std::cout << "impossible\n";
    else if (val < 32 || val == 127) std::cout << "Non displayable\n";
    else std::cout << "'" << static_cast<char>(val) << "'\n";

    // Int
    std::cout << "int: ";
    if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max() || val != val)
        std::cout << "impossible\n";
    else std::cout << static_cast<int>(val) << "\n";

    // Float & Double (Fixed precision kullanarak)
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(val) << "f\n";
    std::cout << "double: " << val << "\n";
}

void ScalarConverter::convert(std::string str) {
    // 1. Bilimsel İfadeler (Bunlar için kendi mantığımızı kuruyoruz)
    if (str == "nan" || str == "nanf") {
        std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
        return;
    }
    if (str == "+inf" || str == "+inff") {
        std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n";
        return;
    }
    if (str == "-inf" || str == "-inff") {
        std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n";
        return;
    }

    // 2. Kendi Parser Mantığımız (C++ stringstream ile daha kısa)
    double val;
    std::stringstream ss(str);
    
    // Eğer tek karakterse ve rakam değilse
    if (str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0])) {
        printAll(static_cast<double>(str[0]));
        return;
    }

    // Eğer bir sayıysa (stringstream ile kontrol)
    ss >> val;
    if (ss.fail()) {
        printAll(0, true);
    } else {
        printAll(val);
    }
}