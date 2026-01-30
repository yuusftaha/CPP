#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout << "ScavTrap " << this->name << " has been constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    *this = copy;
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &assign)   
{
    if (this != &assign)
        ClapTrap::operator=(assign);
    std::cout << "ScavTrap Copy Assignment Operator called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " has been destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->energy_points > 0 && this->hit_points > 0)
    {
        this->energy_points--;
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ScavTrap " << this->name << " cannot attack (No Energy or HP)!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}
