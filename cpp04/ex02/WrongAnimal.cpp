#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout << "WrongAnimal Copy Constructor called" << std::endl;
    *this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &assign)
{
    std::cout << "WrongAnimal Copy Assignment Operator called" << std::endl;
    if (this != &assign)
        this->type = assign.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal makes a weird sound..." << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}