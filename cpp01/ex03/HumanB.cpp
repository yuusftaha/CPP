#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{

}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack()
{
    if (this->weapon != NULL)
    {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    }
    else
    {
        std::cout << name << " has no weapon to attack with!" << std::endl;
    }
}