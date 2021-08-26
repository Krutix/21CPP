#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>

class Base
{
public:
	virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate()
{
	static size_t rand = 0;
	static A a;
	static B b;
	static C c;

	switch (rand++ % 3)
	{
		case 0:
			return &a;
		case 1:
			return &b;
		case 2:
			return &c;
	}
	return NULL;
}

void identify(Base& p)
{
	try {
		dynamic_cast<A&>(p);
		std::cout << "Its A class\n";
	} catch (std::exception&) {}
	try {
		dynamic_cast<B&>(p);
		std::cout << "Its B class\n";
	} catch (std::exception&) {}
	try {
		dynamic_cast<C&>(p);
		std::cout << "Its C class\n";
	} catch (std::exception&) {}
	return;
}


int main()
{
	identify(*generate());
	identify(*generate());
	identify(*generate());
	identify(*generate());
	identify(*generate());
	identify(*generate());
	identify(*generate());
	identify(*generate());
}
