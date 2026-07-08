#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default")
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), target(copy.target)
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
    if (this != &assign)
		this->target = assign.target;	
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    AForm::checkForm(executor);
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}