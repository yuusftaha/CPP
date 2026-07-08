#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &assign);
        virtual ~PresidentialPardonForm();

        void execute(Bureaucrat const &executor) const;
};

#endif