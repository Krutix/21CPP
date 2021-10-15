#pragma once

#include <string>

#define PHONEBOOK_CAPACITY 8

class Contact
{
public:
    Contact() {}

    Contact(std::string const& fn,
            std::string const& ln,
            std::string const& nn,
            std::string const& pn,
            std::string const& ds);

    inline void set_first_name(std::string const& fn);
    inline void set_last_name(std::string const& ln);
    inline void set_nickname(std::string const& nn);
    inline void set_phone_number(std::string const& pn);
    inline void set_dargest_secret(std::string const& ds);
    inline std::string const& get_first_name() const;
    inline std::string const& get_last_name() const;
    inline std::string const& get_nickname() const;
    inline std::string const& get_phone_number() const;
    inline std::string const& get_dargest_secret() const;
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
};

#include "contact.inl"

class PhoneBook
{
public:
    PhoneBook();

    void add(std::istream& is);
    void search(std::istream& is);

private:
    size_t next_insert_pos();

    void show_as_table() const;
    void show_contact(size_t idx) const;

    Contact _phonebook[PHONEBOOK_CAPACITY];
    size_t _size;
    size_t _shift;
};
