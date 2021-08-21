#include <iostream>
#include <string>
#include <algorithm>
#include "Karen.hpp"

int main()
{
	Karen k;
	k.complain("DEBUG");
	k.complain("INFO");
	k.complain("WARNING");
	k.complain("ERROR");
	k.complain("SOME OTHER STAFF");
}
