#include <iostream>
#include <string>

class Karen
{
public:
	enum Level : int8_t
	{
		NONE,
		DEBUG,
		INFO,
		WARNING,
		ERROR
	};

	void complain(std::string level);
	Level convert2lvl(std::string level);

private:
	using msg_func = void(Karen::*)();

	void debug() { std::cout << "[DEBUG]\n"; }
	void info() { std::cout << "[INFO]\n"; }
	void warning() { std::cout << "[WARNING]\n"; }
	void error() { std::cout << "[ERROR]\n"; }
};
