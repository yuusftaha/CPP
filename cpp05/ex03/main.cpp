#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() 
{
    srand(time(NULL));

    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "[ START ] Boss and Intern are getting to work..." << std::endl;
    std::cout << "---------------------------------------------------------\n" << std::endl;

    Bureaucrat boss("boss", 1); 
    Intern someRandomIntern;         

    AForm* rrf = NULL;
    AForm* scf = NULL;
    AForm* ppf = NULL;
    AForm* fail = NULL;

    std::cout << "\n=== INTERN IS CREATING FORMS ===" << std::endl;
    
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    scf = someRandomIntern.makeForm("shrubbery creation", "Arka_Bahce");
    ppf = someRandomIntern.makeForm("presidential pardon", "Arthur_Dent");
    
    fail = someRandomIntern.makeForm("make tea form", "boss");

    std::cout << "\n=== BOSS SIGNS AND EXECUTES FORMS ===" << std::endl;
    
    if (rrf != NULL) 
    {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
    }
    
    if (scf != NULL) 
    {
        std::cout << std::endl;
        boss.signForm(*scf);
        boss.executeForm(*scf);
    }

    if (ppf != NULL) 
    {
        std::cout << std::endl;
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
    }

    if (fail != NULL)
    {
        boss.signForm(*fail);
        boss.executeForm(*fail);
    }

    std::cout << "\n---------------------------------------------------------" << std::endl;
    std::cout << "[ CLEANUP ] Freeing memory (Preventing Memory Leaks)" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;

    delete rrf;
    delete scf;
    delete ppf;

    return 0;
}