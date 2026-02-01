#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    *this = copy;
    std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &assign)
{
    if (this != &assign)
        Animal::operator=(assign);
    std::cout << "Dog Copy Assignment Operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Havv Havvv" << std::endl;
}