#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat a("Alice", 50);
	Bureaucrat b("Bella", 150);
	
	Form f("First Form", 75, 100);
	Form s("Second Form", 50, 60);

	std::cout << a;
	std::cout << b;

	std::cout << std::endl << "---------------------------------------" << std::endl << std::endl;

	std::cout << f;
	std::cout << f.getName() << " sign grade is " << f.getSignGrade() << std::endl;
	std::cout << s;
	std::cout << s.getName() << " sign grade is " << s.getSignGrade() << std::endl;


	std::cout << std::endl << "---------------------------------------" << std::endl << std::endl;

	a.signForm(f);
	std::cout << f;

	std::cout << std::endl << "---------------------------------------" << std::endl << std::endl;

	b.signForm(s);
	std::cout << s;
	
	std::cout << std::endl << "---------------------------------------" << std::endl << std::endl;

	a.signForm(s);
	std::cout << s;

	return 0;
}