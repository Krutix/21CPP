#include <iostream>
#include <string>

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"
#define WRAP_COLOR(color, test) color test COLOR_RESET

class Karen
{
public:
	enum Level
	{
		NONE,
		DEBUG,
		INFO,
		WARNING,
		ERROR
	};

	void complain(std::string level);
	static Level convert2lvl(std::string level);

	void debug() { std::cout << WRAP_COLOR(COLOR_BLUE, "[DEBUG]\n"); }
	void info() { std::cout << WRAP_COLOR(COLOR_GREEN, "[INFO]\n"); }
	void warning() { std::cout << WRAP_COLOR(COLOR_YELLOW, "[WARNING]\n"); }
	void error() { std::cout << WRAP_COLOR(COLOR_RED, "[ERROR]\n"); }

private:
	typedef void(Karen::*msg_func)();
};
