#include <iostream>
#include <string>
#include "iter.hpp"

// TEST FONKSİYONU 1: Sadece okuyan ve ekrana yazdıran (Değiştirmez)
// Parametreyi 'const T&' olarak alır, böylece const dizilerle de sorunsuz çalışır.
template <typename T>
void print(T const & x) {
    std::cout << x << " ";
}

// TEST FONKSİYONU 2: Üzerinde işlem yapan (Değiştirir)
// Parametreyi 'T&' olarak alır, dizideki orijinal elemanı kalıcı olarak günceller.
template <typename T>
void increment(T & x) {
    x++;
}

int main() {
    // ---------------------------------------------------------
    // TEST 1: Normal Integer Dizisi (Değiştirme ve Yazdırma)
    // ---------------------------------------------------------
    int intArray[] = {10, 20, 30, 40};
    size_t intLen = sizeof(intArray) / sizeof(intArray[0]);
    
    std::cout << "--- 1. Integer Testi ---" << std::endl;
    std::cout << "Orijinal: ";
    ::iter(intArray, intLen, print<int>);
    std::cout << std::endl;

    // Sayıları 1 artırıyoruz
    ::iter(intArray, intLen, increment<int>); 
    
    std::cout << "Artmis  : ";
    ::iter(intArray, intLen, print<int>);
    std::cout << std::endl << std::endl;


    // ---------------------------------------------------------
    // TEST 2: String Dizisi (Farklı Veri Tipi Testi)
    // ---------------------------------------------------------
    std::string strArray[] = {"42", "Istanbul", "Core", "Program"};
    size_t strLen = sizeof(strArray) / sizeof(strArray[0]);
    
    std::cout << "--- 2. String Array Testi ---" << std::endl;
    std::cout << "Stringler: ";
    ::iter(strArray, strLen, print<std::string>);
    std::cout << std::endl << std::endl;


    // ---------------------------------------------------------
    // TEST 3: Const Dizisi (Güvenlik Testi)
    // ---------------------------------------------------------
    const double constArray[] = {3.14, 2.71, 1.61};
    size_t constLen = sizeof(constArray) / sizeof(constArray[0]);
    
    std::cout << "--- 3. Const Array Testi ---" << std::endl;
    std::cout << "Sabitler: ";
    ::iter(constArray, constLen, print<double>);
    std::cout << std::endl;

    // NOT: Aşağıdaki satırı açarsan program derlenmez!
    // Çünkü 'constArray' değiştirilemez, ancak 'increment' değiştirmeye çalışır.
    // Bu da şablonunun tip güvenliğini başarıyla sağladığını kanıtlar.
    // ::iter(constArray, constLen, increment<double>); 

    return 0;
}