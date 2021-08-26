#include <string>
#include <iostream>
#include <limits>

class Converter
{
public:
	Converter(std::string const& str)
		: str(str) {}

	operator float()
	{
		return 0;
	}

	operator double()
	{
		return 0;
	}

	operator char ()
	{
		return 0;
	}

	operator int ()
	{
		return 0;
	}
private:
	std::string str;
};

int main()
{
	std::cout << static_cast<int>(Converter("-42")) << '\n';
}
