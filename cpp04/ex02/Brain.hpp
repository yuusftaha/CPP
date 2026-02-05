#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
    public:
        std::string ideas[100];

        Brain();
        Brain(const Brain &copy);
        Brain &operator=(const Brain &assign);
        ~Brain();
};

#endif