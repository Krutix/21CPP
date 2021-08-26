#pragma once

#include <string>
#include <iostream>

class Animal
{
public:
	Animal(std::string type = "None") : _type(type)
	{
		std::cout << "Animal with type " << _type << " constructed\n";
	}

	Animal(Animal const& other) : _type(other._type)
	{
		std::cout << "Animal with type " << _type << " constructed from copying\n";
	}

	Animal& operator= (Animal const& other)
	{
		if (this == &other)
			return *this;
		_type = other._type;
		return *this;
	}

	virtual ~Animal()
	{
		std::cout << "Animal with type " << _type << " destructed\n";
	}

	std::string getType() const { return _type; }

	virtual void makeSound() const { std::cout << "**noise**\n"; }

private:
	std::string _type;
};


class Dog : public Animal
{
public:
	Dog() : Animal("Dog")
	{
		std::cout << "Dog with type " << this->getType() << " constructed\n";
	}

	Dog(Dog const& other) : Animal("Dog")
	{
		std::cout << "Dog with type " << this->getType() << " constructed from copying\n";
	}

	Dog& operator= (Dog const& other)
	{
		if (this == &other)
			return *this;
		this->Animal::operator=(other);
		return *this;
	}

	~Dog()
	{
		std::cout << "Dog with type " << this->getType() << " destructed\n";
	}

	void makeSound() const { std::cout << "WOOF!!!" << '\n'; }
};


class Cat : public Animal
{
public:
	Cat() : Animal("Cat")
	{
		std::cout << "Cat with type " << this->getType() << " constructed\n";
	}

	Cat(Cat const& other) : Animal("Cat")
	{
		std::cout << "Cat with type " << this->getType() << " constructed from copying\n";
	}

	Cat& operator= (Cat const& other)
	{
		if (this == &other)
			return *this;
		this->Animal::operator=(other);
		return *this;
	}

	~Cat()
	{
		std::cout << "Cat with type " << this->getType() << " destructed\n";
	}

	void makeSound() const { std::cout << "Nyaaaaa~~~" << '\n'; }
};


class WrongAnimal
{
public:
	void makeSound() const { std::cout << "As animal\n"; }
};

class WrongCat : public WrongAnimal
{
public:
	void makeSound() const { std::cout << "As cat\n"; }
};
