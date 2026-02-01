#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "\n------- NORMAL ANIMAL TEST -------" << std::endl;
    Animal *meta = new Animal();
    Animal *j = new Dog();
    Animal *i = new Cat();

    std::cout << "\n------- type -------" << std::endl;
    std::cout << "Type = " << j->getType() << std::endl;
    std::cout << "Type = " << i->getType() << std::endl;
    
    std::cout << "\n------- sound -------" << std::endl;
    j->makeSound();
    i->makeSound();
    meta->makeSound();

    std::cout << "\n------- delete -------" << std::endl;
    delete j;
    delete i;



    std::cout << "\n------- WRONG ANIMAL TEST -------" << std::endl;
    WrongAnimal* wrongMeta = new WrongAnimal();
    WrongAnimal* wrongCat = new WrongCat();

    std::cout << "\n------- sound -------" << std::endl;
    wrongCat->makeSound();
    wrongMeta->makeSound();

    std::cout << "\n------- delete -------" << std::endl;
    delete wrongCat;
    delete wrongMeta;

    return 0;
}
