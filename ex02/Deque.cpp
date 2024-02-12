/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deque.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:48:49 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/12 12:21:52 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

MyDeque::MyDeque(){}

MyDeque::~MyDeque(){}

MyDeque::MyDeque(const MyDeque& origine)
{
    *this = origine;
}

void    MyDeque::setdeque(std::vector<int> InitialVector)
{
    _Deque.insert(_Deque.begin(), InitialVector.begin(),
    InitialVector.end());
}

void    MyDeque::setLastValue(int setWith){
    _LastValue = setWith;
}

void    MyDeque::GetLastValue()
{
    std::cout << "Deque LastValue :==> " << _LastValue << std::endl;
}

MyDeque& MyDeque::operator=(const MyDeque& origine){
    
    if (this != &origine){
        _Deque      = origine._Deque;
        Dequeend   = origine.Dequeend;
        DequeStart = origine.DequeStart;
    }
    return (*this);
}

void              MyDeque::insertion(std::deque<int>& elem, size_t begin, size_t end)
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

void    MyDeque::Sortsubs(size_t begin, int midle, size_t end){

    size_t      firstSubVectLen  = (midle - begin + 1);
    size_t      secondSubVectLen = end - midle;
    Pairdeque    firstsubdeque;
    Pairdeque    secondsubdeque;

    for(size_t i = 0; i < firstSubVectLen; i++){
        firstsubdeque.push_back(std::make_pair(Paired.at(begin + i).first, Paired.at(begin + i).second) );
    }
    
    for (size_t i = 0; i < secondSubVectLen; i++){
        secondsubdeque.push_back(std::make_pair(Paired.at(midle + 1+ i).first, Paired.at(midle + 1 + i).second));
    }
    for(size_t i = 0, j = 0, k = begin; k <= end; k++){
        if (i < firstSubVectLen &&  (j >= secondSubVectLen || firstsubdeque.at(i).first <= secondsubdeque.at(j).first)){
            Paired[k] = firstsubdeque[i];
            i++;
        }
        else {
            Paired[k] = secondsubdeque[j];
            j++;
        }   
    }
}

void              MyDeque::TimerDeque(std::string STLtype){
    
    std::cout <<"Time to process a range of " << _Deque.size() << " elements with std::[" << STLtype << "] : " <<
    std::fixed << std::setprecision(8) << (double)(Dequeend - DequeStart) << " us"<<std::endl;
}

void        MyDeque::Main_PendChaine()
{
    for(size_t i = 0; i < Paired.size(); i++){
        _Mainchaine.push_back(Paired.at(i).first);
        _Pendchaine.push_back(Paired.at(i).second);
    }
    insertion(_Pendchaine, 0, _Pendchaine.size());
    insertion(_Mainchaine, 0, _Mainchaine.size());
    _Mainchaine.insert(_Mainchaine.begin(), _Pendchaine.begin(), _Pendchaine.end());
    insertion(_Mainchaine, 0, _Mainchaine.size());
    _Deque.clear();
    _Deque.insert(_Deque.begin(), _Mainchaine.begin(), _Mainchaine.end());
    if (_LastValue != -1)
        _Deque.push_back(_LastValue);
    insertion(_Deque, 0, _Deque.size());
    _Mainchaine.clear();
    _Pendchaine.clear();
}

void    MyDeque::mergeSort( size_t begin, size_t end )
{
    if (begin >= end)
        return ;
    int midle = begin + (end - begin) / 2;    

    mergeSort( begin, midle  );
    mergeSort( midle + 1, end);
    Sortsubs(begin, midle, end);
}

void    MyDeque::StartDequeProcess(){
    DequeStart = clock();
    for (size_t i = 0, j = 0; i < _DequeSize; i += 2){
        Paired.push_back(std::make_pair(_Deque.at(i), _Deque.at(i + 1)));
        if (Paired.at(j).first < Paired.at(j).second)
            std::swap(Paired.at(j).first, Paired.at(j).second);
        j++;
    }
    mergeSort(0, Paired.size() - 1);
    Main_PendChaine();
    Dequeend = clock();
    /*Will need it when defence ..*/
    // std::cout << "After  : ";
    // for (size_t i = 0; i < _Deque.size(); i++){
    //     std::cout << _Deque.at(i) << " " ;
    // }
    // std::cout << std::endl;
    TimerDeque("Deque");
}

void    MyDeque::Getdeque() 
{
    std::cout << "In" << std::endl;
    
    std::deque<int>::iterator it =  _Deque.begin();
    while(it != _Deque.end()){
        std::cout << *it << std::endl;
        it++;
    }
}