#include <iostream>
#include "phonebook.hpp"

int main()
{
    PhoneBook phonebook;

    while (true)
    {
        std::string input;
        if (std::getline(std::cin, input) == false)
            return 0;

        if      (input == "ADD")
            phonebook.add(std::cin);
        else if (input == "SEARCH")
            phonebook.search(std::cin);
        else if (input == "EXIT")
            return 0;
		else
			std::cout << "Invalid command" << std::endl;
    }
}