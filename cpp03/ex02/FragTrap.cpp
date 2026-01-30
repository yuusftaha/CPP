#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << "FragTrap " << this->name << " has been constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    *this = copy;
    std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &assign)
{
    if (this != &assign)
        ClapTrap::operator=(assign);
    std::cout << "FragTrap Copy Assignment Operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " has been destroyed!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (this->energy_points > 0 && this->hit_points > 0)
    {
        this->energy_points--;
        std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    }
    else
        std::cout << "FragTrap " << this->name << " cannot attack (No Energy or HP)!" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->name << " : Hey guys, give me a high five!" << std::endl;
}
