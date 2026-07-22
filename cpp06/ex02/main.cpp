#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) 
{
    int random = rand() % 3;
    
    if (random == 0)
        return new A;
    else if (random == 1)
        return new B;
    else
        return new C;
}

void identify(Base* p) 
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "Pointer tipi: A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "Pointer tipi: B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "Pointer tipi: C" << std::endl;
    else
        std::cout << "Bilinmeyen tip!" << std::endl;
}

void identify(Base& p) 
{
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Referans tipi: A" << std::endl;
    } 
    catch (const std::exception& e) 
    {

    }
    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Referans tipi: B" << std::endl;
    } 
    catch (const std::exception& e) 
    {

    }
    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Referans tipi: C" << std::endl;
    } 
    catch (const std::exception& e)
    {

    }
}

int main() 
{
    std::srand(time(0));
    Base* randomObj = generate();

    identify(randomObj);
    identify(*randomObj);

    delete randomObj;
    return 0;
}