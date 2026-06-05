#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include <exception>

class AForm
{
	private:
		const std::string name;
		bool sign;
		const int sign_grade;
		const int exec_grade;
	public:
        AForm();
        AForm(const AForm &copy);
        AForm(const std::string name,const int sign_grade, const int exec_grade);
        AForm &operator=(const AForm &assign);
        virtual ~AForm();

		void beSigned(const Bureaucrat &b);
		std::string getName() const;
        bool getSigned() const;
        int  getSignGrade() const;
        int  getExecuteGrade() const;

        virtual void execute(Bureaucrat const & executor) const = 0;
        void checkForm(Bureaucrat const & executor) const;

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

        class NotSignedException : public std::exception {
            public:
                virtual char const* what() const throw();
        };
};
std::ostream& operator<<(std::ostream& os, const AForm& f);
#endif