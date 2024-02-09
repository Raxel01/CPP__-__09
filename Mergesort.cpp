#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

int main ()
{
    std::vector<int> vectoro;

    vectoro.push_back(5);
    vectoro.push_back(0);
    vectoro.push_back(3);
    vectoro.push_back(2);
    vectoro.push_back(4);

    vectoro.insert(vectoro.begin() + 1, 9);

    std::vector<int>::iterator new_end = std::remove(vectoro.begin(), vectoro.end() - 2, 9);

    vectoro.erase(new_end, vectoro.end());
    
    std::vector<int>::iterator it = vectoro.begin();
    
    while (it != vectoro.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
    
    return 0;
}