#include "Bureaucrat.hpp"

int main()
{
    std::cout <<"---------MAIN TEST---------" << std::endl;
    try
    {
        Bureaucrat a("Ahmet",50);
        std::cout << a;
        a.decrementGrade();
        std::cout << a;
        a.incrementGrade();
        std::cout << a << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR " << e.what() << std::endl;
    }

    std::cout <<"---------TEST ERROR : HIGH---------" << std::endl;
    try
    {
        Bureaucrat a("James",1);
        std::cout << a;
        a.incrementGrade();
        std::cout << a << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR " << e.what() << std::endl;
    }

    std::cout <<"---------TEST ERROR : LOW---------" << std::endl;
    try
    {
        Bureaucrat a("Alex",150);
        std::cout << a;
        a.decrementGrade();
        std::cout << a << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR " << e.what() << std::endl;
    }

    std::cout <<"---------TEST CREATER ERROR---------" << std::endl;
    try
    {
        Bureaucrat a("Alex",0);
        std::cout << a;
        a.incrementGrade();
        std::cout << a << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR " << e.what() << std::endl;
    }
    return 0;
}
