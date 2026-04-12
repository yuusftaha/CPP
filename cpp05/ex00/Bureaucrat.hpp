#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat(const std::string name, int grade);
        Bureaucrat &operator=(const Bureaucrat &assign);
        ~Bureaucrat();

        void incrementGrade();
        void decrementGrade();
        
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

        std::string getName() const;
        int getGrade() const;
        void setGrade(int &grade);

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);//burası araştırılacak 
#endif