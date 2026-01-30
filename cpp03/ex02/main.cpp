#include "ScavTrap.hpp"

int main() {
    std::cout << "--- ScavTrap Olusturuluyor ---" << std::endl;
    ScavTrap scav("Serena"); // Önce ClapTrap sonra ScavTrap mesajı gelmeli 

    std::cout << "\n--- Aksiyonlar ---" << std::endl;
    scav.attack("Düsman");    // ScavTrap'e özel saldırı mesajı [cite: 156]
    scav.guardGate();         // Özel yetenek [cite: 165, 166]

    std::cout << "\n--- ScavTrap Yok Ediliyor ---" << std::endl;
    // Kapsam dışına çıkınca önce ScavTrap sonra ClapTrap yıkıcıları çalışmalı 
    return 0; 
}