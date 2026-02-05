#include "ScavTrap.hpp"

int main() {
    std::cout << "--- ScavTrap Olusturuluyor ---" << std::endl;
    ScavTrap scav("Serena");

    std::cout << "\n--- Aksiyonlar ---" << std::endl;
    scav.attack("Düsman");
    scav.guardGate();

    std::cout << "\n--- ScavTrap Yok Ediliyor ---" << std::endl;
    return 0; 
}