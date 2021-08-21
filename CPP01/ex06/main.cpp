#include <iostream>
#include <string>
#include <algorithm>
#include "Karen.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
		return 1;
	Karen k;
	switch (k.convert2lvl(argv[1]))
	{
		case Karen::NONE:
		case Karen::DEBUG:
		case Karen::INFO:
		case Karen::WARNING:
		case Karen::ERROR:
		default:
	}
}
