#include <iostream>
#include "phonebook.hpp"

int main()
{
    PhoneBook phonebook;

    while (true)
    {
        std::string input;
        std::cin >> input;

        if      (input == "ADD")
            phonebook.add(std::cin);
        else if (input == "SEARCH")
            phonebook.search(std::cin);
        else if (input == "EXIT")
            return (0);
		else
			std::cout << "Invalid command" << std::endl;
    }
}