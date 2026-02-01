#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    this->brain = new Brain(*copy.brain);
    std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &assign)
{
    if (this != &assign)
    {
        Animal::operator=(assign);
        delete this->brain;
        this->brain = new Brain(*assign.brain);
    }
    std::cout << "Cat Copy Assignment Operator called" << std::endl;
    return *this;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Miiaaavv Miiaaavv" << std::endl;
}