#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string user_name) : name(user_name), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap " << name << " has been constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    *this = copy;
    std::cout << "ClapTrap Copy Constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &assign)
{
    if (this != &assign)
    {
        this->name = assign.name;
        this->hit_points = assign.hit_points;
        this->energy_points = assign.energy_points;
        this->attack_damage = assign.attack_damage;
    }
    std::cout << "ClapTrap Copy Assignment Operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (energy_points > 0 && hit_points > 0)
    {
        energy_points--;
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << name << " cannot attack (No Energy or No HP left)!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hit_points > 0)
    {
        if (amount >= hit_points)
        {
            hit_points = 0;
            std::cout << "ClapTrap " << name << " took " << amount << " damage and died!" << std::endl;
        }
        else
        {
            hit_points -= amount;
            std::cout << "ClapTrap " << name << " took " << amount << " damage!" << std::endl;
        }
    }
    else
    {
        std::cout << "ClapTrap " << name << " is already dead, stop hitting it!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energy_points > 0 && hit_points > 0)
    {
        energy_points--;
        hit_points += amount;
        std::cout << "ClapTrap " << name << " repairs itself, recovering " << amount << " hit points!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << name << " cannot be repaired (No Energy or No HP left)!" << std::endl;
    }
}