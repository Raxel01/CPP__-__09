#include <iostream>
#include <sstream>
#include <unistd.h>


// void    CleanString(std::string& line)
// {
//     int     i = -1;
//     int     flg (0);
// 	std::stringstream ss;
//     while (line[++i])
// 	{
// 		if (line[i] == ' ' || line[i] == '\t')
// 			flg = 1;
// 		if (!(line[i] == ' ' || line[i] == '\t'))
// 		{
// 			if (flg)
// 				ss << " ";
// 			flg = 0;
// 			ss << line[i];
// 			}
// 		}
//     line = ss.str();
// }

int main (int ac, char **av)
{
    std::string input("abdelali  ait talb");


    // CleanString(input);
    // std::cout << input << std::endl;
    // std::string name ("   abdelali  iat  talb         ");
    // std::string namea ("      ");

    // // std::cout << trim(name) << std::endl;

    // // std::string inbuut;
    // // int a;
    // // std::string line("Data     |      Value");

    // // std::stringstream(line) >> inbuut;
    // // std::cout << inbuut << std::endl;
    // std::string mystr("1 ait talb is ok no ok");

    std::string lol;
    // int wa7d;
    
    std::stringstream ss (mystr);
    int i = 0;
    while (ss >> lol)
    {
        i++;
        if (i > 3)
            std::cout << " Not Valide "<< std::endl;
        std::cout << lol << std::endl;
    }
    // // if ()

    return (0);
}