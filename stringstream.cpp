#include <iostream>
#include <sstream>

int main (int ac, char **av)
{
    std::string name ("   abdelali  iat  talb         ");
    std::string namea ("      ");

    std::cout << trim(name) << std::endl;

    // std::string inbuut;
    // int a;
    // std::string line("Data     |      Value");

    // std::stringstream(line) >> inbuut;
    // std::cout << inbuut << std::endl;
    return (0);
}