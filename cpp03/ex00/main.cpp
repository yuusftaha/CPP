#include "ClapTrap.hpp"

int main()
{
    ClapTrap robot("robot");
    
    std::cout << "\nENERJI TUKETIM TESTI BASLIYOR\n" << std::endl;
    for (int i = 1; i <= 12; i++)
    {
        std::cout << "Tur " << i << ": ";
        robot.attack("hedef");
    }
    std::cout << "\nTAMIR DENEMESI" << std::endl;
    robot.beRepaired(10);

    std::cout << "\nTEST BITTI\n" << std::endl;

    return 0;
}