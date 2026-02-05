#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
    protected:
        std::string type;
    public:
        AAnimal();
        AAnimal(const AAnimal &copy);
        AAnimal &operator=(const AAnimal &assign);
        virtual ~AAnimal();
        
        virtual void makeSound() const = 0;
        std::string getType() const;
};

#endif