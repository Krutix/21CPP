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
