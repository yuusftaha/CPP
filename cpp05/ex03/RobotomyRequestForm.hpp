#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &assign);
        virtual ~RobotomyRequestForm();

        void execute(Bureaucrat const &executor) const;
};

#endif