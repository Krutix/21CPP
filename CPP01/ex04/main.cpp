#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <unistd.h>

void usage()
{
	std::cout << "./replace input_file find replace\n";
}

void	replace(std::string& fix_str, std::string const& from, std::string const& to)
{
	size_t findplace = 0;

	while ((findplace = fix_str.find(from, findplace)) != std::string::npos)
	{
		fix_str.erase(findplace, from.size());
		fix_str.insert(findplace, to);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		usage();
		return 1;
	}

	std::ifstream in_file(argv[1]);
	if (!in_file.is_open())
	{
		std::cout << "Can't open file\n";
		return 1; 
	}

	std::ofstream out_file(std::string(argv[1]).append(".REPLACE"));
	if (!out_file.is_open())
	{
		std::cout << "Can't create output file\n";
		return 1;
	}

	std::string from(argv[2]);
	std::string to(argv[3]);
	if (from.size() == 0 || to.size() == 0)
	{
		std::cout << "Can't work with empty string\n";
		return 1;
	}

	std::stringstream ss;
	ss << in_file.rdbuf();
	std::string fix_str(ss.str());
	replace(fix_str, from, to);
	out_file << fix_str;

	in_file.close();
	out_file.close();
}
