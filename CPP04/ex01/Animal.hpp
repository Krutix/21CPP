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

class Brain
{
public:
	Brain() {}

	Brain(Brain const& other)
	{
		for (size_t i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}

	Brain& operator= (Brain const& other)
	{
		for (size_t i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
		return *this;
	}
private:
	std::string ideas[100];
};


class Dog : public Animal
{
public:
	Dog() : Animal("Dog"), brain(new Brain())
	{
		std::cout << "Dog with type " << this->getType() << " constructed\n";
	}

	Dog(Dog const& other) : Animal("Dog"), brain(new Brain(*other.brain))
	{
		std::cout << "Dog with type " << this->getType() << " constructed from copying\n";
	}

	Dog& operator= (Dog const& other)
	{
		if (this == &other)
			return *this;
		this->Animal::operator=(other);
		Brain* new_brain = new Brain(*other.brain);
		delete brain;
		brain = new_brain;
		return *this;
	}

	~Dog()
	{
		std::cout << "Dog with type " << this->getType() << " destructed\n";
		delete brain;
	}

	void makeSound() const { std::cout << "WOOF!!!" << '\n'; }
private:
	Brain *brain;
};


class Cat : public Animal
{
public:
	Cat() : Animal("Cat"), brain(new Brain())
	{
		std::cout << "Cat with type " << this->getType() << " constructed\n";
	}

	Cat(Cat const& other) : Animal("Cat"), brain(new Brain(*other.brain))
	{
		std::cout << "Cat with type " << this->getType() << " constructed from copying\n";
	}

	Cat& operator= (Cat const& other)
	{
		if (this == &other)
			return *this;
		this->Animal::operator=(other);
		Brain* new_brain = new Brain(*other.brain);
		delete brain;
		brain = new_brain;
		return *this;
	}

	~Cat()
	{
		std::cout << "Cat with type " << this->getType() << " destructed\n";
		delete brain;
	}

	void makeSound() const { std::cout << "Nyaaaaa~~~" << '\n'; }
private:
	Brain *brain;
};
