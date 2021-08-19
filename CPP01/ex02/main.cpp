#include <iostream>
#include <string>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string* stringPTR = &string;
    std::string& stringREF = string;

    std::cout << "String memory address: " << &string << '\n';
    std::cout << "StringPTR memory address: " << stringPTR << '\n';
    std::cout << "StringREF memory address: " << &stringREF << '\n';
    std::cout << "StringPTR as string: " << *stringPTR << '\n';
    std::cout << "StringREF as string: " << stringREF << '\n';
}