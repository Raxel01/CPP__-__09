/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:43:35 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/10 20:58:45 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>

#define SECOND secondSubVectLen;
void    PmergeMe::Sortsubs(size_t begin, int midle, size_t end){

    size_t firstSubVectLen  = (midle - begin + 1);
    size_t secondSubVectLen = end - midle;

    Pairtype    firstsubVector;
    Pairtype    secondsubVector;
    
    (void)(firstSubVectLen);
    (void)secondSubVectLen;
    (void)firstsubVector;
    (void)secondsubVector;
    
    // copy to first subvector
    for(size_t i = 0; i < firstSubVectLen; i++){
        firstsubVector.push_back(std::make_pair(Paired.at(begin + i).first, Paired.at(begin + i).second) );
    }
    for (size_t i = 0; i < secondSubVectLen; i++){
        secondsubVector.push_back(std::make_pair(Paired.at(midle + 1+ i).first, Paired.at(midle + 1 + i).second));
    }

    for(size_t i = 0, j = 0, k = begin; k <= end; k++){
        if (i < firstSubVectLen &&  (j >= secondSubVectLen || firstsubVector.at(i).first <= secondsubVector.at(i).first)){
            Paired[k] = firstsubVector[i];
            i++;
        }else {
            Paired[k] = secondsubVector[j];
            j++;
        }
        
    }
    
}

void    PmergeMe::mergeSort( size_t begin, size_t end )
{
    if (begin >= end)
        return ;
    int midle = begin + (end - begin) / 2;    
    mergeSort( begin, midle  );
    mergeSort( midle + 1, end);
    Sortsubs(begin, midle, end);
}

void    PmergeMe::PairSort()
{
    if (_VectorSize % 2 != 0){
        _LastValue = Vector.at(_VectorSize - 1);
        _VectorSize--;
    }
    
    int j (0);
    for (size_t i = 0; i < _VectorSize; i += 2){
        Paired.push_back(std::make_pair(Vector.at(i), Vector.at(i + 1)));
        if (Paired.at(j).first < Paired.at(j).second)
            std::swap(Paired.at(j).first, Paired.at(j).second);
        j++;
    }
     for(size_t i = 0; i < Paired.size(); i++){
        std::cout << Paired.at(i).first << " | "<<Paired.at(i).second << std::endl;
    }
    std::cout << "============================" << std::endl;
    mergeSort(0, Paired.size() - 1);
    
    for(size_t i = 0; i < Paired.size(); i++){
        std::cout << Paired.at(i).first << " | "<<Paired.at(i).second << std::endl;
    }
}

int main (int ac, char **av)
{
        switch (ac)
    {
    case 2:
        try{
            PmergeMe Sorted(av[1]);
            Sorted.ParsInput();
            Sorted.PairSort();
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
    return (0);
}
