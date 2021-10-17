#include "Karen.hpp"

Karen::Level Karen::convert2lvl(std::string level)
{
	int	idx =
		((level == "DEBUG") * (int)DEBUG) +
		((level == "INFO") * (int)INFO) +
		((level == "WARNING") * (int)WARNING) +
		((level == "ERROR") * (int)ERROR);
	return static_cast<Level>(idx);
}

void Karen::debug() { std::cout << WRAP_COLOR(COLOR_BLUE, "[DEBUG]\n"); }
void Karen::info() { std::cout << WRAP_COLOR(COLOR_GREEN, "[INFO]\n"); }
void Karen::warning() { std::cout << WRAP_COLOR(COLOR_YELLOW, "[WARNING]\n"); }
void Karen::error() { std::cout << WRAP_COLOR(COLOR_RED, "[ERROR]\n"); }

void Karen::complain(std::string level)
{
	msg_func mf[] =
	{
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error
	};

	Level lvl = Karen::convert2lvl(level);

	if (lvl == NONE)
		return ;

	(this->*mf[static_cast<int>(lvl) - 1])();
}
