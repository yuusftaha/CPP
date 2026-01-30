#include "FragTrap.hpp"

int main() {
    std::cout << "--- FragTrap Olusturuluyor ---" << std::endl;
    FragTrap frag("Kanka"); 

    std::cout << "\n--- Aksiyonlar ---" << std::endl;
    frag.attack("Düsman");
    frag.highFivesGuys(); // Çak bir beşlik!

    std::cout << "\n--- FragTrap Yok Ediliyor ---" << std::endl;
    return 0; 
}