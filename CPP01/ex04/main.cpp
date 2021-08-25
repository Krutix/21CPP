#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

void usage()
{
	std::cout << "./replace input_file find replace\n";
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

	std::ofstream out_file(std::string(argv[1]).append(".REPLACE").c_str());
	if (!out_file.is_open())
	{
		std::cout << "Can't create output file\n";
		return 1;
	}

	std::string find(argv[2]);
	std::string replace(argv[3]);
	if (find.size() == 0 || replace.size() == 0)
	{
		std::cout << "Can't work with empty string\n";
		return 1;
	}

	for (std::string readbuf = ""; std::getline(in_file, readbuf); )
	{
		for (size_t findplace; (findplace = readbuf.find(find)) != std::string::npos; )
		{
			readbuf.erase(findplace, find.size());
			readbuf.insert(findplace, replace);
		}
		out_file << readbuf;
		if (!in_file.eof())
			out_file << std::endl;
	}
	in_file.close();
	out_file.close();
}
