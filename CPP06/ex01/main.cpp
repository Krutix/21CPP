#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>

struct Data
{
	int i;
};

typedef unsigned long long uintptr_t;

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}


int main()
{
	Data a;
	a.i = 10;
	std::cout << deserialize(serialize(&a))->i << '\n';
}
