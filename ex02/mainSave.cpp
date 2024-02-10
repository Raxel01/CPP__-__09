#include <iostream>
#include <vector>
// #include <>

int main ()
{
    std::vector<int> myvect;

    for (int i = 0; i < 11; i++){
        myvect.push_back(i);
    }

    std::vector<std::pair<int,int> > pairedVectore;
    size_t len = myvect.size();
    if (len % 2 != 0)
        len--;
    int i (0);

    while (i < len){

        pairedVectore.push_back(std::make_pair(myvect.at(i), myvect.at(i + 1)));
        i = i+2;
    }

    for(int i = 0; i < pairedVectore.size(); i++){
            std::cout << pairedVectore.at(i).first << pairedVectore.at(i).second << std::endl;
            std::cout << "======="<< std::endl;
    }
    
    return (0);
}