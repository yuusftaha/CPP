#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() 
{
    std::cout << "--- VECTOR TEST ---" << std::endl;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    try {
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "Basarili! Vektorde bulundu: " << *it << std::endl;
        
        std::cout << "Olmayan bir sayiyi ariyoruz (99)" << std::endl;
        easyfind(vec, 99);
    } 
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- LIST TESTI ---" << std::endl;
    std::list<int> lst;
    lst.push_back(42);
    lst.push_back(43);
    lst.push_back(44);

    try {
        std::list<int>::iterator it2 = easyfind(lst, 44);
        std::cout << "Basarili! Listede bulundu: " << *it2 << std::endl;
        
        std::cout << "Olmayan bir sayiyi ariyoruz (100)..." << std::endl;
        easyfind(lst, 100);
    } 
    catch (const std::exception& e) {
        std::cout << "HATA YAKALANDI: " << e.what() << std::endl;
    }

    return 0;
}