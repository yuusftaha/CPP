#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{   
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "2. ARRAY TEST" << std::endl;
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

    std::cout << "\n--- Array Delete ---" << std::endl;
    for (int k = 0; k < size; k++)
    {
        delete animals[k];
    }

    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "3. DEEP COPY TEST" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;

    Dog basic;
    {
        Dog tmp = basic;
    } 
    std::cout << "-------------------------------------------------------" << std::endl;
    return 0;
}