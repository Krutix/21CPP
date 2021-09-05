#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>

namespace ft {
size_t random()
{
	static size_t rand;
	static size_t rand_stack[] = {
		91, 140, 216, 167, 161, 122, 133, 130, 249, 222, 7, 115, 182, 23,
		236, 190, 164, 85, 230, 181, 141, 86, 218, 224, 121, 9, 132, 186,
		57, 30, 144, 35, 154, 231, 171, 105, 193, 98, 73, 229, 191, 97,
		8, 74, 131, 213, 188, 79, 53, 187, 138, 124, 241, 255, 89, 145, 125,
		59, 93, 62, 199, 92, 129, 21, 49, 163, 180, 100, 183, 43, 120, 128,
		165, 6, 156, 142, 1, 18, 201, 243, 184, 32, 22, 196, 113, 232, 39, 66,
		200, 80, 170, 20, 221, 148, 65, 209, 237, 157, 60, 117, 106, 227, 253,
		114, 2, 109, 217, 99, 45, 251, 247, 81, 52, 134, 38, 25, 192, 233, 75,
		41, 55, 64, 219, 208, 172, 110, 46, 223, 47, 242, 214, 119, 173,
		10, 107, 34, 42, 205, 136, 204, 48, 5, 252, 15, 143, 220, 235,
		70, 178, 37, 19, 58, 169, 4, 16, 116, 17, 177, 234, 83, 197, 239,
		104, 3, 13, 127, 168, 67, 29, 194, 244, 72, 139, 245, 175, 151, 189,
		103, 36, 160, 78, 158, 153, 202, 84, 211, 63, 108, 40, 210, 87, 0, 246,
		240, 24, 135, 248, 126, 123, 90, 250, 137, 179, 94, 54, 166, 31, 111, 61,
		226, 56, 203, 254, 150, 146, 152, 215, 50, 228, 159, 147, 112, 149, 118,
		26, 14, 76, 185, 68, 95, 11, 71, 155, 176, 77, 162, 27, 198, 69, 101, 206,
		12, 44, 207, 28, 88, 212, 225, 82, 102, 33, 238, 195, 174, 96, 51
	};
	return rand = rand_stack[rand];
}
};


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
	static A a;
	static B b;
	static C c;

	switch (ft::random() % 3)
	{
		case 0:
			std::cout << "Gen A class\n";
			return &a;
		case 1:
			std::cout << "Gen B class\n";
			return &b;
		case 2:
			std::cout << "Gen C class\n";
			return &c;
	}
	return NULL;
}

void identify(Base& p)
{
	try {
		dynamic_cast<A&>(p);
		std::cout << "Its A class\n";
		return;
	} catch (std::exception&) {}
	try {
		dynamic_cast<B&>(p);
		std::cout << "Its B class\n";
		return;
	} catch (std::exception&) {}
	try {
		dynamic_cast<C&>(p);
		std::cout << "Its C class\n";
		return;
	} catch (std::exception&) {}
	std::cout << "Invalid class!!!\n";
	return;
}


int main()
{
	for (size_t i = 0; i < 25; i++)
	{
		identify(*generate());
		std::cout << "--------------------\n";
	}
}
