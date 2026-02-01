#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    *this = copy;
    std::cout << "Brain Copy Constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &assign)
{
    if (this != &assign)
    {
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = assign.ideas[i];
        }
    }
    std::cout << "Brain Copy Assignment Operator called" << std::endl;
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}