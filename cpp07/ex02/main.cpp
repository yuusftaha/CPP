#include <iostream>
#include "Array.hpp"

int main() 
{
    std::cout << "--- 1. Basic Testi ---" << std::endl;
    Array<int> sayilar(5);
    
    for (unsigned int i = 0; i < sayilar.size(); i++) 
    {
        sayilar[i] = i * 10;
        std::cout << "sayilar[" << i << "] = " << sayilar[i] << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- 2. Deep Copy Test ---" << std::endl;
    Array<int> kopyaDizi(sayilar);
    kopyaDizi[0] = 999;
    
    std::cout << "Orijinal dizinin 0. elemani : " << sayilar[0] << " (Degismemeli)" << std::endl;
    std::cout << "Kopya dizinin 0. elemani    : " << kopyaDizi[0] << std::endl;
    std::cout << std::endl;

    std::cout << "--- 3. Error Test ---" << std::endl;
    try {
        std::cout << "100. indekse erismeye calisiyoruz." << std::endl;
        sayilar[100] = 42;
        std::cout << "Bu yazi asla ekrana basilmayacak!" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}