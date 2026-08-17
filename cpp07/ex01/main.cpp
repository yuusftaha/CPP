#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(T const &x) 
{
    std::cout << x << " ";
}

int main() 
{
    int intArray[] = {1, 2, 3, 4, 5};
    std::cout << "Integer Array: ";
    ::iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    std::string strArray[] = {"Hello", "42", "World"};
    std::cout << "String Array : ";
    ::iter(strArray, 3, printElement<std::string>);
    std::cout << std::endl;

    const char charArray[] = {'a', 'b', 'c', 'd'};
    std::cout << "Const Array  : ";
    ::iter(charArray, 4, printElement<char>);
    std::cout << std::endl;

    return 0;
}