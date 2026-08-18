#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{
    std::cout << "--- SUBJECT TEST ---" << std::endl;
    try 
	{
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest : " << sp.longestSpan() << std::endl;
    } 
    catch (std::exception& e) 
	{
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- ERROR TEST ---" << std::endl;
    try 
	{
        Span sp2 = Span(1);
        sp2.addNumber(42);
        sp2.shortestSpan();
    } 
    catch (std::exception& e) 
	{
        std::cout << e.what() << std::endl;
    }

    
    std::cout << "\n--- 10.000 INSERT TEST ---" << std::endl;
    try 
	{
        Span bigSpan(10000);
        std::vector<int> rastgeleSayilar;
        
        std::srand(std::time(NULL)); 
        
        for (int i = 0; i < 10000; i++) {
            rastgeleSayilar.push_back(std::rand() % 1000000); 
        }

        bigSpan.addNumbers(rastgeleSayilar.begin(), rastgeleSayilar.end());

        std::cout << "10.000 eleman basariyla eklendi." << std::endl;
        std::cout << "Shortest (10K): " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest  (10K): " << bigSpan.longestSpan() << std::endl;

        std::cout << "\nLimiti asmaya calisiyoruz..." << std::endl;
        bigSpan.addNumber(42);
    }
    catch (std::exception& e) 
	{
        std::cout << e.what() << std::endl;
    }

    return 0;
}