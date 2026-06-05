#include "AForm.hpp"

AForm::AForm() : name("default"), sign(false), sign_grade(1), exec_grade(150)
{

}

AForm::AForm(const AForm &copy) : name(copy.name), sign(false), sign_grade(copy.sign_grade), exec_grade(copy.exec_grade)
{

}

AForm::~AForm()
{

}

AForm::AForm(const std::string name, const int sign_grade, const int exec_grade) : name(name), sign(false), sign_grade(sign_grade), exec_grade(exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
        throw AForm::GradeTooHighException();
    if (sign_grade > 150 || exec_grade > 150)
        throw AForm::GradeTooLowException();
}

AForm& AForm::operator=(const AForm &assign)
{
    if (this != &assign)
		this->sign = assign.sign;	
    return *this;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm grade is too low!";
}

void AForm::checkForm(Bureaucrat const & executor) const
{
    if (!this->getSigned())
        throw AForm::NotSignedException();
        
    if (executor.getGrade() > this->exec_grade)
        throw AForm::GradeTooLowException();
}

std::string AForm::getName() const
{
	return this->name;
}

bool AForm::getSigned() const
{
	return this->sign;
}

int AForm::getSignGrade() const
{
	return this->sign_grade;
}

int AForm::getExecuteGrade() const
{
	return this->exec_grade;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (this->sign_grade < b.getGrade())
		throw AForm::GradeTooLowException();
	else
		this->sign = true;
}

const char *AForm::NotSignedException::what() const throw()
{
    return "Form is not signed! Cannot execute.";
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << "AForm: " << f.getName() 
       << ", Status: " << (f.getSigned() ? "Signed" : "Not Signed")
       << ", Sign Grade required: " << f.getSignGrade()
       << ", Execute Grade required: " << f.getExecuteGrade();
    return os;
}
