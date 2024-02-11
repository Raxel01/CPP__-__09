/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:43:35 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/11 19:14:58 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


void    PmergeMe::Sortsubs(size_t begin, int midle, size_t end){

    size_t      firstSubVectLen  = (midle - begin + 1);
    size_t      secondSubVectLen = end - midle;
    Pairtype    firstsubVector;
    Pairtype    secondsubVector;

    for(size_t i = 0; i < firstSubVectLen; i++){
        firstsubVector.push_back(std::make_pair(Paired.at(begin + i).first, Paired.at(begin + i).second) );
    }
    
    for (size_t i = 0; i < secondSubVectLen; i++){
        secondsubVector.push_back(std::make_pair(Paired.at(midle + 1+ i).first, Paired.at(midle + 1 + i).second));
    }
    for(size_t i = 0, j = 0, k = begin; k <= end; k++){
        if (i < firstSubVectLen &&  (j >= secondSubVectLen || firstsubVector.at(i).first <= secondsubVector.at(j).first)){
            Paired[k] = firstsubVector[i];
            i++;
        }
        else {
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

template<typename T>
void    PmergeMe::insertion(T &elem, size_t begin, size_t end)
{
    size_t start = begin + 1;
    int j;
    int Value;
    
    while (start < end){
        j = start - 1;
        Value = elem[start];
        while (j >= 0 && Value <= elem[j]){
            std::swap(elem[j + 1], elem[j]);
            j--;  
        }
        start++;
    }
}

void PmergeMe::Main_PendChaine()
{
    for(size_t i = 0; i < Paired.size(); i++){
        _Mainchaine.push_back(Paired.at(i).first);
        _Pendchaine.push_back(Paired.at(i).second);
    }
    insertion(_Pendchaine, 0, _Pendchaine.size());
    insertion(_Mainchaine, 0, _Mainchaine.size());
    _Mainchaine.insert(_Mainchaine.begin(), _Pendchaine.begin(), _Pendchaine.end());
    insertion(_Mainchaine, 0, _Mainchaine.size());
    Vector.clear();
    Vector.insert(Vector.begin(), _Mainchaine.begin(), _Mainchaine.end());
    if (_LastValue != -1)
        Vector.push_back(_LastValue);
    insertion(Vector, 0, Vector.size());
    _Mainchaine.clear();
    _Pendchaine.clear();
}


void    PmergeMe::PairSort()
{
    if (_VectorSize % 2 != 0){
        _LastValue = Vector.at(_VectorSize - 1);
        _VectorSize--;
    }
    for (size_t i = 0, j = 0; i < _VectorSize; i += 2){
        Paired.push_back(std::make_pair(Vector.at(i), Vector.at(i + 1)));
        if (Paired.at(j).first < Paired.at(j).second)
            std::swap(Paired.at(j).first, Paired.at(j).second);
        j++;
    }
    vectorStart = clock();
    mergeSort(0, Paired.size() - 1);
    Main_PendChaine();
    vectorend = clock();
    std::cout << "After  : ";
    for (size_t i = 0; i < Vector.size(); i++){
        std::cout << Vector.at(i) << " " ;
    }
    std::cout << std::endl;
    TimerVect("vector");            
    
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
            
        }catch(std::exception& e){
            std::cout << e.what() << std::endl;
        }
        break;
    default:
        std::cout << "[ No    enough  Arguments  ]"<< std::endl;
        std::cout << "[ use  ./PmergMe  \"numbers\" ]"<< std::endl;
        break;
    }  
    return (0);
}
