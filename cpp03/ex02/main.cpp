#include "FragTrap.hpp"

int main() {
    std::cout << "--- FragTrap Olusturuluyor ---" << std::endl;
    FragTrap frag("Kanka"); 

    std::cout << "\n--- Aksiyonlar ---" << std::endl;
    frag.attack("Düsman");
    frag.highFivesGuys();

    std::cout << "\n--- FragTrap Yok Ediliyor ---" << std::endl;
    return 0; 
}