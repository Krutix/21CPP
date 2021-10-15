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
    if (!std::cout)
        return 1;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    }
    else
    {
        for (int idx = 1; idx < argc; idx++)
            std::cout << toupper(argv[idx]);
        std::cout << std::endl;
    }
}
