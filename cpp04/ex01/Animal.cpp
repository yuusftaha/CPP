#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    *this = copy;
    std::cout << "Animal Copy Constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &assign)
{
    if (this != &assign)
        this->type = assign.type;
    std::cout << "Animal Copy Assignment Operator called" << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal makes a generic sound..." << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}