#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private:
    std::string name;

    public:
    void setZombieName(std::string name);
    void announce();
    ~Zombie();

};

Zombie* ZombieHorde(int N, std::string name);

#endif