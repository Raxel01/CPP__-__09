/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:42:52 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/12 17:45:22 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

const char* NonValidinput::what() const throw()
{
    return ("Non Valid character in Your input");
}

const char* OnlyOnecase::what() const throw(){
std::cout << "                                               \\ / _   "  << std::endl;       
std::cout << "                                      ___,,,           "  << std::endl;               
std::cout << "                                      \\_[o o]          "  << std::endl;                       
std::cout << "     Errare humanum est!              C\\  _\\/          "  << std::endl;                       
std::cout << "             /                     _____),_/__         "  << std::endl;                   
std::cout << "        ________                  /     \\/   /         "  << std::endl;                   
std::cout << "      _|       .|                /      o   /          "  << std::endl;               
std::cout << "     | |       .|               /          /           "  << std::endl;               
std::cout << "      \\|       .|              /          /            "  << std::endl;               
std::cout << "       |________|             /_        \\/             "  << std::endl;               
std::cout << "       __|___|__             _//\\        \\             "  << std::endl;               
std::cout << " _____|_________|____       \\  \\ \\        \\            "  << std::endl;                   
std::cout << "                    _|       ///  \\        \\           "  << std::endl;                           
std::cout << "                   |               \\       /           "  << std::endl;                           
std::cout << "                   |               /      /            "  << std::endl;                           
std::cout << "                   |              /      /             "  << std::endl;                               
std::cout << " ________________  |             /__    /_             "  << std::endl;                               
std::cout << " b'ger        ...|_|.............. /______\\.......     "  << std::endl;                               
    return ("                  CCCCCan't Process This Numbers ...");
}

int           PmergeMe::GetLastValue(){
    return (_LastValue);
}  


PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(char *av) : Numbers(av), visited(0), _LastValue(-1){


}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& origine){
    *this = origine;
}

std::vector<int>    PmergeMe::GetVector(){
    return (Vector);
}

PmergeMe& PmergeMe::operator=(const PmergeMe& origine){
    
    if (this != &origine){
        Numbers     = origine.Numbers;
        Vector      = origine.Vector;
        vectorend   = origine.vectorend;
        vectorStart = origine.vectorStart;
    }
    return (*this);
}

void              PmergeMe::TimerVect(std::string STLtype){
    
    std::cout <<"Time to process a range of " << Vector.size() << " elements with std::[" << STLtype << "] : " <<
    std::fixed << std::setprecision(8) << (double)(vectorend - vectorStart) << " us"<<std::endl;
}

void    PmergeMe::InputState(std::string& holder)
{
    int i (-1);

    if (holder[++i] == '+'){
    i++;
        if (!holder[i])
            throw NonValidinput();
    }
    while (holder[i]){
        if (!isdigit(holder[i]))
            throw NonValidinput();
        i++;
    }
    elements = strtol(holder.c_str(), NULL, 0);
    if (elements > 2147483647)
        throw NonValidinput();
    Vector.push_back(static_cast<int>(elements));
}

void    PmergeMe::beforeSorting()
{
    std::vector<int>::iterator it = Vector.begin();
    
    std::cout << "Before : ";
    while(it != Vector.end()){
        std::cout << *it << " ";
        it++;
    }
    std::cout << ""<< std::endl;
    _VectorSize = Vector.size();
}

void    PmergeMe::ParsInput(){

    std::string holder;
    std::stringstream ss(Numbers);

    while (ss >> holder){
        InputState(holder);
        visited = 1;
    }
    if (!visited)
        throw NonValidinput();
    ss.clear();
    beforeSorting();
}



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

void    PmergeMe::insertion(std::vector<int>&elem, size_t begin, size_t end)
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
    /************************************Here**********/
    // _Mainchaine.insert(_Mainchaine.begin(), _Pendchaine.begin(), _Pendchaine.end());
    _Pendchaine.insert(_Pendchaine.end(), _Mainchaine.begin(), _Mainchaine.end());
    /******************************************************/
    // insertion(_Mainchaine, 0, _Mainchaine.size());
    insertion(_Pendchaine, 0, _Pendchaine.size());
    /*************************************************/
    Vector.clear();
    Vector.insert(Vector.begin(), _Pendchaine.begin(), _Pendchaine.end());
    if (_LastValue != -1)
        Vector.push_back(_LastValue);
    insertion(Vector, 0, Vector.size());
    _Mainchaine.clear();
    _Pendchaine.clear();
}

void    connector(PmergeMe& Sorted, MyDeque& dequeObject){
    dequeObject.setdeque(Sorted.GetVector());
    dequeObject.setLastValue(Sorted.GetLastValue());
    dequeObject._DequeSize = Sorted._VectorSize;
}

void    PmergeMe::PairSort(MyDeque& DequeObject)
{
    if (_VectorSize == 1)
        throw OnlyOnecase();
    if (_VectorSize % 2 != 0){
        _LastValue = Vector.at(_VectorSize - 1);
        _VectorSize--;
    }
    connector(*this, DequeObject);
    vectorStart = clock();
    for (size_t i = 0, j = 0; i < _VectorSize; i += 2){
        Paired.push_back(std::make_pair(Vector.at(i), Vector.at(i + 1)));
        if (Paired.at(j).first < Paired.at(j).second)
            std::swap(Paired.at(j).first, Paired.at(j).second);
        j++;
    }
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
