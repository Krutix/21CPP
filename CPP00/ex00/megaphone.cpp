#include <iostream>
#include <iomanip>

std::string toupper(char const *str)
{
    std::string upper(str);
    for (size_t i = 0; i < upper.size(); i++)
        upper[i] = std::toupper(upper[i]);
    return upper;
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    }
    else
    {
        for (size_t idx = 1; idx < static_cast<size_t>(argc); idx++)
            std::cout << toupper(argv[idx]);
        std::cout << '\n';
    }
}
