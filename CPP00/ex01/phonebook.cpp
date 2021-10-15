#include <iostream>
#include <iomanip>
#include "phonebook.hpp"

namespace {
std::string cut_with_dot(std::string const& str, size_t size)
{
    if (str.size() > size)
        return str.substr(0, size - 1).append(".");
    return str;
}
}

PhoneBook::PhoneBook()
{
    _size = 0;
    _shift = 0;
}

void   PhoneBook::add(std::istream& is)
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    std::cout << "Enter first name:\n";
	std::getline(is, first_name);
    std::cout << "Enter last name:\n";
	std::getline(is, last_name);
    std::cout << "Enter nickname:\n";
	std::getline(is, nickname);
    std::cout << "Enter phone number:\n";
	std::getline(is, phone_number);
    std::cout << "Enter darkest secret:\n";
    std::getline(is, darkest_secret);

    _phonebook[next_insert_pos()] = Contact(
                            first_name, last_name,
                            nickname, phone_number,
                            darkest_secret);
}

void   PhoneBook::search(std::istream& is)
{
    this->show_as_table();
    size_t idx;
    std::cout << "Contact index: ";
    is >> idx;
    if (idx >= _size)
        std::cout << "Index out of bounds" << std::endl;
    else
        this->show_contact(idx);
}

void   PhoneBook::show_contact(size_t idx) const
{
    std::cout << "First name: " << _phonebook[idx].get_first_name() << '\n';
    std::cout << "Last name: " << _phonebook[idx].get_last_name() << '\n';
    std::cout << "Nickname: " << _phonebook[idx].get_nickname() << '\n';
    std::cout << "Phone number: " << _phonebook[idx].get_phone_number() << '\n';
    std::cout << "Darkest secret: " << _phonebook[idx].get_dargest_secret() << '\n';
}

void   PhoneBook::show_as_table() const
{
    for (size_t idx = 0; idx < _size; idx++)
    {
        std::cout << '[' << idx << ']' << "|"
            << std::setw(10) << cut_with_dot(_phonebook[idx].get_first_name(), 10) << "|"
            << std::setw(10) << cut_with_dot(_phonebook[idx].get_last_name(), 10) << "|"
            << std::setw(10) << cut_with_dot(_phonebook[idx].get_nickname(), 10) << "|\n";
    }
}

size_t PhoneBook::next_insert_pos()
{
    if (_size == PHONEBOOK_CAPACITY)
    {
        size_t pos = _shift;
        _shift = (_shift + 1) % PHONEBOOK_CAPACITY;
        return pos;
    }
    else
        return _size++;
}
