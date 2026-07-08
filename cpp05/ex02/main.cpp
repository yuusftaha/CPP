#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(NULL));
	try
	{
		Bureaucrat patron("Patron", 1);       // Her şeye yetkisi var
        Bureaucrat mudur("Mudur", 50);        // Orta düzey yetkili
        Bureaucrat stajyer("Stajyer", 140);   // Sadece en alt düzey işlemleri yapabilir

        // 2. Formlarımızı Yaratıyoruz
        ShrubberyCreationForm shrub("Arka_Bahce");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Arthur_Dent");

        // === SHRUBBERY TEST (sign: 145, execute: 137) ===
        std::cout << "\n=== Shrubbery ===" << std::endl;
        stajyer.executeForm(shrub); // HATA: Form henüz imzalanmadı!
        stajyer.signForm(shrub);    // BAŞARILI: Stajyerin notu 140, imza için 145 yeterli.
        stajyer.executeForm(shrub); // HATA: İmzaladı ama çalıştırmak için 137 lazım, stajyerin yetkisi yetmez.
        mudur.executeForm(shrub);   // BAŞARILI: Müdür (50) gelir ve stajyerin imzaladığı formu çalıştırır.

        // === ROBOTOMY TEST (sign: 72, execute: 45) ===
        std::cout << "\n=== Robotomy ===" << std::endl;
        mudur.signForm(robo);       // BAŞARILI: Müdürün notu 50, imza için 72 yeterli.
        mudur.executeForm(robo);    // HATA: Müdür imzaladı ama çalıştırmak için 45 lazım, yetkisi yetmiyor.
        patron.executeForm(robo);   // BAŞARILI: Patron (1) çalıştırır, matkap sesleri başlar!

        // === PRESIDENTIAL PARDON TEST (sign: 25, execute: 5) ===
        std::cout << "\n=== Presidential Pardon ===" << std::endl;
        mudur.signForm(pardon);     // HATA: Müdürün yetkisi bu çok gizli belgeyi imzalamaya bile yetmez.
        patron.signForm(pardon);    // BAŞARILI: Patron imzalar.
        patron.executeForm(pardon); // BAŞARILI: Patron çalıştırır (Zaphod Beeblebrox affeder).

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}