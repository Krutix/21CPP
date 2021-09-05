#include "Animal.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	const WrongCat* as_cat = new WrongCat();
	const WrongAnimal* as_animal = as_cat;
	as_animal->makeSound();
	as_cat->makeSound();
	delete as_cat;
	delete i;
	delete j;
	delete meta;
}
