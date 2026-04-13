#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include <exception>

class Form
{
	private:
		const std::string name;
		bool sign;
		const int sign_grade;
		const int exec_grade;
	public:
        Form();
        Form(const Form &copy);
        Form(const std::string name,const int sign_grade, const int exec_grade);
        Form &operator=(const Form &assign);
        ~Form();

		void beSigned(const Bureaucrat &b);
		std::string getName() const;
        bool getSigned() const;
        int  getSignGrade() const;
        int  getExecuteGrade() const;

	    class GradeTooHighException : public std::exception
        {
            public:
			virtual char const* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual char const* what() const throw();
        };
};
std::ostream& operator<<(std::ostream& os, const Form& f);
#endif