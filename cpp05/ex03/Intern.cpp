#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern &copy) 
{
    (void)copy;
}

Intern& Intern::operator=(const Intern &assign)
{
    (void)assign;
    return *this;
}

Intern::~Intern()
{

}

AForm* Intern::makeShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidential(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (Intern::*funcs[])(std::string) = {
        &Intern::makeShrubbery,
        &Intern::makeRobotomy,
        &Intern::makePresidential
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*funcs[i])(target); 
        }
    }
    std::cout << "Intern cannot create " << formName << " because it doesn't exist!" << std::endl;
    return NULL;
}