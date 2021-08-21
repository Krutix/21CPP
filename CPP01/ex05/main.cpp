#include <iostream>
#include <string>
#include <algorithm>

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

private:
	using msg_func = void(Karen::*)();

	void debug() { std::cout << "[DEBUG]\n"; }
	void info() { std::cout << "[INFO]\n"; }
	void warning() { std::cout << "[WARNING]\n"; }
	void error() { std::cout << "[ERROR]\n"; }
};

void Karen::complain(std::string level)
{
	msg_func mf[] =
	{
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error
	};
	int8_t	func_idx =
		((level == "DEBUG") * (uint8_t)Level::DEBUG) +
		((level == "INFO") * (uint8_t)Level::INFO) +
		((level == "WARNING") * (uint8_t)Level::WARNING) +
		((level == "ERROR") * (uint8_t)Level::ERROR) - 1;

	if (func_idx == -1)
		return ;

	(this->*mf[func_idx])();
}


int main()
{
	Karen k;
	k.complain("DEBUG");
	k.complain("INFO");
	k.complain("WARNING");
	k.complain("ERROR");
	k.complain("SOME OTHER STAFF");
}
