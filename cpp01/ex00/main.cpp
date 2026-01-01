#include "Zombie.hpp"

int main()
{
    randomChump("Foo");
    std::cout << "--------------------------------" << std::endl;
    Zombie *heapZombie = newZombie("Bar");
    heapZombie->announce();
    delete heapZombie;

    return 0;
}