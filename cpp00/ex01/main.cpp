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
			if (!phonebook.addContact())
			{
				/* HATA DURUMU */
			}
			
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
			/* code */
		}
	}
	return 0;
}
