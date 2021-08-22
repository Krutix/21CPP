#include "Karen.hpp"

Karen::Level Karen::convert2lvl(std::string level)
{
	int8_t	func_idx =
		((level == "DEBUG") * (uint8_t)Level::DEBUG) +
		((level == "INFO") * (uint8_t)Level::INFO) +
		((level == "WARNING") * (uint8_t)Level::WARNING) +
		((level == "ERROR") * (uint8_t)Level::ERROR);
	return static_cast<Level>(func_idx);
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

	if (lvl == Level::NONE)
		return ;

	(this->*mf[static_cast<int8_t>(lvl) - 1])();
}
