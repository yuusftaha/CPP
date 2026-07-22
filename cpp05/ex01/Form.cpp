#include "Form.hpp"

Form::Form() : name("default"), sign(false), sign_grade(1), exec_grade(150)
{

}

Form::Form(const Form &copy) : name(copy.name), sign(false), sign_grade(copy.sign_grade), exec_grade(copy.exec_grade)
{

}

Form::~Form()
{

}

Form::Form(const std::string name, const int sign_grade, const int exec_grade) : name(name), sign(false), sign_grade(sign_grade), exec_grade(exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
        throw Form::GradeTooHighException();
    if (sign_grade > 150 || exec_grade > 150)
        throw Form::GradeTooLowException();
}

Form& Form::operator=(const Form &assign)
{
    if (this != &assign)
		this->sign = assign.sign;	
    return *this;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

std::string Form::getName() const
{
	return this->name;
}

bool Form::getSigned() const
{
	return this->sign;
}

int Form::getSignGrade() const
{
	return this->sign_grade;
}

int Form::getExecuteGrade() const
{
	return this->exec_grade;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (this->sign_grade < b.getGrade())
		throw Form::GradeTooLowException();
	else 
		this->sign = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form: " << f.getName() 
       << ", Status: " << (f.getSigned() ? "Signed" : "Not Signed")
       << ", Sign Grade required: " << f.getSignGrade()
       << ", Execute Grade required: " << f.getExecuteGrade() << std::endl;
    return os;
}