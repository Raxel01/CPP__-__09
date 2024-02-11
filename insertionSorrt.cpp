#include <iomanip>
#include <iostream>
#include <vector>

int main ()
{
    std::vector<int> Myvect;
    Myvect.push_back( 5);
    Myvect.push_back( 3);
    Myvect.push_back( 0);
    Myvect.push_back( 4);
    Myvect.push_back( 1);
    Myvect.push_back( 3);
    Myvect.push_back( 1);
    Myvect.push_back( -2);
    Myvect.push_back( 5);


    insertion(Myvect,0, Myvect.size());

    int i = -1;
    while ( ++i < Myvect.size()){
        std::cout << Myvect[i] << std::endl;
    }
    return (0);
}