#include <iomanip>
#include <iostream>
#include <vector>

template<typename T>
void    insertion(T &elem, size_t begin, size_t end)
{
    size_t start = begin + 1;
    int j;
    int Value;
    
    while (start < end){
        j = start - 1;
        Value = elem[start];
        while (j >= 0 && Value <= elem[j]){
            std::cout << "Value : " << Value << " | j+1 : " << elem.at(j + 1) << " | j :" << elem.at(j) << std::endl;
            std::swap(elem[j + 1], elem[j]);
            j--;  
        }
        start++;
    }
}

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