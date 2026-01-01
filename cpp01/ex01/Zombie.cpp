#include "Zombie.hpp"

void Zombie::setZombieName(std::string name)
{
    this->name = name;
}

void Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->name << ": destroyed." << std::endl;
}
