#include <iostream>
#include <string>
#include <algorithm>
#include "Karen.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
		return 1;
	Karen k;
	switch (Karen::convert2lvl(argv[1]))
	{
		case Karen::NONE:
			break;
		case Karen::DEBUG:
			k.debug();
		case Karen::INFO:
			k.info();
		case Karen::WARNING:
			k.warning();
		case Karen::ERROR:
			k.error();
	}
}
