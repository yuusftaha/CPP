#include "Zombie.hpp"

int main()
{
    Zombie* horde = ZombieHorde(5, "yusuf");
    
    for (int i = 0; i < 5; ++i)
    {
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}