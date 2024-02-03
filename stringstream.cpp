#include <iostream>
#include <sstream>

int main (int ac, char **av)
{
    std::string inbuut;
    int a;
    std::string line("Data     |      Value");

    std::stringstream(line) >> inbuut;
    std::cout << inbuut << std::endl;
    return (0);
}