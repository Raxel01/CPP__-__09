/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:43:35 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/09 16:39:52 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>

// template<typename T>
// void    Mswap(T& a, T&b){
//     T tmp;
//     tmp = a;
//     a = b;
//     b = tmp;    
// }

// template <typename T>
// void    recurs_it(T &elem , size_t len = 9, size_t start = 0, size_t end = 1)
// {
//     if (end >= len)
//         return ;
//     if (elem[start] > elem[end])
//         std::swap(elem[start],  elem[end]);
//     recurs_it(elem, len, start+2, end+2);
// }

// template <typename T>
// void  findSmall(T& vect)
// {
//     typedef typename T::iterator iter;
    
//     iter beg = vect.begin();
//     iter min = vect.begin();
//     while (beg != vect.end() - 1){
//         if (*beg < *min)
//             min = beg;
//         beg += 2;
//     }
//     int tmp1 = *min;
//     int tmp2 = *(min+1);
//     vect.erase(min, min + 2);
//     vect.insert(vect.begin(), tmp2);    
//     vect.insert(vect.begin(), tmp1);
// }

int main (int ac, char **av)
{
        switch (ac)
    {
    case 2:
        try{
            PmergeMe Sorted(av[1]);
            Sorted.ParsInput();
            
            // Sorted.Timer("vector", 0.00033);            
            // Sorted.Timer("deque", 0.00039);            
        }catch(std::exception& e){
            std::cout << e.what() << std::endl;
        }
        break;
    default:
        std::cout << "[ No     nough  Arguments  ]"<< std::endl;
        std::cout << "[ use  ./PmergMe  \"numbers\" ]"<< std::endl;
        break;
    }
    // (void)ac;
    // (void)av; // 0=1, 1=2
    // std::vector<int> vectoro;
    // vectoro.push_back(9);
    // vectoro.push_back(8);
    // vectoro.push_back(6);
    // vectoro.push_back(0);
    // vectoro.push_back(3);
    // vectoro.push_back(2);
    // vectoro.push_back(7);
    // vectoro.push_back(5);
    // vectoro.push_back(1);
    
    // clock_t start_time = clock();
    // recurs_it(vectoro);
    // // findSmall(vectoro);
    // clock_t end_time = clock();
    // std::cout << "Time : " <<std::fixed << std::setprecision(6) <<double(end_time - start_time) / CLOCKS_PER_SEC << std::endl;
    // std::vector<int>::iterator beg = vectoro.begin();
    
    // while (beg != vectoro.end()){
    //     std::cout << *beg << std::endl;
    //     beg++;
    // }    
    return (0);
}
