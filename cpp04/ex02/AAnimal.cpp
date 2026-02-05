#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
    std::cout << "AAnimal Default Constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
    *this = copy;
    std::cout << "AAnimal Copy Constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &assign)
{
    if (this != &assign)
        this->type = assign.type;
    std::cout << "AAnimal Copy Assignment Operator called" << std::endl;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal Destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
    return this->type;
}