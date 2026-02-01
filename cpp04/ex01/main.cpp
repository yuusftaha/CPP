#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "1. SENIN ISTEDIGIN TEST (Basic Allocation & Leak Check)" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "2. ARRAY TESTI (PDF: Loop ile olustur ve sil)" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;

    int size = 4;
    const Animal* animals[size];

    for (int k = 0; k < size; k++)
    {
        if (k < size / 2)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }

    std::cout << "\n--- Array Temizleniyor ---" << std::endl;
    for (int k = 0; k < size; k++)
    {
        delete animals[k];
    }

    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "3. DEEP COPY TESTI (Kopyalanan nesne orjinali bozmamali)" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;

    Dog basic;
    {
        Dog tmp = basic;
        std::cout << "-> Scope bitiyor, 'tmp' yok ediliyor..." << std::endl;
    } 
    std::cout << "-> Scope disindayiz. 'basic' hala yasiyor olmali." << std::endl;
    std::cout << "-> Program bitiyor, 'basic' yok edilecek..." << std::endl;

    return 0;
}