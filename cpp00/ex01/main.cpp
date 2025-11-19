#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string value;
	while (1)
	{
		std::cout << "*******************************************************" << std::endl;
		std::cout << "*               WELCOME TO MY PHONEBOOK               *" << std::endl;
		std::cout << "* Write what you want to do following three operation *" << std::endl;
		std::cout << "*           ADD    |    SEARCH    |    EXIT           *" << std::endl;
		std::cout << "*******************************************************" << std::endl;

		std::getline(std::cin, value);

		if (value == "ADD")
		{
			phonebook.addContact();	
		}
		else if (value == "SEARCH")
		{
			if (phonebook.getCurrentIndex() == 0)
				std::cout << "Phonebook is empty." << std::endl;
			else
				phonebook.searchContact();
		}
		else if (value == "EXIT")
		{
			std::cout << "Program is terminated." << std::endl;
			std::exit(0);
		}
		else
			std::cout << "invalid entry" << std::endl;
	}
	return 0;
}
