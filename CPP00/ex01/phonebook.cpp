#include <iostream>
#include <iomanip>

#define PHONEBOOK_CAPACITY 8

class Contact
{
public:
    Contact() {}

    Contact(std::string const& fn,
            std::string const& ln,
            std::string const& nn,
            std::string const& pn,
            std::string const& ds)
        : first_name(fn),
          last_name(ln),
          nickname(nn),
          phone_number(pn),
          darkest_secret(ds) {}

    inline void set_first_name(std::string const& fn) { this->first_name = fn; }
    inline void set_last_name(std::string const& ln) { this->last_name = ln; }
    inline void set_nickname(std::string const& nn) { this->nickname = nn; }
    inline void set_phone_number(std::string const& pn) { this->phone_number = pn; }
    inline void set_dargest_secret(std::string const& ds) { this->darkest_secret = ds; }
    inline std::string const& get_first_name() const { return this->first_name; }
    inline std::string const& get_last_name() const { return this->last_name; }
    inline std::string const& get_nickname() const { return this->nickname; }
    inline std::string const& get_phone_number() const { return this->phone_number; }
    inline std::string const& get_dargest_secret() const { return this->darkest_secret; }
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
};

std::string cut_with_dot(std::string const& str, size_t size);

class PhoneBook
{
public:
    PhoneBook();

    void add(std::istream& is);
    void search(std::istream& is);

private:
    size_t insert_person();

    void show_as_table() const;
    void show_contact(size_t idx) const;

    Contact _phonebook[PHONEBOOK_CAPACITY];
    size_t _size;
    size_t _shift;
};


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
    }
}


std::string cut_with_dot(std::string const& str, size_t size)
{
    if (str.size() > size)
        return str.substr(0, size - 1).append(".");
    return str;
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

    std::cout << "Enter first name: ";
    is >> first_name;
    std::cout << "Enter last name: ";
    is >> last_name;
    std::cout << "Enter nickname: ";
    is >> nickname;
    std::cout << "Enter phone number: ";
    is >> phone_number;
    std::cout << "Enter darkest secret: ";
    is >> darkest_secret;

    ::new (&_phonebook[insert_person()])Contact(first_name, last_name, nickname, phone_number, darkest_secret);
}

void   PhoneBook::search(std::istream& is)
{
    this->show_as_table();
    size_t idx;
    std::cout << "Contact index: ";
    is >> idx;
    if (idx >= _size)
        std::cout << "Index out of bounds";
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

size_t PhoneBook::insert_person()
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

