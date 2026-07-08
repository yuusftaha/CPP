#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), target(copy.target)
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
    if (this != &assign)
		this->target = assign.target;	
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    AForm::checkForm(executor);
    std::cout << "Bzzzzzzz" << std::endl;
    if (rand() % 2 == 0)
        std::cout << this->target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy failed on " << this->target << std::endl;
}